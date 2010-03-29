#include <unistd.h>
#include <stdlib.h>

/* XX: use bitmaps for bracket expressions */
/* XX: rename p to _, p* to __, p** to ___ */

typedef void *p[2];

int str_len(char *a, char *b) {
    if (! *b) return b - a;
    else      return str_len(a, ++b);
}

void str_cpy(char *a, char *b) {
    if ((*a = *b)) str_cpy(++a, ++b);
}

void walk(p *a, p **b, p **c, p **d, void (*e)(p *, p **, p **, p **)) {
    p *f;
    if (! a) return;
    f = (*a)[1];
    e(a, b, c, d);
    walk(f, b, c, d, e);
}

void out_destroy_callback(p *a, p **b, p **c, p **d) {
    *b = (*a)[1];
    free((*a)[0]);
    (*a)[0] = 0;
    free(a);
}

void out_destroy(p **a) {
    walk(*a, a, 0, 0, out_destroy_callback);
}

p *out_new(int a) {
    p *b = malloc(sizeof(p));
    (*b)[0] = malloc(a);
    (*b)[1] = 0;
    return b;
}

void out_append_callback(p *a, p **b, p **c, p **d) {
    if (! (*a)[1]) (*a)[1] = *b;
}

void out_append(p **a, p *b) {
    p *c = *a;

    if (! c) *a = b;
    else walk(c, &b, 0, 0, out_append_callback);
}

void out_char(p **a, char b) {
    p *c = out_new(2);
    ((char *)(*c)[0])[0] = b;
    ((char *)(*c)[0])[1] = 0;
    out_append(a, c);
}

void out_string(p **a, char *b) {
    p *c = out_new(str_len(b,b) + 1);
    str_cpy(((*c)[0]), b);
    out_append(a, c);
}

void out_strings(p **a, char *b, char *c) {
    p *d = out_new(str_len(b,b) + str_len(c,c) + 1);
    str_cpy(((*d)[0]), b);
    str_cpy((char *)((*d)[0]) + str_len(b,b), c);
    out_append(a, d);
}

void out_move_callback(p *a, p **b, p **c, p **d) {
    out_string(b, (*a)[0]);
}

void out_move(p **a, p **b) {
    out_destroy(a);
    walk(*b, a, 0, 0, out_move_callback);
    out_destroy(b);
}

void out_mutate_callback(p *a, p **b, p **c, p **d) {
    out_strings(b, (char *)(*c), (*a)[0]);
}

void out_mutate(char *a, p *b, p **c) {
    walk(b, c, (p **)&a, 0, out_mutate_callback);
}

void out_numbered_callback(p *a, p **b, p **c, p **d) {
    out_mutate((*a)[0], *b, c);
}

void out_numbered_recurse(int a, int b, p **c, p **d, p **e, p **f) {
    if (a > b) return;
    if (a == 1)
        out_mutate("", *c, (a == b) ? d : e);
    else
        walk(*f, c, (a == b) ? d : e, 0, out_numbered_callback);
    out_move(f, e);
    out_numbered_recurse(++a, b, c, d, e, f);
}

p *out_numbered(p *a, int b) {
    p *c = 0, *d = 0, *e = 0;

    if (! b) out_char(&c, 0);

    out_numbered_recurse(1, b, &a, &c, &d, &e);

    out_destroy(&e);
    return c;
}

void out_multiplex_callback(p *a, p **b, p **c, p **d) {
    out_string(b, (*a)[0]);
}

void out_multiplex_recurse(int a, int b, p **c, p **d) {
    p *e = 0;

    if (a > b) return;

    e = out_numbered(*c, a);
    walk(e, d, 0, 0, out_multiplex_callback);
    out_destroy(&e);

    out_multiplex_recurse(++a, b, c, d);
}

void out_multiplex(p **a, int b, int c) {
    p *d = 0;
    out_multiplex_recurse(b, c, a, &d);
    out_destroy(a);
    *a = d;
}

void out_merge_callback_callback(p *a, p **b, p **c, p **d) {
    out_mutate((*a)[0], (**d)[0], (! (**d)[1]) ? b : c);
}

int first;
void out_merge_callback(p *a, p **b, p **c, p **d) {
    if (first) out_mutate("", (*a)[0], (! (*a)[1]) ? b : c);
    else walk(*d, b, c, &a, out_merge_callback_callback);
    first = 0;
    out_move(d, c);
}

p *out_merge(p *a) {
    p *b = 0, *c = 0, *d = 0;

    first = 1;
    walk(a, &b, &d, &c, out_merge_callback);
    out_destroy(&c);

    return b;
}

void syn_die(char *a) {
    write(1, "syntax error: ", 14);
    write(1, a, str_len(a,a));
    write(1, "\n", 1);
    exit(1);
}

int scan_int(char *s, int *n) {
    int b, c = 0;
    *n = 0;

    while (s[c] && ((b = s[c++] - '0') < 10) && (b >= 0)) *n = *n * 10 + b;
    return c - 1;
}

int parse_bracket(char *s, p **o) {
    int c = 0;
    int inverted = 0;
    int i;
    char seen[127];

    if (s[c] == '^') { ++c; inverted = 1; }
    for (i = 1; i < 127; ++i) seen[i] = inverted;
    if (s[c] == ']') { seen[']'] = ! inverted; ++c; }
    while (s[c] && s[c] != ']') {
        seen[(int)s[c]] = ! inverted;
        ++c;
    }
    for (i = 0; i < 127; ++i) if (seen[i]) out_char(o, i);
    return c;
}

int parse_bounds(char *s, p **o) {
    int n, num = 0;
    int n1, n2;

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
    } else syn_die("bad {}: no i value found");

    return 0;
}

int parse_re(char *s, p **o);
int parse_atom(char *s, p **o) {
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

int parse_piece(char *s, p **o) {
    int n, num = 0;

    if (! *s) return 0;

    if ((n = parse_atom(s, o))) {
        s += n;
        num += n;
        n = parse_bounds(s, o);
        s += n;
        num += n;
    } else return 0;

    return num;
}

void parse_branch_callback(p *current, p **pieces, p **i, p **j) {
    *pieces = (*current)[1];
    out_destroy((p **)(&((*current)[0])));
    free(current);
}

int parse_branch(char *s, p **o) {
    int n, num = 0;
    p *output = 0;
    p *pieces = 0;

    if (! *s) return 0;

    while ((n = parse_piece(s, &output))) {
        p *new = malloc(sizeof(p));
        (*new)[0] = output;
        (*new)[1] = 0;

        out_append(&pieces, new);

        output = 0;
        s += n;
        num += n;
    }
    *o = out_merge(pieces);

    walk(pieces, &pieces, 0, 0, parse_branch_callback);

    if (*s == '|') num += 1;
    if ((! num) && (*s != ')')) syn_die("branch problem");

    return num;
}

int parse_re(char *s, p **o) {
    int n, num = 0;
    p *output = 0;

    if ((! s) || (! *s))
        syn_die("input string is empty");

    while ((n = parse_branch(s, &output))) {
        out_append(o, output);
        s += n;
        num += n;
    }

    return num;
}

void main_callback(p *ot, p **i, p **j, p **k) {
    write(1, "R", 1);
    write(1, (*ot)[0], str_len((*ot)[0],(*ot)[0]));
    write(1, "\t\t$@ <MATCH>\n", 13);
}

int main(int argc, char **argv) {
    p *output = 0;

    parse_re(argv[1], &output);

    write(1, "S88\n", 4);
    walk(output, 0, 0, 0, main_callback);
    write(1, "R$*\t\t$@ <NOMATCH>\n", 18);

    out_destroy(&output);

    exit(0);
}
