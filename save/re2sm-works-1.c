#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef void *_[2];
int A;
void B(int a, char *b, _**c) {
 a[b] = !!c; 
}
_*T(unsigned int a) {
 _*b = malloc(sizeof(_));
 if (!b) {
  printf("error\n"); exit(1);
 }
 **b = malloc(a);
 if (!**b) {
  printf("error\n"); exit(1);
 }
 1[*b] = 0;
 return b;
}
void P(_*a, _**b, _**c, _**d, void (*e)(_*a, _**b, _**c, _**d)) {
 _*f;
 if (a) {
  f = 1[*a];
  e(a, b, c, d);
  P(f, b, c, d, e);
 }
}
void G(_*a, _**b, _**c, _**d) {
 if (!1[*a]) {
  1[*a] = *b;
 }
}
void J(_**a, _*b) {
 if (*a) {
  P(*a, &b, 0, 0, G);
 } else {
  *a = b;
 }
}
void K(_**a, char *b) {
 _*c = T(strlen(b) + 1);
 strcpy(**c, b);
 J(a, c);
}
void C(_*a, _**b, _**c, _**d) {
 K(b, **a);
}
void S(_*a, _**b, char *c) {
 if (a) {
  _*d = 1[*a];
  _*e = T(strlen(c) + strlen(**a) + 1);
  strcpy(**e, c);
  strcpy((char *)**e + strlen(c), **a);
  J(b, e);
  S(d, b, c);
 }
}
void D(_*a, _**b, _**c, _**d) {
 S(*b, c, **a);
}
void M(_**a, int b) {
 if (b != 10 && b != 13) {
  _*c = T(2);
  *(char *)**c = b;
  1[(char *)**c] = 0;
  J(a, c);
 }
}
void E(int a, char *b, _**c) {
 if (a[b]) {
  M(c, a);
 }
}
void F(_**a, _**b) {
 *a = 0;
 P(*b, a, 0, 0, C);
 *b = 0;
}
void H(int a, _**b) {
 if (a != 127) {
  M(b, a);
  H(++a, b);
 }
}
void I(_*a, _**b, _**c, _**d) {
 S(***d, 1[**d] ? c : b, **a);
}
void L(_*a, _**b, _**c, _**d) {
 printf("R%s\t$@<MATCH>\n", (char *)**a);
}
void N(int a, char *b, _**c, void (*d)(int a, char *b, _**c)) {
 if (a != 127) {
  d(a, b, c);
  N(++a, b, c, d);
 }
}
void O(_*a, _**b, _**c, _**d) {
 if (A) {
  S(**a, 1[*a] ? c : b, "");
 } else {
  P(*d, b, c, &a, I);
 }
 A = 0;
 F(d, c);
}
void Q(char *a, _**b, int *c, char d[127], int e) {
 if (a[*c] && a[*c] != 93 && a[*c] > 0) {
  a[(*c)++][d] = !e;
  Q(a, b, c, d, e);
 }
}
void U(int a, int b, _**c, _**d, _**e, _**f) {
 if (a <= b) {
  if (a == 1) {
   S(*c, a == b ? d : e, "");
  } else {
   P(*f, c, a == b ? d : e, 0, D);
  }
  F(f, e);
  U(++a, b, c, d, e, f);
 }
}
void R(int a, int b, _**c, _**d) {
 _*e = 0, *f = 0, *g = 0;
 if (a <= b) {
  if (!a) {
   M(&e, 0);
  }
  U(1, a, c, &e, &f, &g);
  P(e, d, 0, 0, C);
  R(++a, b, c, d);
 }
}
void W(char *a, _**b, int *c);
void V(char *a, _**b, int *c) {
 _*d = 0, *e = 0;
 char f[127];
 int g = 0, h = 0, i = 0, j = 0;
 if (*a) {
  if (*a == 40) {
   if (1[a] == 41) {
    M(&d, 0);
    g = 2;
   } else {
    W(a + 1, &d, &g);
    if (!g++ || *(a + g++) != 41) {
     printf("error\n"); exit(1);
    }
   }
  } else if (*a == 91) {
   if (a[g + 1] == 94) {
    ++g;
    h = 1;
   }
   N(1, f, (_**) h, B);
   if (a[g + 1] == 93) {
    ++g;
    93[f] = !h;
   }
   Q(a + 1, 0, &g, f, h);
   N(1, f, &d, E);
   if (!g++ || *(a + g++) != 93) {
    printf("error\n"); exit(1);
   }
  } else if (*a == 92) {
   if (1[a] < 1 || 1[a] == 10 || 1[a] == 13) {
    printf("error\n"); exit(1);
   }
   M(&d, *(a + 1));
   g = 2;
  } else if (*a == 46) {
   H(1, &d);
   g = 1;
  } else if (*a > 0 && *a != 10 && *a != 13 && *a != 41 && *a != 63 && *a != 123 && *a != 124) {
   M(&d, *a);
   g = 1;
  }
 }
 a += g;
 h = 0;
 if (g) {
  if (*a == 63) {
   ++a;
   ++g;
   ++j;
  } else if (*a == 123) {
   ++a;
   ++g;
   sscanf(a, "%d%n", &i, &h);
   if (!h || i < 0) {
    printf("error\n"); exit(1);
   }
   g += h;
   a += h;
   if (*a != 44 && *a != 125) {
    printf("error\n"); exit(1);
   }
   if (*a == 44) {
    ++a;
    ++g;
    sscanf(a, "%d%n", &j, &h);
    if (!h) {
     printf("error\n"); exit(1);
    }
    g += h;
    a += h;
    if (*a != 125) {
     printf("error\n"); exit(1);
    }
    ++a;
    ++g;
    if (j < i) {
     printf("error\n"); exit(1);
    }
   } else {
    ++a;
    ++g;
    j = i;
   }
  }
  if (h || j) {
   R(i, j, &d, &e);
   d = e;
  }
 }
 if (g) {
  e = T(1);
  **e = d;
  1[*e] = 0;
  J(b, e);
  *c += g;
  V(a, b, c);
 }
}
void W(char *a, _**b, int *c) {
 _*d = 0, *e = 0, *f = 0, *g = 0;
 int h = 0;
 if (*a) {
  V(a, &e, &h);
  A = 1;
  P(e, b, &g, &f, O);
  if (*a == 124) {
   ++h;
  }
  if (!h && *a != 41) {
   printf("error\n"); exit(1);
  }
 }
 if (h) {
  J(b, d);
  a += h;
  *c += h;
  W(a, b, c);
 }
}
int main(int a, char **b) {
 _*c = 0;
 if (!1[b] || !*(1[b])) {
  printf("error\n"); exit(1);
 }
 W(1[b], &c, &a);
 printf("S3\n");
 P(c, 0, 0, 0, L);
 printf("R$*\t$@<NOMATCH>\n");
 exit(0);
}
