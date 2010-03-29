#include <stdio.h>

/* XX: A single atom MUST be either all non-tokenizing chars, or a single
       tokenizing char ***** */
/* XX: '.' will have to mean all non-tokenizing chars */
/* XX: do '^' and '$' mean anything? */

#include "re.basic.output.working.h"

void deparse_re(re *r) {
    branch_list *bt = r->branches;
    out_list    *ot = r->output;

    while (bt) {
        piece_list *pt = bt->pieces;

        printf("Branch:\n");
        while (pt) {
            out_list *ot = pt->output;

            printf("  Piece: bound_min  = %d\n", pt->bound_min);
            printf("         bound_max  = %d\n", pt->bound_max);
            if (pt->atom_char) {
                printf("         atom_char  = %c\n", pt->atom_char);
            } else if (pt->atom_flags) {
                printf("         atom_flags = %d\n", pt->atom_flags);
            } else if (pt->re) {
                printf("---- start sub regex ---\n");
                deparse_re(pt->re);
                printf("---- end sub regex -----\n");
            } else if (pt->bracket) {
                int i;

                printf("         atom_group = ");
                if (pt->bracket->inverted)
                    printf("^");
                for (i = 0; i < 255; ++i)
                    if (pt->bracket->characters[i])
                        printf("%c", i);
                printf("\n");
            }

            while (ot) {
                printf("    OUTPUT = %s\n", ot->output);
                ot = ot->next;
            }

            pt = pt->next;
        }

        bt = bt->next;
    }

    while (ot) {
        printf("OUTPUT = %s\n", ot->output);
        ot = ot->next;
    }
}

int main(int argc, char **argv) {
    re r;
    r.branches = 0;
    r.output   = 0;

    parse_re(argv[1], &r);
    printf("syntax ok.\n");
    deparse_re(&r);

    exit(0);
}
