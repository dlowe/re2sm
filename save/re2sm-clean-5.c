#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define _a(z, y) _b(z, y), _b((*e), y))) { _*f; if (a) { f = 1[*a]; e(a, b, c, d); z(f, b, c, d, e); } }
#define _b(z, y) void z(_*a, _**b, y *c, _**d
#define _c(z, y) _d(z, y), _d((*d), y))) { if (a != 127) { d(a, b, c); z(++a, b, c, d); } }
#define _d(z, y) void z(int a, y *b, _**c
#define _e(z)    void z(char *a, _**b, int *c
#define _f(z, y) void z(_**a, y b)
#define _g(z)    void z(int a, int b, _**c, _**d
#define _h(z)    if (z) { printf("error\n"); exit(1); }
typedef void *_[2];
int A;
_d(B, char)) {
 a[b] = !!c;
}
_b(G, _*)) {
 if (!1[*a]) {
  1[*a] = *b;
 }
}
_a(R, _*)
_f(I, _*) {
 if (*a) {
  R(*a, &b, 0, 0, G);
 } else {
  *a = b;
 }
}
_*W(unsigned int a) {
 _*b = malloc(sizeof(_));
 _h(!b)
 **b = malloc(a);
 _h(!**b)
 1[*b] = 0;
 return b;
}
_f(K, char *) {
 _*c = W(strlen(b) + 1);
 strcpy(**c, b);
 I(a, c);
}
_b(C, _*)) {
 K(b, **a);
}
_f(D, _**) {
 *a = 0;
 R(*b, a, 0, 0, C);
 *b = 0;
}
_f(L, int) {
 if (b != 10 && b != 13) {
  _*c = W(2);
  *(char *)**c = b;
  1[(char *)**c] = 0;
  I(a, c);
 }
}
_d(E, char)) {
 if (a[b]) {
  L(c, a);
 }
}
_a(S, char)
_b(T, char)) {
 _*e = W(strlen(c) + strlen(**a) + 1);
 strcpy(**e, c);
 strcpy((char *)**e + strlen(c), **a);
 I(b, e);
}
_b(F, _*)) {
 S(*b, c, **a, 0, T);
}
_d(H, _*)) {
 L(b, a);
}
_b(J, _*)) {
 S(***d, 1[**d] ? c : b, **a, 0, T);
}
_b(M, _*)) {
 printf("R%s	$@<MATCH>\n", (char *)**a);
}
_c(N, _*)
_c(O, char)
_e(P), char d[127], int e) {
 if (a[*c] && a[*c] != 93) {
  a[(*c)++][d] = !e;
  P(a, b, c, d, e);
 }
}
_b(Q, _*)) {
 if (A) {
  S(**a, 1[*a] ? c : b, "", 0, T);
 } else {
  R(*d, b, c, &a, J);
 }
 A = 0;
 D(d, c);
}
_g(V), _**e, _**f) {
 if (a <= b) {
  if (a == 1) {
   S(*c, a == b ? d : e, "", 0, T);
  } else {
   R(*f, c, a == b ? d : e, 0, F);
  }
  D(f, e);
  V(++a, b, c, d, e, f);
 }
}
_g(U)) {
 _*e = 0, *f = 0, *g = 0;
 if (a <= b) {
  if (!a) {
   L(&e, 0);
  }
  V(1, a, c, &e, &f, &g);
  R(e, d, 0, 0, C);
  U(++a, b, c, d);
 }
}
_e(Y));
_e(X)) {
 _*d = 0, *e = 0;
 char f[127];
 int g = 0, h = 0, i = 0, j = 0;
 if (*a) {
  if (*a == 40) {
   if (1[a] == 41) {
    L(&d, 0);
    g = 2;
   } else {
    Y(a + 1, &d, &g);
    _h(!g++ || *(a + g++) != 41)
   }
  } else if (*a == 91) {
   if (a[g + 1] == 94) {
    ++g;
    h = 1;
   }
   O(1, f, (_**)h, B);
   if (a[g + 1] == 93) {
    ++g;
    93[f] = !h;
   }
   P(a + 1, 0, &g, f, h);
   O(1, f, &d, E);
   _h(!g++ || *(a + g++) != 93)
  } else if (*a == 92) {
   _h(!1[a])
   L(&d, *(a + 1));
   g = 2;
  } else if (*a == 46) {
   N(1, &d, 0, H);
   g = 1;
  } else if (*a != 10 && *a != 13 && *a != 41 && *a != 63 && *a != 123 && *a != 124) {
   L(&d, *a);
   g = 1;
  }
 }
 a += g;
 h = 0;
 if (g) {
  if (*a == 63) {
   ++a; ++g;
   ++j;
  } else if (*a == 123) {
   ++a; ++g;
   sscanf(a, "%d%n", &i, &h);
   _h(!h || i < 0)
   g += h; a += h;
   _h(*a != 44 && *a != 125)
   if (*a == 44) {
    ++a; ++g;
    sscanf(a, "%d%n", &j, &h);
    _h(!h)
    g += h; a += h;
    _h(*a != 125)
    ++a; ++g;
    _h(j < i)
   } else {
    ++a; ++g;
    j = i;
   }
  }
  if (h || j) {
   U(i, j, &d, &e);
   d = e;
  }
 }
 if (g) {
  e = W(1);
  **e = d;
  1[*e] = 0;
  I(b, e);
  *c += g;
  X(a, b, c);
 }
}
_e(Y)) {
 _*d = 0, *e = 0, *f = 0, *g = 0;
 int h = 0;
 if (*a) {
  X(a, &e, &h);
  A = 1;
  R(e, b, &g, &f, Q);
  if (*a == 124) {
   ++h;
  }
  _h(!h && *a != 41)
 }
 if (h) {
  I(b, d);
  a += h;
  *c += h;
  Y(a, b, c);
 }
}
int main(int a, char **b) {
 _*c = 0;
 _h(!1[b] || !*(1[b]))
 Y(1[b], &c, &a);
 printf("S3\n");
 R(c, 0, 0, 0, M);
 printf("R$*	$@<NOMATCH>\n");
 exit(0);
}
