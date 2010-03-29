#include <unistd.h>
#include <stdlib.h>

typedef void *_[2];
typedef _ *__;
typedef __ *___;

void C(__ a, ___ b, ___ c, ___ d, void (*e)(__, ___, ___, ___)) {
    __ f;
    if (a) {
        f = 1[*a];
        e(a, b, c, d);
        C(f, b, c, d, e);
    }
}

void D(__ a, ___ b, ___ c, ___ d) {
    *b = 1[*a];
    free(**a);
    **a = 0;
    free(a);
}

__ E(int a) {
    __ b = malloc(sizeof(_));
    **b = malloc(a);
    1[*b] = 0;
    return b;
}

void F(__ a, ___ b, ___ c, ___ d) {
    if (! 1[*a]) 1[*a] = *b;
}

void G(___ a, __ b) {
    if (*a) C(*a, &b, 0, 0, F);
    else *a = b;
}

void H(___ a, char b) {
    __ c = E(2);
    *(char *)**c = b;
    1[(char *)**c] = 0;
    G(a, c);
}

void I(___ a, char *b) {
    __ c = E(strlen(b) + 1);
    strcpy(**c, b);
    G(a, c);
}

void J(__ a, ___ b, ___ c, ___ d) {
    I(b, **a);
}

void K(___ a, ___ b) {
    C(*a, a, 0, 0, D);
    C(*b, a, 0, 0, J);
    C(*b, b, 0, 0, D);
}

void L(__ a, ___ b, ___ c, ___ d) {
    __ e = E(strlen((char *)c) + strlen(**a) + 1);
    strcpy(**e, (char *)c);
    strcpy((char *)**e + strlen((char *)c), **a);
    G(b, e);
}

void M(__ a, ___ b, ___ c, ___ d) {
    C(*b, c, **a, 0, L);
}

void N(int a, int b, ___ c, ___ d, ___ e, ___ f) {
    if (a > b) return;
    if (a == 1)
        C(*c, a == b ? d : e, (___)"", 0, L);
    else
        C(*f, c, a == b ? d : e, 0, M);
    K(f, e);
    N(++a, b, c, d, e, f);
}

void O(int a, int b, ___ c, ___ d) {
    __ e = 0, f = 0, g = 0;

    if (a > b) return;

    if (! a) H(&e, 0);
    
    N(1, a, c, &e, &f, &g);
    C(g, &g, 0, 0, D);

    C(e, d, 0, 0, J);
    C(e, &e, 0, 0, D);

    O(++a, b, c, d);
}

void P(__ a, ___ b, ___ c, ___ d) {
    C(***d, 1[**d] ? c : b, **a, 0, L);
}

int Q;

void R(__ a, ___ b, ___ c, ___ d) {
    if (Q) C(**a, 1[*a] ? c : b, (___)"", 0, L);
    else C(*d, b, c, &a, P);
    Q = 0;
    K(d, c);
}

void S(void) {
    exit(1);
}

int T(char *a, int *b, int c) {
    int d;
    if (!c[a] || (d = c[a] - '0') >= 10 || d < 0) return c;
    *b = *b * 10 + d;
    return T(a, b, ++c);
}

void U(int a, ___ b, ___ c, void (*d)(int, ___, ___)) {
    if (a == 127) return;
    d(a, b, c);
    U(++a, b, c, d);
}

void V(int a, ___ b, ___ c) {
    a[(char *)b] = !!c;
}

void W(int a, ___ b, ___ c) {
    if (a[(char *)b]) H(c, a);
}

void X(char *a, int *b, char c[127], int d) {
    if (!a[*b] || a[*b] == ']') return;
    a[(*b)++][c] = !d;
    X(a, b, c, d);
}

void Y(int a, ___ b, ___ c) {
    if (a != 10 && a != 13) H(b, a);
}

void B(char *a, ___ b, int *c);

void Z(__ a, ___ b, ___ c, ___ d) {
    *b = 1[*a];
    C(**a, (___)*a, 0, 0, D);
    free(a);
}

void A(char *a, ___ b, int *c) {
    __ d=0, e=0, f=0;
    int g=0, h=0, i=0, j, k=0, l=0;
    char m[127];

    if (*a) {
        if (*a == '(') {
            if (1[a] == ')') {
                H(&d, 0);
                g = 2;
            } else {
                B(a + 1, &d, &g);
                if (!g || *(a + g + 1) != ')') S();
                g += 2;
            }
        } else if (*a == '[') {
            if (a[g+1] == '^') { ++g; i = 1; }
            U(0, (___)m, (___)i, V);
            if (a[g+1] == ']') { ++g; ']'[m] = !i; }
            X(a + 1, &g, m, i);
            U(0, (___)m, &d, W);
            if (!g || *(a + g + 1) != ']') S();
            g += 2;
        } else if (*a == '\\') {
            if (! 1[a]) S();
            H(&d, *(a+1));
            g = 2;
        } else if (*a == '.') {
            U(1, &d, 0, Y);
            g = 1;
        } else if (*a != '.' && *a != '[' && *a != '(' && *a != ')'
             && *a != '|' && *a != '?' && *a != '{' && *a != '\\') {
            H(&d, *a);
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

            j = T(a, &k, 0);
            if (j) {
                if (k > 255) S();
                h += j;
                a += j;

                if (*a == ',') {
                    ++h;
                    ++a;
                    j = T(a, &l, 0);
                    if (j) {
                        if (l > 255) S();
                        h += j;
                        a += j;
                        if (*a == '}') {
                            ++h;
                            ++a;
                            if (l < k) S();
                        } else S();
                    } else S();
                } else if (*a == '}') {
                    ++h;
                    ++a;
                    l = k;
                } else S();
            } else S();
        }

        if (h) {
            O(k, l, &d, &f);
            C(d, &d, 0, 0, D);
            d = f;
        }
        g += h;
    }

    if (! g) return;

    e = malloc(sizeof(_));
    **e = d;
    1[*e] = 0;

    G(b, e);

    d = 0;
    *c += g;

    A(a, b, c);
}

void B(char *a, ___ b, int *c) {
    __ d = 0, e = 0, f = 0, g = 0;
    int h = 0;

    if (*a) {
        A(a, &e, &h);
        Q = 1;
        C(e, b, &g, &f, R);
        C(f, &f, 0, 0, D);
        C(e, &e, 0, 0, Z);
        if (*a == '|') ++h;
        if (!h && *a != ')') S();
    }

    if (! h) return;
    G(b, d);
    a += h;
    *c += h;
    B(a, b, c);
}

void CC(__ a, ___ b, ___ c, ___ d) {
    write(1, "R", 1);
    write(1, **a, strlen(**a));
    write(1, "\t\t$@ <Y>\n", 13);
}

int main(int a, char **b) {
    __ c = 0;

    if (!1[b] || !*(1[b])) S();

    B(1[b], &c, &a);

    write(1, "S88\n", 4);
    C(c, 0, 0, 0, CC);
    write(1, "R$*\t\t$@ <N>\n", 18);

    C(c, &c, 0, 0, D);

    exit(0);
}
