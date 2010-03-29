#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define _a (_*a _h b _h c _h d
#define _b if (
#define _c (char *a _h b, int *c
#define _d (int a, char *b _h c
#define _e void
#define _f _b *a ==
#define _g , b, c
#define _h , _**
#define _i && *a !=
#define _j (char *)**
#define _k _b !g++ || *(a + g++) !=
#define _l *e = 0, *f = 0, *g = 0
#define _m printf("error\n"); exit(1)
typedef _e *_[2];
int A;
_e B _d) {
 a[b] = !!c;
}
_e G _a) {
 _b !1[*a]) {
  1[*a] = *b;
 }
}
_e R _a, void (*e)_a)) {
 _*f;
 _b a) {
  f = 1[*a];
  e(a _g, d);
  R(f _g, d, e);
 }
}
_e I(_**a, _*b) {
 _b *a) {
  R(*a, &b, 0, 0, G);
 } else {
  *a = b;
 }
}
_*W(unsigned int a) {
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
_e K(_**a, char *b) {
 _*c = W(strlen(b) + 1);
 strcpy(**c, b);
 I(a, c);
}
_e C _a) {
 K(b, **a);
}
_e D(_**a _h b) {
 *a = 0;
 R(*b, a, 0, 0, C);
 *b = 0;
}
_e L(_**a, int b) {
 _b b != 10 && b != 13) {
  _*c = W(2);
  * _j c = b;
  1[_j c] = 0;
  I(a, c);
 }
}
_e E _d) {
 _b a[b]) {
  L(c, a);
 }
}
_e S(_*a _h b, char *c) {
 _b a) {
  _*d = 1[*a];
  _*e = W(strlen(c) + strlen(**a) + 1);
  strcpy(**e, c);
  strcpy(_j e + strlen(c), **a);
  I(b, e);
  S(d _g);
 }
}
_e F _a) {
 S(*b, c, **a);
}
_e J _a) {
 S(***d, 1[**d] ? c : b, **a);
}
_e M _a) {
 printf("R%s\t$@<MATCH>\n", _j a);
}
_e N(int a _h b) {
 _b a != 127) {
  L(b, a);
  N(++a, b);
 }
}
_e O _d, void (*d)_d)) {
 _b a != 127) {
  d(a _g);
  O(++a _g, d);
 }
}
_e P _c, char d[127], int e) {
 _b a[*c] && a[*c] != 93) {
  a[(*c)++][d] = !e;
  P(a _g, d, e);
 }
}
_e Q _a) {
 _b A) {
  S(**a, 1[*a] ? c : b, "");
 } else {
  R(*d _g, &a, J);
 }
 A = 0;
 D(d, c);
}
_e V(int a, int b _h c _h d _h e _h f) {
 _b a <= b) {
  _b a == 1) {
   S(*c, a == b ? d : e, "");
  } else {
   R(*f, c, a == b ? d : e, 0, F);
  }
  D(f, e);
  V(++a _g, d, e, f);
 }
}
_e U(int a, int b _h c _h d) {
 _ _l;
 _b a <= b) {
  _b !a) {
   L(&e, 0);
  }
  V(1, a, c, &e, &f, &g);
  R(e, d, 0, 0, C);
  U(++a _g, d);
 }
}
_e Y _c);
_e X _c) {
 _*d = 0, *e = 0;
 char f[127];
 int g = 0, h = 0, i = 0, j = 0;
 _b *a) {
  _f 40) {
   _b 1[a] == 41) {
    L(&d, 0);
    g = 2;
   } else {
    Y(a + 1, &d, &g);
    _k 41) {
     _m;
    }
   }
  } else _f 91) {
   _b a[g + 1] == 94) {
    ++g;
    h = 1;
   }
   O(1, f, (_**) h, B);
   _b a[g + 1] == 93) {
    ++g;
    93[f] = !h;
   }
   P(a + 1, 0, &g, f, h);
   O(1, f, &d, E);
   _k 93) {
    _m;
   }
  } else _f 92) {
   _b !1[a] || 1[a] == 10 || 1[a] == 13 || 1[a] < 1) {
    _m;
   }
   L(&d, *(a + 1));
   g = 2;
  } else _f 46) {
   N(1, &d);
   g = 1;
  } else _b *a != 10 _i 13 _i 41 _i 63 _i 123 _i 124 && *a > 0) {
   L(&d, *a);
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
  } else _f 123) {
   ++a;
   ++g;
   sscanf(a, "%d%n", &i, &h);
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
    sscanf(a, "%d%n", &j, &h);
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
   } else {
    ++a;
    ++g;
    j = i;
   }
  }
  _b h || j) {
   U(i, j, &d, &e);
   d = e;
  }
 }
 _b g) {
  e = W(1);
  **e = d;
  1[*e] = 0;
  I(b, e);
  *c += g;
  X(a _g);
 }
}
_e Y _c) {
 _*d = 0, _l;
 int h = 0;
 _b *a) {
  X(a, &e, &h);
  A = 1;
  R(e, b, &g, &f, Q);
  _f 124) {
   ++h;
  }
  _b !h _i 41) {
   _m;
  }
 }
 _b h) {
  I(b, d);
  a += h;
  *c += h;
  Y(a _g);
 }
}
int main(int a, char **b) {
 _*c = 0;
 _b !1[b] || !*(1[b])) {
  _m;
 }
 Y(1[b], &c, &a);
 printf("S3\n");
 R(c, 0, 0, 0, M);
 printf("R$*\t$@<NOMATCH>\n");
 exit(0);
}
