#include <unistd.h>
#include <stdlib.h>

/* OBFUSCATIONS */
/* XX: only recursive functions and functions called from more than 1 place */
/* XX: replace all loops with tail recursive functions */
/* XX: reverse indentation? */
/* XX: use bitmaps for bracket expressions */

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

void poot_walk(poot *c, poot **e1, poot **e2, poot **e3,
               void (*callback)(poot *, poot **, poot **, poot **)) {
    poot *next;
    if (! c) return;
    next = (*c)[1];
    callback(c, e1, e2, e3);
    poot_walk(next, e1, e2, e3, callback);
}

void out_destroy_callback(poot *current, poot **o, poot **i, poot **j) {
    *o = ((*current)[1]);
    free((*current)[0]);
    (*current)[0] = 0;
    free(current);
}

void out_destroy(poot **o) {
    poot_walk(*o, o, 0, 0, out_destroy_callback);
}

poot *out_new(unsigned int s) {
    poot *o = malloc(sizeof(poot));
    (*o)[0] = malloc(s);
    (*o)[1] = 0;
    return o;
}

void out_append_callback(poot *current, poot **new, poot **i, poot **j) {
    if (! (*current)[1]) (*current)[1] = *new;
}

void out_append(poot **o, poot *n) {
    poot *c = *o;

    if (! c) *o = n;
    else poot_walk(c, &n, 0, 0, out_append_callback);
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

void out_move_callback(poot *current, poot **to, poot **i, poot **j) {
    out_string(to, (*current)[0]);
}

void out_move(poot **to, poot **from) {
    out_destroy(to);
    poot_walk(*from, to, 0, 0, out_move_callback);
    out_destroy(from);
}

void out_mutate_callback(poot *current, poot **p, poot **base, poot **i) {
    out_strings(p, (char *)(*base), (*current)[0]);
}

void out_mutate(char *base, poot *o, poot **p) {
    poot_walk(o, p, (poot **)&base, 0, out_mutate_callback);
}

void out_numbered_callback(poot *current, poot **o, poot **p, poot **i) {
    out_mutate((*current)[0], *o, p);
}

poot *out_numbered(poot *o, unsigned int n) {
    unsigned int this_index;
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
            poot_walk(exist_out, &o,
                      (this_index == n) ? &final_out : &build_out, 0,
                      out_numbered_callback);
        }
        out_move(&exist_out, &build_out);
    }

    out_destroy(&exist_out);
    return final_out;
}

void out_multiplex_callback(poot *current, poot **new, poot **i, poot **j) {
    out_string(new, (*current)[0]);
}

void out_multiplex(poot **o, unsigned int min, unsigned int max) {
    unsigned int this_count;
    poot         *new      = 0;
    poot         *this_out = 0;

    for (this_count = min; this_count <= max; ++this_count) {
        this_out = out_numbered(*o, this_count);
        poot_walk(this_out, &new, 0, 0, out_multiplex_callback);
        out_destroy(&this_out);
    }

    out_destroy(o);
    *o = new;
}

void out_merge_callback_callback(poot *exist_current, poot **final_out,
                                 poot **build_out, poot **thing_current) {
    out_mutate((*exist_current)[0], (**thing_current)[0],
               (! (**thing_current)[1]) ? final_out : build_out);
}

int first;
void out_merge_callback(poot *thing_current, poot **final_out,
                        poot **build_out, poot **exist_out) {
    if (first) {
        out_mutate("", (*thing_current)[0],
                   (! (*thing_current)[1]) ? final_out : build_out);
    } else {
        poot_walk(*exist_out, final_out, build_out, &thing_current,
                  out_merge_callback_callback);
    }
    first = 0;
    out_move(exist_out, build_out);
}

poot *out_merge(poot *t) {
    poot *final_out     = 0;
    poot *exist_out     = 0;
    poot *build_out     = 0;

    first = 1;
    poot_walk(t, &final_out, &build_out, &exist_out, out_merge_callback);
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

void parse_branch_callback(poot *current, poot **pieces, poot **i, poot **j) {
    *pieces = (*current)[1];
    out_destroy((poot **)(&((*current)[0])));
    free(current);
}

int parse_branch(char *s, poot **o) {
    int n, num = 0;
    poot *output = 0;
    poot *pieces = 0;

    if (! *s) return 0;

    while ((n = parse_piece(s, &output))) {
        poot *new = malloc(sizeof(poot));
        (*new)[0] = output;
        (*new)[1] = 0;

        out_append(&pieces, new);

        output = 0;
        s += n;
        num += n;
    }
    *o = out_merge(pieces);

    poot_walk(pieces, &pieces, 0, 0, parse_branch_callback);

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

void main_callback(poot *ot, poot **i, poot **j, poot **k) {
    write(1, "R", 1);
    write(1, (*ot)[0], str_len((*ot)[0]));
    write(1, "\t\t$@ <MATCH>\n", 13);
}

int main(int argc, char **argv) {
    poot *output = 0;
    poot *ot;

    parse_re(argv[1], &output);

    ot = output;

    write(1, "S88\n", 4);
    poot_walk(output, 0, 0, 0, main_callback);
    write(1, "R$*\t\t$@ <NOMATCH>\n", 18);

    out_destroy(&output);

    exit(0);
}
