#ifndef _RE_H
#define _RE_H

#define RE_DUP_MAX 255

typedef struct PIECE_LIST  piece_list;
typedef struct BRANCH_LIST branch_list;
typedef struct RE          re;
typedef struct BRACKET     bracket;
typedef struct OUTPUT      out_list;
typedef struct THING       thing;

struct THING {
    out_list    *output;
    thing       *next;
};

struct RE {
    out_list    *output;
    branch_list *branches;
};

struct BRANCH_LIST {
    out_list    *output;
    branch_list *next;
    piece_list  *pieces;
};

struct PIECE_LIST {
    out_list     *output;
    piece_list   *next;
    unsigned int atom_flags;
    char         atom_char;
    re           *re;
    bracket      *bracket;
    unsigned int bound_min;
    unsigned int bound_max;
};

struct BRACKET {
    char inverted;
    char characters[255];
};

struct OUTPUT {
    char     output[1024];
    out_list *next;
};

#define AFLAG_NULL         1
#define AFLAG_ANY          2
#define AFLAG_ANCHOR_FRONT 3
#define AFLAG_ANCHOR_REAR  4

void re_add_branch(re *r, branch_list *b);
void branch_add_piece(branch_list *b, piece_list *p);
void err_die(char *out);
void syn_die(char *out);
int c_is_special(char c);
unsigned int scan_int(char *s, unsigned int *n);
int parse_bracket(char *s, bracket *b, out_list **o);
int parse_bounds(char *s, piece_list *p);
int parse_atom(char *s, piece_list *p);
int parse_piece(char *s, branch_list *b);
int parse_branch(char *s, re *r);
int parse_re(char *s, re *r);

#endif /* _RE_H */
