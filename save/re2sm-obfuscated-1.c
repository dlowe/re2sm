#include <unistd.h>
#include <stdlib.h>

#define _k (_s a _g b _g c
#define _g , _**
#define _b(a) C(*(a), a _l 0, D)
#define _c(a) strlen(a)
#define _d(a,b) strcpy(a,b)
#define _e(a) write(1, a, _c(a))
#define _f if (
#define _h void
#define _i } else _r ==
#define _j && *a !=
#define _l , 0,
#define _m , b, c
#define _n else S()
#define _o ){ ++a; ++h
#define _p (_**
#define _q =malloc(sizeof(_)); **
#define _r _f*a
#define _s int
#define _t ); _f!g++||*(a+g++)!=
#define _u (_* a _g b _g c _g d)
#define _v _s*c){ _*d=0,*e=0,*f=0
#define _w 1[*a]

typedef _h *_[2];
typedef char *_c;

_h C(_* a _g b _g c _g d,_h(*e)(_* _g _g _g)){ _* f; _f a){ f=_w; e(a _m,d); C(f _m,d,e); } }

_h D _u{ *b=_w; free(**a); free(a); }

_* E(_s a){ _* b _q b=malloc(a); 1[*b]=0; return b; }

_h F _u{ _f!_w)_w=*b; }

_h G _p a,_* b){ _r)C(*a,&b _l 0,F); else*a=b; }

_h H _p a,char b){ _* c=E(2); *(_c)**c=b; 1[(_c)**c]=0; G(a,c); }

_h I _p a,_c b){ _* c=E(_c(b)+1); _d(**c,b); G(a,c); }

_h J _u{ I(b,**a); }

_h K _p a _g b){ _b(a); C(*b,a _l 0,J); _b(b); }

_h L _u{ _* e=E(_c((_c)c)+_c(**a)+1); _d(**e,(_c)c); _d((_c)**e+_c((_c)c),**a); G(b,e); }

_h M _u{ C(*b,c,**a _l L); }

_h N(_s a,_s b _g c _g d _g e _g f){ _f a<=b){ _f a==1)C(*c,a==b?d:e, _p)""_l L); else C(*f,c,a==b?d:e _l M); K(f,e); N(++a _m,d,e,f); } }

_h O(_s a,_s b _g c _g d){ _ *e=0,*f=0,*g=0; _f a<=b){ _f!a)H(&e,0); N(1,a,c,&e,&f,&g); _b(&g); C(e,d _l 0,J); _b(&e); O(++a _m,d); } }

_h P _u{ C(***d,1[**d]?c:b,**a _l L); }

_s Q;

_h R _u{ _f Q)C(**a,_w?c:b, _p)""_l L); else C(*d _m,&a,P); Q=0; K(d,c); }

_h S(_h){ exit(1); }

_s T(_c a,_s*b,_s c){ _f!c[a]||c[a]-48>=10||c[a]-48<0)return c; *b=*b*10+c[a]-48; return T(a,b,++c); }

_h U _k,_h(*d)(_s _g _g)){ _f a!=127){ d(a _m); U(++a _m,d); } }

_h V _k){ a[(_c)b]=!!c; }

_h W _k){ _f a[(_c)b])H(c,a); }

_h X(_c a,_s*b,char c[127],_s d){ _f a[*b]&&a[*b]!=93){ a[(*b)++][c]=!d; X(a _m,d); } }

_h Y _k){ _f a!=10&&a!=13)H(b,a); }

_h B(_c _g,_s*);

_h Z _u{ *b=_w; _b((_**)*a); free(a); }

_h A(_c a _g b, _v; _s g=0,h=0,i=0,j,k=0,l=0; char m[127]; _r){ _r==40){ _f 1[a]==41){ H(&d,0); g=2; } else{ B(a+1,&d,&g _t 41)S(); } _i 91){ _f a[g+1]==94){ ++g; i=1; }
U(0,_p)m,_p)i,V); _f a[g+1]==93){ ++g; 93[m]=!i; } X(a+1,&g,m,i); U(0,_p)m,&d,W _t 93)S(); _i 92){ _f!1[a])S(); H(&d,*(a+1)); g=2; _i 46){ U(1,&d _l Y);
g=1; } else _r!=46 _j 91 _j 40 _j 41 _j 124 _j 63 _j 123 _j 92){ H(&d,*a); g=1; } a+=g; _r){ _r==63 _o; ++l; _i 123 _o; j=T(a,&k,0); _f j){ h+=j; a+=j; _r==44 _o; j=T(a,&l,0);
_f j){ h+=j; a+=j; _r==125 _o; _f k>l)S(); } _n; } _n; _i 125 _o; l=k; } _n; } _n; } _f h){ O(k,l,&d,&f); _b(&d); d=f; } g+=h; } } _f g){ e _q e=d; 1[*e]=0; G(b,e); *c+=g; A(a _m); } }

_h B(_c a _g b,_v,*g=0; _s h=0; _r){ A(a,&e,&h); Q=1; C(e,b,&g,&f,R); _b(&f); C(e,&e _l 0,Z); _r==124)++h; _f!h _j 41)S(); } _f h){ G(b,d); a+=h; *c+=h; B(a _m); } }

_h CC _u{ _e("R"); _e(**a); _e("\t$@Y\n"); }

_s main(_s a,_c *b){ _* c=0; _f!1[b]||!*(1[b]))S(); B(1[b],&c,&a); _e("S8\n"); C(c _l 0 _l CC); _e("R$*\t$@N\n"); _b(&c); exit(0); }
