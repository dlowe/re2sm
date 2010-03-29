#include <stdlib.h>
#include <stdio.h>

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

_* E(int a) {
    _* b = malloc(sizeof(_));
    **b = malloc(a);
    1[*b] = 0;
    return b;
}

void F(_* a, _** b, _** c, _** d) {
    if (! 1[*a]) {
        1[*a] = *b;
    }
}

void G(_** a, _* b) {
    if (*a) {
        C(*a, &b, 0, 0, F);
    } else {
        *a = b;
    }
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
    *a = 0;
    C(*b, a, 0, 0, J);
    *b = 0;
}

void L(_* a, _** b, _** c, _** d) {
    _* e = E(strlen((char *)c) + strlen(**a) + 1);
    strcpy(**e, (char *)c);
    strcpy((char *)**e + strlen((char *)c), **a);
    G(b, e);
}

void M(_* a, _** b, _** c, _** d) {
    C(*b, c, **a, d, L);
}

void N(int a, int b, _** c, _** d, _** e, _** f) {
    if (a <= b) {
        if (a == 1) {
            C(*c, a == b ? d : e, (_**)"", 0, L);
        } else {
            C(*f, c, a == b ? d : e, 0, M);
        }
        K(f, e);
        N(++a, b, c, d, e, f);
    }
}

void O(int a, int b, _** c, _** d) {
    _*e = 0, *f = 0, *g = 0;

    if (a <= b) {
        if (! a) {
            H(&e, 0);
        }
    
        N(1, a, c, &e, &f, &g);
        C(e, d, 0, 0, J);
        O(++a, b, c, d);
    }
}

void P(_* a, _** b, _** c, _** d) {
    C(***d, 1[**d] ? c : b, **a, 0, L);
}

void R(_* a, _** b, _** c, _** d) {
    if (Q) {
        C(**a, 1[*a] ? c : b, (_**)"", 0, L);
    } else {
        C(*d, b, c, &a, P);
    }
    Q = 0;
    K(d, c);
}

void U(int a, _** b, _** c, void (*d)(int, _**, _**)) {
    if (a != 127) {
        d(a, b, c);
        U(++a, b, c, d);
    }
}

void V(int a, _** b, _** c) {
    a[(char *)b] = !!c;
}

void W(int a, _** b, _** c) {
    if (a[(char *)b]) {
        H(c, a);
    }
}

void X(char *a, int *b, char c[127], int d) {
    if (a[*b] && a[*b] != 93) {
        a[(*b)++][c] = !d;
        X(a, b, c, d);
    }
}

void Y(int a, _** b, _** c) {
    if (a != 10 && a != 13) {
        H(b, a);
    }
}

void B(char *, _**, int *);

void A(char *a, _** b, int *c) {
    _*d=0, *e=0;
    char f[127];
    int g=0, h=0, i=0, j=0;

    if (*a) {
        if (*a == 40) {
            if (1[a] == 41) {
                H(&d, 0);
                g = 2;
            } else {
                B(a + 1, &d, &g);
                if (!g++ || *(a + g++) != 41) {
                    exit(1);
                }
            }
        } else if (*a == 91) {
            if (a[g+1] == 94) {
                ++g;
                h = 1;
            }
            U(0, (_**)f, (_**)h, V);
            if (a[g+1] == 93) {
                ++g;
                93[f] = !h;
            }
            X(a + 1, &g, f, h);
            U(0, (_**)f, &d, W);
            if (!g++ || *(a + g++) != 93) {
                exit(1);
            }
        } else if (*a == 92) {
            if (! 1[a]) {
                exit(1);
            }
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

    if (g) {
        if (*a == 63) {
            ++a;
            ++j;
            ++g;
        } else if (*a == 123) {
            ++a;
            ++g;

            sscanf(a, "%u%n", &i, &h);
            if (h) {
                g += h;
                a += h;

                if (*a == 44) {
                    ++g;
                    ++a;
                    sscanf(a, "%u%n", &j, &h);
                    if (h) {
                        g += h;
                        a += h;
                        if (*a == 125) {
                            ++g;
                            ++a;
                            if (j < i) exit(1);
                        } else {
                            exit(1);
                        }
                    } else {
                        exit(1);
                    }
                } else if (*a == 125) {
                    ++g;
                    ++a;
                    j = i;
                } else {
                    exit(1);
                }
            } else {
                exit(1);
            }
        }

        if (h||j) {
            O(i, j, &d, &e);
            d = e;
        }
    }

    if (g) {
        e = malloc(sizeof(_));
        **e = d;
        1[*e] = 0;

        G(b, e);

        *c += g;

        A(a, b, c);
    }
}

void B(char *a, _** b, int *c) {
    _*d = 0, *e = 0, *f = 0, *g = 0;
    int h = 0;

    if (*a) {
        A(a, &e, &h);
        Q = 1;
        C(e, b, &g, &f, R);
        if (*a == 124) {
            ++h;
        }
        if (!h && *a != 41) {
            exit(1);
        }
    }

    if (h) {
        G(b, d);
        a += h;
        *c += h;
        B(a, b, c);
    }
}

void S(_* a, _** b, _** c, _** d) {
    printf("R%s\t$@Y\n", (char *)**a);
}

int main(int a, char **b) {
    _* c = 0;

    if (!1[b] || !*(1[b])) {
        exit(1);
    }

    B(1[b], &c, &a);

    printf("S3\n");
    C(c, 0, 0, 0, S);
    printf("R$*\t$@N\n");

    exit(0);
}
