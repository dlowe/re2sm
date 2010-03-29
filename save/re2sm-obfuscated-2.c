#include <unistd.h>
#include <stdlib.h>

#define _a (_*a _g b _g c _g d
#define _b void
#define _c(a) write(1, a, strlen(a))
#define _d exit(1)
#define _e _i*a==
#define _f(a) C(*(a), a, 0, 0, D)
#define _g ,_**
#define _h (char
#define _i if(
#define _j &&*a!=

typedef _b*_[2];

int Q;

_b C _a,_b(*e)(_*_g _g _g)){ _*f; _i a){ f=1[*a]; e(a,b,c,d); C(f,b,c,d,e); } }

_b D _a){ *b=1[*a]; free(**a); free(a); }

_*E(int a){ _*b=malloc(sizeof(_)); **b=malloc(a); 1[*b]=0; return b; }

_b F _a){ _i!1[*a])1[*a]=*b; }

_b G(_**a,_*b){ _i*a)C(*a,&b,0,0,F); else*a=b; }

_b H(_**a,char b){ _*c=E(2); *_h*)**c=b; 1[_h*)**c]=0; G(a,c); }

_b I(_**a,char*b){ _*c=E(strlen(b)+1); strcpy(**c,b); G(a,c); }

_b J _a){ I(b,**a); }

_b K(_**a _g b){ _f(a); C(*b,a,0,0,J); _f(b); }

_b L _a){ _*e=E(strlen(_h*)c)+strlen(**a)+1); strcpy(**e,_h*)c); strcpy(_h*)**e+strlen(_h*)c),**a); G(b,e); }

_b M _a){ C(*b,c,**a,0,L); }

_b N(int a, int b _g c _g d _g e _g f){ _i a<=b){ _i a==1)C(*c,a==b?d:e,(_**)"",0,L); else C(*f,c,a==b?d:e,0,M); K(f,e); N(++a,b,c,d,e,f); } }

_b O(int a,int b _g c _g d){ _*e=0,*f=0,*g=0; _i a<=b){ _i!a)H(&e,0); N(1,a,c,&e,&f,&g); _f(&g); C(e,d,0,0,J); _f(&e); O(++a,b,c,d); } }

_b P _a){ C(***d,1[**d]?c:b,**a,0,L); }

_b R _a){ _i Q)C(**a,1[*a]?c:b,(_**)"",0,L); else C(*d,b,c,&a,P); Q=0; K(d,c); }

int T _h*a,int*b,int c){ _i!c[a]||(Q=c[a]-48)>=10||Q<0)return c; *b=*b*10+Q; return T(a,b,++c); }

_b U(int a _g b _g c,_b(*d)(int _g _g)){ _i a!=127){ d(a,b,c); U(++a,b,c,d); } }

_b V(int a _g b _g c){ a[_h*)b]=!!c; }

_b W(int a _g b _g c){ _i a[_h*)b])H(c,a); }

_b X _h*a,int*b,char c[127],int d){ _i a[*b]&&a[*b]!=93){ a[(*b)++][c]=!d; X(a,b,c,d); } }

_b Y(int a _g b _g c){ _i a!=10&&a!=13)H(b,a); }

_b B _h*_g,int*);

_b Z _a){ *b=1[*a]; _f((_**)*a); free(a); }

_b A _h*a _g b,int*c){ _*d=0,*e=0; char f[127]; int g=0,h=0,i=0,j=0; _i*a){ _e 40){ _i 1[a]==41){ H(&d,0); g=2; } else{ B(a+1,&d,&g); _i!g++||*(a+g++)!=41)_d; } } else _e 91){ _i a[g+1]==94){ ++g; h=1; } U(0,(_**)f,(_**)h,V); _i a[g+1]==93){ ++g; 93[f]=!h; } X(a+1,&g,f,h); U(0,(_**)f,&d,W); _i!g++||*(a+g++)!=93)_d; } else _e 92){ _i!1[a])_d; H(&d,*(a+1)); g=2; } else _e 46){ U(1,&d,0,Y); g=1; } else _i*a!=46 _j 91 _j 40 _j 41 _j 124 _j 63 _j 123 _j 92){ H(&d,*a); g=1; } } a+=g; _i g){ _e 63){ ++a; ++j; ++g; } else _e 123){ ++a; ++g; h=T(a,&i,0); _i h){ g+=h; a+=h; _e 44){ ++g; ++a; h=T(a,&j,0); _i h){ g+=h; a+=h; _e 125){ ++g; ++a; _i j<i)_d; } else _d; } else _d; } else _e 125){ ++g; ++a; j=i; } else _d; } else _d; } _i h||j){ O(i,j,&d,&e); _f(&d); d=e; } } _i g){ e=malloc(sizeof(_)); **e=d; 1[*e]=0; G(b,e); *c+=g; A(a,b,c); } }

_b B _h*a _g b,int*c){ _*d=0,*e=0,*f=0,*g=0; int h=0; _i*a){ A(a,&e,&h); Q=1; C(e,b,&g,&f,R); _f(&f); C(e,&e,0,0,Z); _e 124)++h; _i!h _j 41)_d; } _i h){ G(b,d); a+=h; *c+=h; B(a,b,c); } }

_b S _a){ _c("R"); _c(**a); _c("\t$@Y\n"); }

int main(int a,char**b){ _*c=0; _i!1[b]||!*(1[b]))_d; B(1[b],&c,&a); _c("S3\n"); C(c,0,0,0,S); _c("R$*\t$@N\n"); _f(&c); exit(0); }
