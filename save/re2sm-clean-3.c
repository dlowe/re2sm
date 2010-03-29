#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef void *_[2];
int A;
void B(int a, char *b, _**c) {
 a[b] = !!c;
}
void G(_*a, _**b, _**c, _**d) {
 if (!1[*a]) {
  1[*a] = *b;
 }
}
void R(_*a, _**b, _**c, _**d, void(*e)(_*a, _**b, _**c, _**d)) {
 _*f;
 if (a) {
  f = 1[*a];
  e(a, b, c, d);
  R(f, b, c, d, e);
 }
}
void I(_**a, _*b) {
 if (*a) {
  R(*a, &b, 0, 0, G);
 } else {
  *a = b;
 }
}
_*W(unsigned int a) {
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
void K(_**a, char *b) {
 _*c = W(strlen(b) + 1);
 strcpy(**c, b);
 I(a, c);
}
void C(_*a, _**b, _**c, _**d) {
 K(b, **a);
}
void D(_**a, _**b) {
 *a = 0;
 R(*b, a, 0, 0, C);
 *b = 0;
}
void L(_**a, int b) {
 if (b != 10 && b != 13) {
  _*c = W(2);
  *(char *)**c = b;
  1[(char *)**c] = 0;
  I(a, c);
 }
}
void E(int a, char *b, _**c) {
 if (a[b]) {
  L(c, a);
 }
}
void S(_*a, _**b, char *c, void(*d)(_*a, _**b, char *c)) {
 _*e;
 if (a) {
  e = 1[*a];
  d(a, b, c);
  S(e, b, c, d);
 }
}
void T(_*a, _**b, char *c) {
 _*e = W(strlen(c) + strlen(**a) + 1);
 strcpy(**e, c);
 strcpy((char *)**e + strlen(c), **a);
 I(b, e);
}
void F(_*a, _**b, _**c, _**d) {
 S(*b, c, **a, T);
}
void H(int a, _**b) {
 L(b, a);
}
void J(_*a, _**b, _**c, _**d) {
 S(***d, 1[**d] ? c : b, **a, T);
}
void M(_*a, _**b, _**c, _**d) {
 printf("R%s	$@<MATCH>\n", (char *)**a);
}
void N(int a, _**b, void(*c)(int a, _**b)) {
 if (a != 127) {
  c(a, b);
  N(++a, b, c);
 }
}
void O(int a, char *b, _**c, void(*d)(int a, char *b, _**c)) {
 if (a != 127) {
  d(a, b, c);
  O(++a, b, c, d);
 }
}
void P(char *a, int *b, char c[127], int d) {
 if (a[*b] && a[*b] != 93) {
  a[(*b)++][c] = !d;
  P(a, b, c, d);
 }
}
void Q(_*a, _**b, _**c, _**d) {
 if (A) {
  S(**a, 1[*a] ? c : b, "", T);
 } else {
  R(*d, b, c, &a, J);
 }
 A = 0;
 D(d, c);
}
void V(int a, int b, _**c, _**d, _**e, _**f) {
 if (a <= b) {
  if (a == 1) {
   S(*c, a == b ? d : e, "", T);
  } else {
   R(*f, c, a == b ? d : e, 0, F);
  }
  D(f, e);
  V(++a, b, c, d, e, f);
 }
}
void U(int a, int b, _**c, _**d) {
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
void Y(char *a, _**b, int *c);
void X(char *a, _**b, int *c) {
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
    if (!g++ || *(a + g++) != 41) {
     printf("error\n"); exit(1);
    }
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
   P(a + 1, &g, f, h);
   O(1, f, &d, E);
   if (!g++ || *(a + g++) != 93) {
    printf("error\n"); exit(1);
   }
  } else if (*a == 92) {
   if (!1[a]) {
    printf("error\n"); exit(1);
   }
   L(&d, *(a + 1));
   g = 2;
  } else if (*a == 46) {
   N(1, &d, H);
   g = 1;
  } else if (*a != 46 && *a != 91 && *a != 40 && *a != 41 && *a != 124 && *a != 63 && *a != 123 && *a != 92) {
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
   if (h) {
    g += h; a += h;
    if (*a == 44) {
     ++a; ++g;
     sscanf(a, "%d%n", &j, &h);
     if (h) {
      g += h; a += h;
      if (*a == 125) {
       ++a; ++g;
       if (j < i) {
        printf("error\n"); exit(1);
       }
      } else {
       printf("error\n"); exit(1);
      }
     } else {
      printf("error\n"); exit(1);
     }
    } else if (*a == 125) {
     ++a; ++g;
     j = i;
    } else {
     printf("error\n"); exit(1);
    }
   } else {
    printf("error\n"); exit(1);
   }
  }
  if (h || j) {
   U(i, j, &d, &e);
   d = e;
  }
 }
 if (g) {
  e = malloc(sizeof(_));
  if (!e) {
   printf("error\n"); exit(1);
  }
  **e = d;
  1[*e] = 0;
  I(b, e);
  *c += g;
  X(a, b, c);
 }
}
void Y(char *a, _**b, int *c) {
 _*d = 0, *e = 0, *f = 0, *g = 0;
 int h = 0;
 if (*a) {
  X(a, &e, &h);
  A = 1;
  R(e, b, &g, &f, Q);
  if (*a == 124) {
   ++h;
  }
  if (!h && *a != 41) {
   printf("error\n"); exit(1);
  }
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
 if (!1[b] || !*(1[b])) {
  printf("error\n"); exit(1);
 }
 Y(1[b], &c, &a);
 printf("S3\n");
 R(c, 0, 0, 0, M);
 printf("R$*	$@<NOMATCH>\n");
 exit(0);
}
