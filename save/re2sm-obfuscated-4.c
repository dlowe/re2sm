#include <stdlib.h>
#include <stdio.h>

#define _a (_* a _e b _e c _e d
#define _b (char *
#define _c void
#define _d _g*a ==
#define _e , _**
#define _f printf("error\n"); exit(1)
#define _g if (
#define _h && *a !=
#define _i (_m a _e b _e c
#define _j else
#define _k a, b, c
#define _l (_**
#define _m int
#define _n = malloc(sizeof(_))
#define _o _g !g++ || *(a + g++) !=
#define _p strlen(
#define _q sscanf(a, "%u%n", &
#define _r (_m a, _m b _e c _e d
#define _s *e = 0, *f = 0, *g = 0

typedef _c *_[2];

_m A;

  _c C _i) {
a[_b)b] = !!c;
  }

    _c F _a) {
  _g! 1[*a]) {
1[*a] = *b;
  }
    }

  _c G _a) {
printf("R%s\t$@<MATCH>\n", _b)**a);
  }

  _* K(_m a) {
_* b _n;
**b = malloc(a);
1[*b] = 0;
return b;
  }

    _c M _i, _c (*d)(_m _e _e)) {
  _g a != 127) {
d(_k);
M(++_k, d);
  }
    }

    _c P _a, _c (*e)(_* _e _e _e)) {
  _* f;
  _g a) {
f = 1[*a];
e(_k, d);
P(f, b, c, d, e);
  }
    }

    _c L _l a, _* b) {
  _g*a) {
P(*a, &b, 0, 0, F);
  } _j {
*a = b;
  }
    }

  _c O _l a, char b) {
_* c = K(2);
*_b)**c = b;
1[_b)**c] = 0;
L(a, c);
  }

    _c E _i) {
  _g a[_b)b]) {
O(c, a);
  }
    }

    _c H _i) {
  _g a != 10 && a != 13) {
O(b, a);
  }
    }

  _c N _l a, char *b) {
_* c = K(_p b) + 1);
strcpy(**c, b);
L(a, c);
  }

  _c B _a) {
N(b, **a);
  }

  _c J _l a _e b) {
*a = 0;
P(*b, a, 0, 0, B);
*b = 0;
  }

    _c Q _b a, _m *b, char c[127], _m d) {
  _g a[*b] && a[*b] != 93) {
a[(*b)++][c] = !d;
Q(_k, d);
  }
    }

  _c S _a) {
_* e = K(_p _b) c) + _p**a) + 1);
strcpy(**e, _b)c);
strcpy(_b)**e + _p _b)c), **a);
L(b, e);
  }

  _c D _a) {
P(*b, c, **a, d, S);
  }

  _c I _a) {
P(***d, 1[**d] ? c : b, **a, 0, S);
  }

    _c R _a) {
  _g A) {
P(**a, 1[*a] ? c : b, _l)"", 0, S);
  } _j {
P(*d, b, c, &a, I);
  }
  A = 0;
  J(d, c);
    }

      _c U _r _e e _e f) {
    _g a <= b) {
  _g a == 1) {
P(*c, a == b ? d : e, _l)"", 0, S);
  } _j {
P(*f, c, a == b ? d : e, 0, D);
  }
  J(f, e);
  U(++_k, d, e, f);
    }
      }

      _c T _r) {
    _ _s;
    _g a <= b) {
  _g! a) {
O(&e, 0);
  }
  U(1, a, c, &e, &f, &g);
  P(e, d, 0, 0, B);
  T(++_k, d);
    }
      }

_c V _b _e, _m *);

                _c W _b a _e b, _m *c) {
              _*d=0, *e=0;
              char f[127];
              _m g=0, h=0, i=0, j=0;
              _g *a) {
            _d 40) {
          _g 1[a] == 41) {
        O(&d, 0);
        g = 2;
          } _j {
        V(a + 1, &d, &g);
        _o 41) {
      _f;
        }
          }
            } _j _d 91) {
          _g a[g+1] == 94) {
        ++g;
        h = 1;
          }
          M(0, _l)f, _l)h, C);
          _g a[g+1] == 93) {
        ++g;
        93[f] = !h;
          }
          Q(a + 1, &g, f, h);
          M(0, _l)f, &d, E);
          _o 93) {
        _f;
          }
            } _j _d 92) {
          _g ! 1[a]) {
          _f;
            }
          O(&d, *(a+1));
          g = 2;
            } _j _d 46) {
          M(1, &d, 0, H);
          g = 1;
            } _j _g *a != 46 _h 91 _h 40 _h 41 _h 124 _h 63 _h 123 _h 92) {
          O(&d, *a);
          g = 1;
            }
              }
              a += g;
              _g g) {
            _d 63) {
          ++a;
          ++j;
          ++g;
            } _j _d 123) {
          ++a;
          ++g;
          _q i, &h);
          _g h) {
        g += h;
        a += h;
        _d 44) {
      ++g;
      ++a;
      _q j, &h);
      _g h) {
    g += h;
    a += h;
    _d 125) {
  ++g;
  ++a;
  _g j < i) {
_f;
  }
    } _j {
  _f;
    }
      } _j {
    _f;
      }
        } _j _d 125) {
      ++g;
      ++a;
      j = i;
        } _j {
      _f;
        }
          } _j {
        _f;
          }
            }
            _g h||j) {
          T(i, j, &d, &e);
          d = e;
            }
              }
              _g g) {
            e _n;
            **e = d;
            1[*e] = 0;
            L(b, e);
            *c += g;
            W(_k);
              }
                }

      _c V _b a _e b, _m *c) {
    _*d = 0, _s;
    _m h = 0;
    _g *a) {
  W(a, &e, &h);
  A = 1;
  P(e, b, &g, &f, R);
  _d 124) {
++h;
  }
  _g !h _h 41) {
_f;
  }
    }
    _g h) {
  L(b, d);
  a += h;
  *c += h;
  V(_k);
    }
      }

    _m main(_m a, char **b) {
  _* c = 0;
  _g !1[b] || !*(1[b])) {
_f;
  }
  V(1[b], &c, &a);
  printf("S3\n");
  P(c, 0, 0, 0, G);
  printf("R$*\t$@<NOMATCH>\n");
  exit(0);
    }
