#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef void *_[2];

/* first */
int first;

/* parse_bracket_callback1 */
void parse_bracket_callback1(int a, char * b, _ ** c) {
	a[b] = !!c;
}

/* out_append_callback */
void out_append_callback(_ * a, _ ** b, _ ** c, _ ** d) {
	if (!1[*a]) {
		1[*a] = *b;
	}
}

/* main_callback */
void main_callback(_ * a, _ ** b, _ ** c, _ ** d) {
	printf("R%s\t$@<MATCH>\n", (char *)**a);
}

/* new_thingy */
_ *new_thingy(unsigned int a) {
	_ *b = malloc(sizeof(_));
	if (!b) {
		printf("error\n");
		exit(1);
	}
	**b = malloc(a);
	if (!**b) {
		printf("error\n");
		exit(1);
	}
	1[*b] = 0;
	return b;
}

/* do127c */
void do127c(int a, char *b, _ ** c, void (*d) (int, char *, _ **)) {
    if (a != 127) {
        d(a, b, c);
        do127c(++a, b, c, d);
    }
}

/* do127 */
void do127(int a, _ ** b, _ ** c, void (*d) (int, _ **, _ **)) {
	if (a != 127) {
		d(a, b, c);
		do127(++a, b, c, d);
	}
}

/* walk */
void walk(_ * a, _ ** b, _ ** c, _ ** d, void (*e) (_ *, _ **, _ **, _ **)) {
	_ *f;
	if (a) {
		f = 1[*a];
		e(a, b, c, d);
		walk(f, b, c, d, e);
	}
}

/* walkc */
void walkc(_ * a, _ ** b, char * c, _ ** d, void (*e) (_ *, _ **, char *, _ **)) {
    _ *f;
    if (a) {
        f = 1[*a];
        e(a, b, c, d);
        walkc(f, b, c, d, e);
    }
}

/* out_append */
void out_append(_ ** a, _ * b) {
	if (*a) {
		walk(*a, &b, 0, 0, out_append_callback);
	} else {
		*a = b;
	}
}

/* out_char */
void out_char(_ ** a, int b) {
    if (b != 10 && b != 13) {
	    _ *c = new_thingy(2);
	    *(char *)**c = b;
	    1[(char *)**c] = 0;
	    out_append(a, c);
    }
}

/* parse_bracket_callback2 */
void parse_bracket_callback2(int a, char * b, _ ** c) {
	if (a[b]) {
		out_char(c, a);
	}
}

/* parse_atom_callback */
void parse_atom_callback(int a, _ ** b, _ ** c) {
	out_char(b, a);
}

/* out_string */
void out_string(_ ** a, char *b) {
	_ *c = new_thingy(strlen(b) + 1);
	strcpy(**c, b);
	out_append(a, c);
}

/* out_move_callback */
void out_move_callback(_ * a, _ ** b, _ ** c, _ ** d) {
	out_string(b, **a);
}

/* out_move */
void out_move(_ ** a, _ ** b) {
	*a = 0;
	walk(*b, a, 0, 0, out_move_callback);
	*b = 0;
}

/* parse_bracket_recurse */
void parse_bracket_recurse(char *a, int *b, char c[127], int d) {
	if (a[*b] && a[*b] != 93) {
		a[(*b)++][c] = !d;
		parse_bracket_recurse(a, b, c, d);
	}
}

/* out_mutate_callback */
void out_mutate_callback(_ * a, _ ** b, char * c, _ ** d) {
	_ *e = new_thingy(strlen(c) + strlen(**a) + 1);
	strcpy(**e, c);
	strcpy((char *)**e + strlen(c), **a);
	out_append(b, e);
}

/* out_numbered_callback */
void out_numbered_callback(_ * a, _ ** b, _ ** c, _ ** d) {
	walkc(*b, c, **a, d, out_mutate_callback);
}

/* out_merge_callback_callback */
void out_merge_callback_callback(_ * a, _ ** b, _ ** c, _ ** d) {
	walkc(***d, 1[**d] ? c : b, **a, 0, out_mutate_callback);
}

/* out_merge_callback */
void out_merge_callback(_ * a, _ ** b, _ ** c, _ ** d) {
	if (first) {
		walkc(**a, 1[*a] ? c : b, "", 0, out_mutate_callback);
	} else {
		walk(*d, b, c, &a, out_merge_callback_callback);
	}
	first = 0;
	out_move(d, c);
}

/* out_numbered_recurse */
void out_numbered_recurse(int a, int b, _ ** c, _ ** d, _ ** e, _ ** f) {
	if (a <= b) {
		if (a == 1) {
			walkc(*c, a == b ? d : e, "", 0, out_mutate_callback);
		} else {
			walk(*f, c, a == b ? d : e, 0, out_numbered_callback);
		}
		out_move(f, e);
		out_numbered_recurse(++a, b, c, d, e, f);
	}
}

/* out_multiplex_recurse */
void out_multiplex_recurse(int a, int b, _ ** c, _ ** d) {
	_ *e = 0, *f = 0, *g = 0;
	if (a <= b) {
		if (!a) {
			out_char(&e, 0);
		}
		out_numbered_recurse(1, a, c, &e, &f, &g);
		walk(e, d, 0, 0, out_move_callback);
		out_multiplex_recurse(++a, b, c, d);
	}
}

void parse_re_recurse(char *, _ **, int *);

void parse_branch_recurse(char *a, _ ** b, int *c) {
	_    *d = 0, *e = 0;
	char  f[127];
	int   g = 0, h = 0, i = 0, j = 0;
	if (*a) {
		if (*a == 40) {
			if (1[a] == 41) {
				out_char(&d, 0);
				g = 2;
			} else {
				parse_re_recurse(a + 1, &d, &g);
				if (!g++ || *(a + g++) != 41) {
					printf("error\n");
					exit(1);
				}
			}
		} else if (*a == 91) {
			if (a[g + 1] == 94) {
				++g;
				h = 1;
			}
			do127c(1, f, (_ **) h, parse_bracket_callback1);
			if (a[g + 1] == 93) {
				++g;
				93[f] = !h;
			}
			parse_bracket_recurse(a + 1, &g, f, h);
			do127c(1, f, &d, parse_bracket_callback2);
			if (!g++ || *(a + g++) != 93) {
				printf("error\n");
				exit(1);
			}
		} else if (*a == 92) {
			if (!1[a]) {
				printf("error\n");
				exit(1);
			}
			out_char(&d, *(a + 1));
			g = 2;
		} else if (*a == 46) {
			do127(1, &d, 0, parse_atom_callback);
			g = 1;
		} else if (*a != 46 && *a != 91 && *a != 40 && *a != 41 && *a != 124 && *a != 63 && *a != 123 && *a != 92) {
			out_char(&d, *a);
			g = 1;
		}
	}
	a += g;
    h = 0;
	if (g) {
		if (*a == 63) {
			++a;
			++j;
			++g;
		} else if (*a == 123) {
			++a;
			++g;
			sscanf(a, "%d%n", &i, &h);
			if (h) {
				g += h;
				a += h;
				if (*a == 44) {
					++g;
					++a;
					sscanf(a, "%d%n", &j, &h);
					if (h) {
						g += h;
						a += h;
						if (*a == 125) {
							++g;
							++a;
							if (j < i) {
								printf("error\n");
								exit(1);
							}
						} else {
							printf("error\n");
							exit(1);
						}
					} else {
						printf("error\n");
						exit(1);
					}
				} else if (*a == 125) {
					++g;
					++a;
					j = i;
				} else {
					printf("error\n");
					exit(1);
				}
			} else {
				printf("error\n");
				exit(1);
			}
		}
		if (h || j) {
			out_multiplex_recurse(i, j, &d, &e);
			d = e;
		}
	}
	if (g) {
		e = malloc(sizeof(_));
		if (!e) {
			printf("error\n");
			exit(1);
		}
		**e = d;
		1[*e] = 0;
		out_append(b, e);
		*c += g;
		parse_branch_recurse(a, b, c);
	}
}

/* parse_re_recurse */
void parse_re_recurse(char *a, _ ** b, int *c) {
	_   *d = 0, *e = 0, *f = 0, *g = 0;
	int  h = 0;
	if (*a) {
		parse_branch_recurse(a, &e, &h);
		first = 1;
		walk(e, b, &g, &f, out_merge_callback);
		if (*a == 124) {
			++h;
		}
		if (!h && *a != 41) {
			printf("error\n");
			exit(1);
		}
	}
	if (h) {
		out_append(b, d);
		a += h;
		*c += h;
		parse_re_recurse(a, b, c);
	}
}

int main(int a, char **b) {
	_ *c = 0;
	if (!1[b] || !*(1[b])) {
		printf("error\n");
		exit(1);
	}
	parse_re_recurse(1[b], &c, &a);
	printf("S3\n");
	walk(c, 0, 0, 0, main_callback);
	printf("R$*\t$@<NOMATCH>\n");
	exit(0);
}
