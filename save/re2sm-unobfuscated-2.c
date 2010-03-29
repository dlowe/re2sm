#include <unistd.h>
#include <stdlib.h>

/* OBFUSCATIONS */
/* XX: only recursive functions and functions called from more than 1 place */
/* XX: replace all loops with tail recursive functions */
/* XX: reverse indentation? */
/* XX: use bitmaps for bracket expressions */
/* XX: rewrite all while loops which walk a poot using a callback */

typedef void *poot[2];

unsigned int str_len(char *s)
{
    char *t = s;
    for (;;++t) if (!*t) return t - s;
}

void str_cpy(char *s, char *t) {
    for (;;++s,++t) { if (!(*s = *t)) break; }
}

int parse_re(char *s, poot **o);

void out_destroy(poot **o) {
    poot *current = *o;
    while (current) {
        *o = ((*current)[1]);
        free((*current)[0]);
        (*current)[0] = 0;
        free(current);
        current = *o;
    }
}

poot *out_new(unsigned int s) {
    poot *o = malloc(sizeof(poot));
    (*o)[0] = malloc(s);
    (*o)[1] = 0;
    return o;
}

void out_append(poot **o, poot *n) {
    poot *c = *o;

    if (! c) *o = n;
    else {
        while ((*c)[1]) c = (*c)[1];
        (*c)[1] = n;
    }
}

void out_char(poot **o, char c) {
    poot *new = out_new(2);
    ((char *)(*new)[0])[0] = c;
    ((char *)(*new)[0])[1] = 0;
    out_append(o, new);
}

void out_string(poot **o, char *s) {
    poot *new = out_new(str_len(s) + 1);
    str_cpy(((*new)[0]), s);
    out_append(o, new);
}

void out_strings(poot **o, char *s, char *t) {
    poot *new = out_new(str_len(s) + str_len(t) + 1);
    str_cpy(((*new)[0]), s);
    str_cpy((char *)((*new)[0]) + str_len(s), t);
    out_append(o, new);
}

void out_move(poot **to, poot **from) {
    poot *current;

    out_destroy(to);

    current = *from;
    while (current) {
        out_string(to, ((*current)[0]));
        current = (*current)[1];
    }

    out_destroy(from);
}

void out_mutate(char *base, poot *o, poot **p) {
    while (o) {
        out_strings(p, base, (*o)[0]);
        o = (*o)[1];
    }
}

poot *out_numbered(poot *o, unsigned int n) {
    unsigned int this_index;
    poot         *current;
    poot         *final_out = 0;
    poot         *build_out = 0;
    poot         *exist_out = 0;

    if (! n) {
        out_char(&final_out, 0);
    }

    for (this_index = 1; this_index <= n; ++this_index) {
        if (this_index == 1) {
            out_mutate("", o, (this_index == n) ? &final_out : &build_out);
        } else {
            current = exist_out;
            while (current) {
                out_mutate((*current)[0], o,
                           (this_index == n) ? &final_out : &build_out);
                current = (*current)[1];
            }
        }
        out_move(&exist_out, &build_out);
    }

    out_destroy(&exist_out);
    return final_out;
}

void out_multiplex(poot **o, unsigned int min, unsigned int max) {
    unsigned int this_count;
    poot         *new      = 0;
    poot         *this_out = 0;
    poot         *current  = 0;

    for (this_count = min; this_count <= max; ++this_count) {
        current = this_out = out_numbered(*o, this_count);
        while (current) {
            out_string(&new, (*current)[0]);
            current = (*current)[1];
        }
        out_destroy(&this_out);
    }

    out_destroy(o);
    *o = new;
}

poot *out_merge(poot *t) {
    poot *thing_current = t;
    poot *exist_current = 0;
    poot *final_out     = 0;
    poot *exist_out     = 0;
    poot *build_out     = 0;

    while (thing_current) {
        if (thing_current == t) {
            out_mutate("", (*thing_current)[0],
                       (! (*thing_current)[1]) ? &final_out : &build_out);
        } else {
            exist_current = exist_out;
            while (exist_current) {
                out_mutate((*exist_current)[0], (*thing_current)[0],
                           (! (*thing_current)[1]) ? &final_out : &build_out);
                exist_current = (*exist_current)[1];
            }
        }

        thing_current = (*thing_current)[1];
        out_move(&exist_out, &build_out);
    }
    out_destroy(&exist_out);

    return final_out;
}

void syn_die(char *out) {
    write(1, "syntax error: ", 14);
    write(1, out, str_len(out));
    write(1, "\n", 1);
    exit(1);
}

unsigned int scan_int(char *s, unsigned int *n) {
    int b, c = 0;
    *n = 0;

    while (s[c] && ((b = s[c++] - '0') < 10) && (b >= 0))
        *n = *n * 10 + b;
    return c - 1;
}

int parse_bracket(char *s, poot **o) {
    int c = 0;
    int inverted = 0;
    int i;
    char seen[127];

    if (s[c] == '^') { ++c; inverted = 1; }
    for (i = 1; i < 127; ++i) { seen[i] = inverted; }
    if (s[c] == ']') { seen[']'] = ! inverted; ++c; }
    while (s[c] && s[c] != ']') {
        seen[(int)s[c]] = ! inverted;
        ++c;
    }
    for (i = 0; i < 127; ++i) {
        if (seen[i]) out_char(o, i);
    }
    return c;
}

int parse_bounds(char *s, poot **o) {
    int n, num = 0;
    unsigned int n1, n2;

    if (! *s) return 0;

    switch (*s) {
        case '?':
            out_multiplex(o, 0, 1);
            return 1;
        case '{':
            break;
        default:
            return 0;
    };

    num += 1;
    s += 1;

    n = scan_int(s, &n1);
    if (n) {
        if (n1 > 255) syn_die("bad {}: i is too big");
        num += n;
        s += n;
        switch (*s) {
            case ',':
                num += 1;
                s += 1;
                n = scan_int(s, &n2);
                if (n) {
                    if (n2 > 255) syn_die("bad {}: j is too big");
                    num += n;
                    s += n;
                    if (*s == '}') {
                        num += 1;
                        s += 1;
                        if (n2 < n1) syn_die("bad {}: j smaller than i");
                        out_multiplex(o, n1, n2);
                        return num;
                    } else
                        syn_die("bad {}: no closing brace found");
                } else
                    syn_die("bad {}: no j value found");
            case '}':
                num += 1;
                s += 1;
                out_multiplex(o, n1, n1);
                return num;
            default:
                syn_die("bad {}: expected comma or closing brace");
        };
    } else
        syn_die("bad {}: no i value found");

    return 0;
}

int parse_atom(char *s, poot **o) {
    char i;

    if (! *s) return 0;

    switch (*s) {
        case '(':
            if ((*(s+1)) && (*(s+1) == ')')) {
                out_char(o, 0);
                return 2;
            } else {
                int n;

                n = parse_re(s + 1, o);
                if ((! n) || (*(s + n + 1) != ')'))
                    syn_die("sub-expression trouble");

                return n + 2;
            }
        case '[': {
            int n;

            n = parse_bracket(s + 1, o);
            if ((! n) || (*(s + n + 1) != ']'))
                syn_die("bracket expression trouble");

            return n + 2;
        } case '\\':
            if (! *(s+1))
                syn_die("regexp cannot end in \\");
            out_char(o, *(s+1));
            return 2;
        case '.':
            for (i = 1; i <= 126; ++i) {
                if ((i == 10) || (i == 13)) continue;
                out_char(o, i);
            }
            return 1;
        default:
            if ((*s == '.') || (*s == '[') || (*s == '(') || (*s == ')')
             || (*s == '|') || (*s == '?') || (*s == '{') || (*s == '\\'))
                return 0;
            out_char(o, *s);
            return 1;
    };
    return 0;
}

int parse_piece(char *s, poot **o) {
    int n, num = 0;

    if (! *s) return 0;

    if ((n = parse_atom(s, o))) {
        s += n;
        num += n;
        n = parse_bounds(s, o);
        s += n;
        num += n;
    } else {
        return 0;
    }

    return num;
}

int parse_branch(char *s, poot **o) {
    int n, num = 0;
    poot *output = 0;
    poot *pieces = 0;
    poot *current = 0;

    if (! *s) return 0;

    while ((n = parse_piece(s, &output))) {
        poot *current = pieces;
        poot *new     = malloc(sizeof(poot));

        (*new)[0] = output;
        (*new)[1] = 0;

        if (! current) {
            pieces = new;
        } else {
            while ((*current)[1]) current = (*current)[1];
            (*current)[1] = new;
        }
        output = 0;
        s += n;
        num += n;
    }
    *o = out_merge(pieces);

    current = pieces;
    while (current) {
        pieces = (*current)[1];
        out_destroy((poot **)&((*current)[0]));
        free(current);
        current = pieces;
    }

    if (*s == '|') num += 1;
    if ((! num) && (*s != ')'))
        syn_die("branch problem");

    return num;
}

int parse_re(char *s, poot **o) {
    int n, num = 0;
    poot *output = 0;

    if ((! s) || (! *s))
        syn_die("input string is empty");

    while ((n = parse_branch(s, &output))) {
        out_append(o, output);
        s += n;
        num += n;
    }

    return num;
}

int main(int argc, char **argv) {
    poot *output = 0;
    poot *ot;

    parse_re(argv[1], &output);

    ot = output;

    write(1, "S88\n", 4);
    while (ot) {
        write(1, "R", 1);
        write(1, (*ot)[0], str_len((*ot)[0]));
        write(1, "\t\t$@ <MATCH>\n", 13);
        ot = (*ot)[1];
    }
    write(1, "R$*\t\t$@ <NOMATCH>\n", 18);

    out_destroy(&output);

    exit(0);
}
