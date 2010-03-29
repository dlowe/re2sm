#include <unistd.h>
#include <stdlib.h>

typedef void *_[2];

int Q;

void C(_* a, _** b, _** c, _** d, void (*e)(_*, _**, _**, _**)) {
    _* f;
    if (a) {
        f = 1[*a];
        e(a, b, c, d);
        C(f, b, c, d, e);
    }
}

void D(_* a, _** b, _** c, _** d) {
    *b = 1[*a];
    free(**a);
    **a = 0;
    free(a);
}

_* E(int a) {
    _* b = malloc(sizeof(_));
    **b = malloc(a);
    1[*b] = 0;
    return b;
}

void F(_* a, _** b, _** c, _** d) {
    if (! 1[*a]) 1[*a] = *b;
}

void G(_** a, _* b) {
    if (*a) C(*a, &b, 0, 0, F);
    else *a = b;
}

void H(_** a, char b) {
    _* c = E(2);
    *(char *)**c = b;
    1[(char *)**c] = 0;
    G(a, c);
}

void I(_** a, char *b) {
    _* c = E(strlen(b) + 1);
    strcpy(**c, b);
    G(a, c);
}

void J(_* a, _** b, _** c, _** d) {
    I(b, **a);
}

void K(_** a, _** b) {
    C(*a, a, 0, 0, D);
    C(*b, a, 0, 0, J);
    C(*b, b, 0, 0, D);
}

void L(_* a, _** b, _** c, _** d) {
    _* e = E(strlen((char *)c) + strlen(**a) + 1);
    strcpy(**e, (char *)c);
    strcpy((char *)**e + strlen((char *)c), **a);
    G(b, e);
}

void M(_* a, _** b, _** c, _** d) {
    C(*b, c, **a, 0, L);
}

void N(int a, int b, _** c, _** d, _** e, _** f) {
    if (a > b) return;
    if (a == 1)
        C(*c, a == b ? d : e, (_**)"", 0, L);
    else
        C(*f, c, a == b ? d : e, 0, M);
    K(f, e);
    N(++a, b, c, d, e, f);
}

void O(int a, int b, _** c, _** d) {
    _*e = 0, *f = 0, *g = 0;

    if (a > b) return;

    if (! a) H(&e, 0);
    
    N(1, a, c, &e, &f, &g);
    C(g, &g, 0, 0, D);

    C(e, d, 0, 0, J);
    C(e, &e, 0, 0, D);

    O(++a, b, c, d);
}

void P(_* a, _** b, _** c, _** d) {
    C(***d, 1[**d] ? c : b, **a, 0, L);
}

void R(_* a, _** b, _** c, _** d) {
    if (Q) C(**a, 1[*a] ? c : b, (_**)"", 0, L);
    else C(*d, b, c, &a, P);
    Q = 0;
    K(d, c);
}

void S(void) {
    exit(1);
}

int T(char *a, int *b, int c) {
    if (!c[a] || (Q = c[a] - 48) >= 10 || Q < 0) return c;
    *b = *b * 10 + Q;
    return T(a, b, ++c);
}

void U(int a, _** b, _** c, void (*d)(int, _**, _**)) {
    if (a == 127) return;
    d(a, b, c);
    U(++a, b, c, d);
}

void V(int a, _** b, _** c) {
    a[(char *)b] = !!c;
}

void W(int a, _** b, _** c) {
    if (a[(char *)b]) H(c, a);
}

void X(char *a, int *b, char c[127], int d) {
    if (!a[*b] || a[*b] == 93) return;
    a[(*b)++][c] = !d;
    X(a, b, c, d);
}

void Y(int a, _** b, _** c) {
    if (a != 10 && a != 13) H(b, a);
}

void B(char *a, _** b, int *c);

void Z(_* a, _** b, _** c, _** d) {
    *b = 1[*a];
    C(**a, (_**)*a, 0, 0, D);
    free(a);
}

void A(char *a, _** b, int *c) {
    _*d=0, *e=0, *f=0;
    int g=0, h=0, i=0, j, k=0, l=0;
    char m[127];

    if (*a) {
        if (*a == 40) {
            if (1[a] == 41) {
                H(&d, 0);
                g = 2;
            } else {
                B(a + 1, &d, &g);
                if (!g++ || *(a + g++) != 41) S();
            }
        } else if (*a == 91) {
            if (a[g+1] == 94) { ++g; i = 1; }
            U(0, (_**)m, (_**)i, V);
            if (a[g+1] == 93) { ++g; 93[m] = !i; }
            X(a + 1, &g, m, i);
            U(0, (_**)m, &d, W);
            if (!g++ || *(a + g++) != 93) S();
        } else if (*a == 92) {
            if (! 1[a]) S();
            H(&d, *(a+1));
            g = 2;
        } else if (*a == 46) {
            U(1, &d, 0, Y);
            g = 1;
        } else if (*a != 46 && *a != 91 && *a != 40 && *a != 41
             && *a != 124 && *a != 63 && *a != 123 && *a != 92) {
            H(&d, *a);
            g = 1;
        }
    }
    a += g;

    if (*a) {
        if (*a == 63) {
            ++a;
            ++l;
            h=1;
        } else if (*a == 123) {
            ++a;
            h=1;

            j = T(a, &k, 0);
            if (j) {
                if (k > 255) S();
                h += j;
                a += j;

                if (*a == 44) {
                    ++h;
                    ++a;
                    j = T(a, &l, 0);
                    if (j) {
                        if (l > 255) S();
                        h += j;
                        a += j;
                        if (*a == 125) {
                            ++h;
                            ++a;
                            if (l < k) S();
                        } else S();
                    } else S();
                } else if (*a == 125) {
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

void B(char *a, _** b, int *c) {
    _*d = 0, *e = 0, *f = 0, *g = 0;
    int h = 0;

    if (*a) {
        A(a, &e, &h);
        Q = 1;
        C(e, b, &g, &f, R);
        C(f, &f, 0, 0, D);
        C(e, &e, 0, 0, Z);
        if (*a == 124) ++h;
        if (!h && *a != 41) S();
    }

    if (! h) return;
    G(b, d);
    a += h;
    *c += h;
    B(a, b, c);
}

void CC(_* a, _** b, _** c, _** d) {
    write(1, "R", 1);
    write(1, **a, strlen(**a));
    write(1, "\t\t$@ <Y>\n", 9);
}

int main(int a, char **b) {
    _* c = 0;

    if (!1[b] || !*(1[b])) S();

    B(1[b], &c, &a);

    write(1, "S88\n", 4);
    C(c, 0, 0, 0, CC);
    write(1, "R$*\t\t$@ <N>\n", 12);

    C(c, &c, 0, 0, D);

    exit(0);
}
