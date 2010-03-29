#include <unistd.h>
#include <stdlib.h>

/* OBFUSCATIONS */
/* XX: THING and OUTPUT can both be replaced with void *foo[2] variables ;) */
/* XX: only recursive functions and functions called from more than 1 place */
/* XX: replace all loops with tail recursive functions */
/* XX: reverse indentation? */
/* XX: use bitmaps for bracket expressions */

typedef struct OUTPUT out_list;
typedef struct THING  thing;

struct THING {
    out_list *output;
    thing    *next;
};

struct OUTPUT {
    char     *output;
    out_list *next;
};

unsigned int str_len(char *s)
{
    char *t = s;
    for (;;++t) if (!*t) return t - s;
}

void str_cpy(char *s, char *t) {
    for (;;++s,++t) { if (!(*s = *t)) break; }
}

int parse_re(char *s, out_list **o);

void out_destroy(out_list **o) {
    out_list *current = *o;
    while (current) {
        *o = current->next;
        free(current->output);
        current->output = 0;
        free(current);
        current = *o;
    }
}

out_list *out_new(unsigned int s) {
    out_list *o = (out_list *)malloc(sizeof(out_list));
    o->output   = (char *)malloc(s);
    o->next     = NULL;
    return o;
}

void out_append(out_list **o, out_list *n) {
    out_list *c = *o;

    if (! c) *o = n;
    else {
        while (c->next) c = c->next;
        c->next = n;
    }
}

void out_char(out_list **o, char c) {
    out_list *new  = out_new(2);
    new->output[0] = c;
    new->output[1] = 0;
    out_append(o, new);
}

void out_string(out_list **o, char *s) {
    out_list *new = out_new(str_len(s) + 1);
    str_cpy(new->output, s);
    out_append(o, new);
}

void out_strings(out_list **o, char *s, char *t) {
    out_list *new = out_new(str_len(s) + str_len(t) + 1);
    str_cpy(new->output, s);
    str_cpy(new->output + str_len(s), t);
    out_append(o, new);
}

void out_move(out_list **to, out_list **from) {
    out_list *current;

    out_destroy(to);

    current = *from; 
    while (current) {
        out_string(to, current->output);
        current = current->next;
    }

    out_destroy(from);
}

void out_mutate(char *base, out_list *o, out_list **p) {
    while (o) {
        out_strings(p, base, o->output);
        o = o->next;
    }
}

out_list *out_numbered(out_list *o, unsigned int n) {
    unsigned int this_index;
    out_list     *current;
    out_list     *final_out = NULL;
    out_list     *build_out = NULL;
    out_list     *exist_out = NULL;

    if (!n) {
        out_char(&final_out, 0);
    }

    for (this_index = 1; this_index <= n; ++this_index) {
        if (this_index == 1) {
            out_mutate("", o, (this_index == n) ? &final_out : &build_out);
        } else {
            current = exist_out;
            while (current) {
                out_mutate(current->output, o,
                           (this_index == n) ? &final_out : &build_out);
                current = current->next;
            }
        }
        out_move(&exist_out, &build_out);
    }

    out_destroy(&exist_out);
    return final_out;
}

void out_multiplex(out_list **o, unsigned int min, unsigned int max) {
    unsigned int this_count;
    out_list     *new      = NULL;
    out_list     *this_out = NULL;
    out_list     *current  = NULL;

    for (this_count = min; this_count <= max; ++this_count) {
        current = this_out = out_numbered(*o, this_count);
        while (current) {
            out_string(&new, current->output);
            current = current->next;
        }
        out_destroy(&this_out);
    }

    out_destroy(o);
    *o = new;
}

out_list *out_merge(thing *t) {
    thing    *thing_current = t;
    out_list *exist_current = NULL;
    out_list *final_out     = NULL;
    out_list *exist_out     = NULL;
    out_list *build_out     = NULL;

    while (thing_current) {
        if (thing_current == t) {
            out_mutate("", thing_current->output,
                      (thing_current->next == NULL) ? &final_out : &build_out);
        } else {
            exist_current = exist_out;
            while (exist_current) {
                out_mutate(exist_current->output, thing_current->output,
                      (thing_current->next == NULL) ? &final_out : &build_out);
                exist_current = exist_current->next;
            }
        }
        thing_current = thing_current->next;

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

int parse_bracket(char *s, out_list **o) {
    int c        = 0;
    int inverted = 0;
    int i;
    char seen[127];

    if (s[c] == '^') { ++c; inverted = 1; }
    for (i = 1; i < 127; ++i) { seen[i] = inverted; }
    if (s[c] == ']') { seen[']'] = ! inverted; ++c; }
    while (s[c] && s[c] != ']') {
        seen[(int)s[c]] = (! inverted);
        ++c;
    }
    for (i = 0; i < 127; ++i) {
        if (seen[i]) out_char(o, i);
    }
    return c;
}

int parse_bounds(char *s, out_list **o) {
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

int parse_atom(char *s, out_list **o) {
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

int parse_piece(char *s, out_list **o) {
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

int parse_branch(char *s, out_list **o) {
    int n, num = 0;
    out_list *output = NULL;
    thing *pieces = NULL;
    thing *current = NULL;

    if (! *s) return 0;

    while ((n = parse_piece(s, &output))) {
        thing *current = pieces;
        thing *new     = (thing *)malloc(sizeof(thing));

        new->output = output;
        new->next   = NULL;

        if (! current) {
            pieces = new;
        } else {
            while (current->next) current = current->next;
            current->next = new;
        }
        output = NULL;
        s += n;
        num += n;
    }
    *o = out_merge(pieces);

    current = pieces;
    while (current) {
        pieces = current->next;
        out_destroy(&(current->output));
        free(current);
        current = pieces;
    }

    if (*s == '|') num += 1;
    if ((! num) && (*s != ')'))
        syn_die("branch problem");

    return num;
}

int parse_re(char *s, out_list **o) {
    int n, num = 0;
    out_list *output = NULL;

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
    out_list *output = NULL;
    out_list *ot;

    parse_re(argv[1], &output);

    ot = output;

    write(1, "S88\n", 4);
    while (ot) {
        write(1, "R", 1);
        write(1, ot->output, str_len(ot->output));
        write(1, "\t\t$@ <MATCH>\n", 13);
        ot = ot->next;
    }
    write(1, "R$*\t\t$@ <NOMATCH>\n", 18);

    out_destroy(&output);

    exit(0);
}
