#include <unistd.h>
#include <stdlib.h>

typedef void *_[2];
typedef _ *__;
typedef __ *___;

int str_len(char *a, char *b) {
    return *b ? str_len(a, ++b) : b - a;
}

void str_cpy(char *a, char *b) {
    if ((*a = *b)) str_cpy(++a, ++b);
}

void walk(__ a, ___ b, ___ c, ___ d, void (*e)(__, ___, ___, ___)) {
    __ f;
    if (a) {
        f = 1[*a];
        e(a, b, c, d);
        walk(f, b, c, d, e);
    }
}

void out_destroy_callback(__ a, ___ b, ___ c, ___ d) {
    *b = 1[*a];
    free(**a);
    **a = 0;
    free(a);
}

__ out_new(int a) {
    __ b = malloc(sizeof(_));
    **b = malloc(a);
    1[*b] = 0;
    return b;
}

void out_append_callback(__ a, ___ b, ___ c, ___ d) {
    if (! 1[*a]) 1[*a] = *b;
}

void out_append(___ a, __ b) {
    if (*a) walk(*a, &b, 0, 0, out_append_callback);
    else *a = b;
}

void out_char(___ a, char b) {
    __ c = out_new(2);
    *(char *)**c = b;
    1[(char *)**c] = 0;
    out_append(a, c);
}

void out_string(___ a, char *b) {
    __ c = out_new(str_len(b,b) + 1);
    str_cpy(**c, b);
    out_append(a, c);
}

void out_move_callback(__ a, ___ b, ___ c, ___ d) {
    out_string(b, **a);
}

void out_move(___ a, ___ b) {
    walk(*a, a, 0, 0, out_destroy_callback);
    walk(*b, a, 0, 0, out_move_callback);
    walk(*b, b, 0, 0, out_destroy_callback);
}

void out_mutate_callback(__ a, ___ b, ___ c, ___ d) {
    __ e = out_new(str_len((char *)c, (char *)c) + str_len(**a, **a) + 1);
    str_cpy(**e, (char *)c);
    str_cpy((char *)**e + str_len((char *)c, (char *)c), **a);
    out_append(b, e);
}

void out_numbered_callback(__ a, ___ b, ___ c, ___ d) {
    walk(*b, c, **a, 0, out_mutate_callback);
}

void out_numbered_recurse(int a, int b, ___ c, ___ d, ___ e, ___ f) {
    if (a > b) return;
    if (a == 1)
        walk(*c, a == b ? d : e, (___)"", 0, out_mutate_callback);
    else
        walk(*f, c, a == b ? d : e, 0, out_numbered_callback);
    out_move(f, e);
    out_numbered_recurse(++a, b, c, d, e, f);
}

void out_multiplex_recurse(int a, int b, ___ c, ___ d) {
    __ e = 0, f = 0, g = 0;

    if (a > b) return;

    if (! a) out_char(&e, 0);
    
    out_numbered_recurse(1, a, c, &e, &f, &g);
    walk(g, &g, 0, 0, out_destroy_callback);

    walk(e, d, 0, 0, out_move_callback);
    walk(e, &e, 0, 0, out_destroy_callback);

    out_multiplex_recurse(++a, b, c, d);
}

void out_merge_callback_callback(__ a, ___ b, ___ c, ___ d) {
    walk(***d, 1[**d] ? c : b, **a, 0, out_mutate_callback);
}

int first;
void out_merge_callback(__ a, ___ b, ___ c, ___ d) {
    if (first) walk(**a, 1[*a] ? c : b, (___)"", 0, out_mutate_callback);
    else walk(*d, b, c, &a, out_merge_callback_callback);
    first = 0;
    out_move(d, c);
}

void die(void) {
    write(1, "error\n", 6);
    exit(1);
}

int scan_int(char *a, int *b, int c) {
    int d;
    if (!c[a] || (d = c[a] - '0') >= 10 || d < 0) return c;
    *b = *b * 10 + d;
    return scan_int(a, b, ++c);
}

void do127(int a, ___ b, ___ c, void (*d)(int, ___, ___)) {
    if (a == 127) return;
    d(a, b, c);
    do127(++a, b, c, d);
}

void parse_bracket_callback1(int a, ___ b, ___ c) {
    a[(char *)b] = !!c;
}

void parse_bracket_callback2(int a, ___ b, ___ c) {
    if (a[(char *)b]) out_char(c, a);
}

void parse_bracket_recurse(char *a, int *b, char c[127], int d) {
    if (!a[*b] || a[*b] == ']') return;
    a[(*b)++][c] = !d;
    parse_bracket_recurse(a, b, c, d);
}

void parse_atom_callback(int a, ___ b, ___ c) {
    if (a != 10 && a != 13) out_char(b, a);
}

void parse_re_recurse(char *a, ___ b, int *c);

void parse_branch_callback(__ a, ___ b, ___ c, ___ d) {
    *b = 1[*a];
    walk(**a, (___)*a, 0, 0, out_destroy_callback);
    free(a);
}

void parse_branch_recurse(char *a, ___ b, int *c) {
    __ d=0, e=0, f=0;
    int g=0, h=0, i=0, j, k=0, l=0;
    char m[127];

    if (*a) {
        if (*a == '(') {
            if (1[a] == ')') {
                out_char(&d, 0);
                g = 2;
            } else {
                parse_re_recurse(a + 1, &d, &g);
                if (!g || *(a + g + 1) != ')') die();
                g += 2;
            }
        } else if (*a == '[') {
            if (a[g+1] == '^') { ++g; i = 1; }
            do127(0, (___)m, (___)i, parse_bracket_callback1);
            if (a[g+1] == ']') { ++g; ']'[m] = !i; }
            parse_bracket_recurse(a + 1, &g, m, i);
            do127(0, (___)m, &d, parse_bracket_callback2);
            if (!g || *(a + g + 1) != ']') die();
            g += 2;
        } else if (*a == '\\') {
            if (! 1[a]) die();
            out_char(&d, *(a+1));
            g = 2;
        } else if (*a == '.') {
            do127(1, &d, 0, parse_atom_callback);
            g = 1;
        } else if (*a != '.' && *a != '[' && *a != '(' && *a != ')'
             && *a != '|' && *a != '?' && *a != '{' && *a != '\\') {
            out_char(&d, *a);
            g = 1;
        }
    }
    a += g;

    if (*a) {
        if (*a == '?') {
            ++a;
            ++l;
            ++h;
        } else if (*a == '{') {
            ++a;
            ++h;

            j = scan_int(a, &k, 0);
            if (j) {
                if (k > 255) die();
                h += j;
                a += j;

                if (*a == ',') {
                    ++h;
                    ++a;
                    j = scan_int(a, &l, 0);
                    if (j) {
                        if (l > 255) die();
                        h += j;
                        a += j;
                        if (*a == '}') {
                            ++h;
                            ++a;
                            if (l < k) die();
                        } else die();
                    } else die();
                } else if (*a == '}') {
                    ++h;
                    ++a;
                    l = k;
                } else die();
            } else die();
        }

        if (h) {
            out_multiplex_recurse(k, l, &d, &f);
            walk(d, &d, 0, 0, out_destroy_callback);
            d = f;
        }
        g += h;
    }

    if (! g) return;

    e = malloc(sizeof(_));
    **e = d;
    1[*e] = 0;

    out_append(b, e);

    d = 0;
    *c += g;

    parse_branch_recurse(a, b, c);
}

void parse_re_recurse(char *a, ___ b, int *c) {
    __ d = 0, e = 0, f = 0, g = 0;
    int h = 0;

    if (*a) {
        parse_branch_recurse(a, &e, &h);
        first = 1;
        walk(e, b, &g, &f, out_merge_callback);
        walk(f, &f, 0, 0, out_destroy_callback);
        walk(e, &e, 0, 0, parse_branch_callback);
        if (*a == '|') ++h;
        if (!h && *a != ')') die();
    }

    if (! h) return;
    out_append(b, d);
    a += h;
    *c += h;
    parse_re_recurse(a, b, c);
}

void main_callback(__ a, ___ b, ___ c, ___ d) {
    write(1, "R", 1);
    write(1, **a, str_len(**a,**a));
    write(1, "\t\t$@ <MATCH>\n", 13);
}

int main(int a, char **b) {
    __ c = 0;

    if (!1[b] || !*(1[b])) die();

    parse_re_recurse(1[b], &c, &a);

    write(1, "S88\n", 4);
    walk(c, 0, 0, 0, main_callback);
    write(1, "R$*\t\t$@ <NOMATCH>\n", 18);

    walk(c, &c, 0, 0, out_destroy_callback);

    exit(0);
}
