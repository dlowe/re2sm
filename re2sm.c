#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define _a (_*a _h b _h c _h d
#define _b if (
#define _c (_p a _h b, int *c
#define _d (int a, _p b _h c
#define _e void
#define _f _b *a ==
#define _g , b, c
#define _h , _**
#define _i && *a !=
#define _j (_p)**
#define _k _b !g++ || *(a + g++) !=
#define _l *e = 0, *f = 0, *g = 0
#define _m _r "error\n"); exit(1)
#define _n (int a, int b _h c _h d
#define _o a _g, d
#define _p char *
#define _q else
#define _r printf(
#define _s sscanf(a, "%d%n", &
#define _t strlen(
typedef _e *_[2];
int A;
 _e B _d) {
a[b] = !!c; 
 }
  _*T(unsigned int a) {
 _*b = malloc(sizeof(_));
 _b !b) {
_m;
 }
 **b = malloc(a);
 _b !**b) {
_m;
 }
 1[*b] = 0;
 return b;
  }
  _e P _a, _e (*e)_a)) {
 _*f;
 _b a) {
f = 1[*a];
e(_o);
P(f _g, d, e);
 }
  }
  _e G _a) {
 _b !1[*a]) {
1[*a] = *b;
 }
  }
  _e J(_**a, _*b) {
 _b *a) {
P(*a, &b, 0, 0, G);
 } _q {
*a = b;
 }
  }
 _e K(_**a, _p b) {
_*c = T(_t b) + 1);
strcpy(**c, b);
J(a, c);
 }
 _e C _a) {
K(b, **a);
 }
  _e S(_*a _h b, _p c) {
 _b a) {
_*d = 1[*a];
_*e = T(_t c) + _t **a) + 1);
strcpy(**e, c);
strcpy(_j e + _t c), **a);
J(b, e);
S(d _g);
 }
  }
 _e D _a) {
S(*b, c, **a);
 }
  _e M(_**a, int b) {
 _b b != 10 && b != 13) {
_*c = T(2);
*_j c = b;
1[_j c] = 0;
J(a, c);
 }
  }
  _e E _d) {
 _b a[b]) {
M(c, a);
 }
  }
 _e F(_**a _h b) {
*a = 0;
P(*b, a, 0, 0, C);
*b = 0;
 }
  _e H(int a _h b) {
 _b a != 127) {
M(b, a);
H(++a, b);
 }
  }
 _e I _a) {
S(***d, 1[**d] ? c : b, **a);
 }
 _e L _a) {
_r "R%s\t$@<MATCH>\n", _j a);
 }
  _e N _d, _e (*d)_d)) {
 _b a != 127) {
d(a _g);
N(++_o);
 }
  }
  _e O _a) {
 _b A) {
S(**a, 1[*a] ? c : b, "");
 } _q {
P(*d _g, &a, I);
 }
 A = 0;
 F(d, c);
  }
  _e Q _c, char d[127], int e) {
 _b a[*c] && a[*c] != 93 && a[*c] > 0) {
a[(*c)++][d] = !e;
Q(_o, e);
 }
  }
   _e U _n _h e _h f) {
  _b a <= b) {
 _b a == 1) {
S(*c, a == b ? d : e, "");
 } _q {
P(*f, c, a == b ? d : e, 0, D);
 }
 F(f, e);
 U(++_o, e, f);
  }
   }
   _e R _n) {
  _ _l;
  _b a <= b) {
 _b !a) {
M(&e, 0);
 }
 U(1, a, c, &e, &f, &g);
 P(e, d, 0, 0, C);
 R(++_o);
  }
   }
_e W _c);
     _e V _c) {
    _*d = 0, *e = 0;
    char f[127];
    int g = 0, h = 0, i = 0, j = 0;
    _b *a) {
   _f 40) {
  _b 1[a] == 41) {
 M(&d, 0);
 g = 2;
  } _q {
 W(a + 1, &d, &g);
 _k 41) {
_m;
 }
  }
   } _q _f 91) {
  _b a[g + 1] == 94) {
 ++g;
 h = 1;
  }
  N(1, f, (_**) h, B);
  _b a[g + 1] == 93) {
 ++g;
 93[f] = !h;
  }
  Q(a + 1, 0, &g, f, h);
  N(1, f, &d, E);
  _k 93) {
 _m;
  }
   } _q _f 92) {
  _b 1[a] < 1 || 1[a] == 10 || 1[a] == 13) {
 _m;
  }
  M(&d, *(a + 1));
  g = 2;
   } _q _f 46) {
  H(1, &d);
  g = 1;
   } _q _b *a > 0 _i 10 _i 13 _i 41 _i 63 _i 123 _i 124) {
  M(&d, *a);
  g = 1;
   }
    }
    a += g;
    h = 0;
    _b g) {
   _f 63) {
  ++a;
  ++g;
  ++j;
   } _q _f 123) {
  ++a;
  ++g;
  _s i, &h);
  _b !h || i < 0) {
 _m;
  }
  g += h;
  a += h;
  _b *a != 44 _i 125) {
 _m;
  }
  _f 44) {
 ++a;
 ++g;
 _s j, &h);
 _b !h) {
_m;
 }
 g += h;
 a += h;
 _b *a != 125) {
_m;
 }
 ++a;
 ++g;
 _b j < i) {
_m;
 }
  } _q {
 ++a;
 ++g;
 j = i;
  }
   }
   _b h || j) {
  R(i, j, &d, &e);
  d = e;
   }
    }
    _b g) {
   e = T(1);
   **e = d;
   1[*e] = 0;
   J(b, e);
   *c += g;
   V(a _g);
    }
     }
   _e W _c) {
  _*d = 0, _l;
  int h = 0;
  _b *a) {
 V(a, &e, &h);
 A = 1;
 P(e, b, &g, &f, O);
 _f 124) {
++h;
 }
 _b !h _i 41) {
_m;
 }
  }
  _b h) {
 J(b, d);
 a += h;
 *c += h;
 W(a _g);
  }
   }
  int main(int a, _p*b) {
 _*c = 0;
 _b !1[b] || !*(1[b])) {
_m;
 }
 W(1[b], &c, &a);
 _r "S3\n");
 P(c, 0, 0, 0, L);
 _r "R$*\t$@<NOMATCH>\n");
 exit(0);
  }
