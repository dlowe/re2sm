#include <stdlib.h>
#include <stdio.h>
#define _a (_* a _e b _e c _e d
#define _b (char *
#define _c void
#define _d _g*a ==
#define _e , _**
#define _f exit(1)
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
_m Q;
_c C _a, _c (*e)(_* _e _e _e)) {
  _* f;
  _g a) {
    f = 1[*a];
    e(_k, d);
    C(f, b, c, d, e);
  }
}
_* E(_m a) {
  _* b _n;
  **b = malloc(a);
  1[*b] = 0;
  return b;
}
_c F _a) {
  _g! 1[*a]) {
    1[*a] = *b;
  }
}
_c G _l a, _* b) {
  _g*a) {
    C(*a, &b, 0, 0, F);
  } _j {
    *a = b;
  }
}
_c H _l a, char b) {
  _* c = E(2);
  *_b)**c = b;
  1[_b)**c] = 0;
  G(a, c);
}
_c I _l a, char *b) {
  _* c = E(_p b) + 1);
  strcpy(**c, b);
  G(a, c);
}
_c J _a) {
  I(b, **a);
}
_c K _l a _e b) {
  *a = 0;
  C(*b, a, 0, 0, J);
  *b = 0;
}
_c L _a) {
  _* e = E(_p _b) c) + _p**a) + 1);
  strcpy(**e, _b)c);
  strcpy(_b)**e + _p _b)c), **a);
  G(b, e);
}
_c M _a) {
  C(*b, c, **a, d, L);
}
_c N _r _e e _e f) {
  _g a <= b) {
    _g a == 1) {
      C(*c, a == b ? d : e, _l)"", 0, L);
    } _j {
      C(*f, c, a == b ? d : e, 0, M);
    }
    K(f, e);
    N(++_k, d, e, f);
  }
}
_c O _r) {
  _ _s;
  _g a <= b) {
    _g! a) {
      H(&e, 0);
    }
    N(1, a, c, &e, &f, &g);
    C(e, d, 0, 0, J);
    O(++_k, d);
  }
}
_c P _a) {
  C(***d, 1[**d] ? c : b, **a, 0, L);
}
_c R _a) {
  _g Q) {
    C(**a, 1[*a] ? c : b, _l)"", 0, L);
  } _j {
    C(*d, b, c, &a, P);
  }
  Q = 0;
  K(d, c);
}
_c U _i, _c (*d)(_m _e _e)) {
  _g a != 127) {
    d(_k);
    U(++_k, d);
  }
}
_c V _i) {
  a[_b)b] = !!c;
}
_c W _i) {
  _g a[_b)b]) {
    H(c, a);
  }
}
_c X _b a, _m *b, char c[127], _m d) {
  _g a[*b] && a[*b] != 93) {
    a[(*b)++][c] = !d;
    X(_k, d);
  }
}
_c Y _i) {
  _g a != 10 && a != 13) {
    H(b, a);
  }
}
_c B _b _e, _m *);
_c A _b a _e b, _m *c) {
  _*d=0, *e=0;
  char f[127];
  _m g=0, h=0, i=0, j=0;
  _g *a) {
    _d 40) {
      _g 1[a] == 41) {
        H(&d, 0);
        g = 2;
      } _j {
        B(a + 1, &d, &g);
        _o 41) {
          _f;
        }
      }
    } _j _d 91) {
      _g a[g+1] == 94) {
        ++g;
        h = 1;
      }
      U(0, _l)f, _l)h, V);
      _g a[g+1] == 93) {
        ++g;
        93[f] = !h;
      }
      X(a + 1, &g, f, h);
      U(0, _l)f, &d, W);
      _o 93) {
        _f;
      }
    } _j _d 92) {
      _g ! 1[a]) {
        _f;
      }
      H(&d, *(a+1));
      g = 2;
    } _j _d 46) {
      U(1, &d, 0, Y);
      g = 1;
    } _j _g *a != 46 _h 91 _h 40 _h 41 _h 124 _h 63 _h 123 _h 92) {
      H(&d, *a);
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
      O(i, j, &d, &e);
      d = e;
    }
  }
  _g g) {
    e _n;
    **e = d;
    1[*e] = 0;
    G(b, e);
    *c += g;
    A(_k);
  }
}
_c B _b a _e b, _m *c) {
  _*d = 0, _s;
  _m h = 0;
  _g *a) {
    A(a, &e, &h);
    Q = 1;
    C(e, b, &g, &f, R);
    _d 124) {
      ++h;
    }
    _g !h _h 41) {
      _f;
    }
  }
  _g h) {
    G(b, d);
    a += h;
    *c += h;
    B(_k);
  }
}
_c S _a) {
  printf("R%s\t$@Y\n", _b)**a);
}
_m main(_m a, char **b) {
  _* c = 0;
  _g !1[b] || !*(1[b])) {
    _f;
  }
  B(1[b], &c, &a);
  printf("S3\n");
  C(c, 0, 0, 0, S);
  printf("R$*\t$@N\n");
  exit(0);
}
