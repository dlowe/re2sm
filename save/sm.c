#include <string.h>
#include <stdio.h>
#include "re.basic.output.working.h"
#include "sm.h"

void sm_deparse_bracket(bracket *b, char *s) {
}

void sm_deparse_piece(piece_list *p, int n, char *s) {
    int i;

    for (i = 1; i <= n; ++i) {
        switch (p->atom_flags) {
            case AFLAG_NULL:         continue;
            case AFLAG_ANCHOR_FRONT: strncat(s, "^", 1);
                                     continue;
            case AFLAG_ANCHOR_REAR:  strncat(s, "$", 1);
                                     continue;
            case AFLAG_ANY:          strncat(s, ".", 1);
                                     continue;
        }
        if (p->atom_char) {
            strncat(s, &(p->atom_char), 1);
        } else if (p->re) {
            sm_deparse_re(p->re, s);
        } else if (p->bracket) {
            sm_deparse_bracket(p->bracket, s);
        }
    }
}

void sm_deparse_pieces(piece_list *p, char *s) {
    int i;
    char save[2048];

    if (! p) {
        if (*s) {
            printf("'%s'\n", s);
        } else {
            printf("''\n");
        }
        return;
    }
    for (i = p->bound_min; i <= p->bound_max; ++i) {
        strcpy(save, s);
        sm_deparse_piece(p, i, s);
        sm_deparse_pieces(p->next, s);
        strcpy(s, save);
    }
}

void sm_deparse_re(re *r, char *s) {
    branch_list *bt = r->branches;

    while (bt) {
        sm_deparse_pieces(bt->pieces, s);
        bt = bt->next;
    }
}
