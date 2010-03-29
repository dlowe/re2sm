#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "re.basic.output.working.h"



void out_destroy(out_list *o) {
    out_list *current = o;
    while (current) {
        o = current->next;
        free(current);
        current = o;
    }
}

out_list *out_new(void) {
    out_list *o = (out_list *)malloc(sizeof(out_list));
    o->output[0] = 0;
    o->next      = NULL;
    return o;
}

void out_char(out_list **o, char c) {
    out_list *current = *o;
    out_list *new     = out_new();

    new->output[0] = c;
    new->output[1] = 0;

    if (! current) {
        *o = new;
    } else {
        while (current->next) {
            current = current->next;
        }
        current->next = new;
    }
}

void out_string(out_list **o, char *s) {
    out_list *current = *o;
    out_list *new     = out_new();

    strcpy(new->output, s);

    if (! current) {
        *o = new;
    } else {
        while (current->next) {
            current = current->next;
        }
        current->next = new;
    }
}

void out_cat(out_list **o, branch_list *b) {
    while (b) {
        out_list *current = b->output;
        while (current) {
            out_string(o, current->output);
            current = current->next;
        }
        b = b->next;
    }
}

out_list *out_numbered(out_list *o, unsigned int n) {
    unsigned int this_index;
    out_list     *current, *i_current;
    out_list     *final_out = NULL;
    out_list     *build_out = NULL;
    out_list     *exist_out = NULL;
    char         buffer[1024];

    for (this_index = 1; this_index <= n; ++this_index) {
        if (this_index == 1) {
            /* loop through atoms */
            i_current = o;
            while (i_current) {
                /* append atom to existing output string (blank) */
                /* if we're at the bottom, store in final_out, otherwise
                   store it in existing strings */
                sprintf(buffer, "%s%s", "", i_current->output);
                if (this_index == n) {
                    out_string(&final_out, buffer);
                } else {
                    out_string(&build_out, buffer);
                }
                i_current = i_current->next;
            }
        } else {
            /* loop through existing output strings */
            current = exist_out;
            while (current) {
                /* loop through atoms */
                i_current = o;
                while (i_current) {
                    /* append atom to existing output string */
                    /* if we're at the bottom, store in final_out, otherwise
                       store it in existing strings */
                    sprintf(buffer, "%s%s", current->output, i_current->output);
                    if (this_index == n) {
                        out_string(&final_out, buffer);
                    } else {
                        out_string(&build_out, buffer);
                    }
                    i_current = i_current->next;
                }
                current = current->next;
            }
        }

        /* store build_out strings in exist_out, and remove build_out */
        out_destroy(exist_out);
        exist_out = NULL;

        current = build_out;
        while (current) {
            out_string(&exist_out, current->output);
            current = current->next;
        }

        out_destroy(build_out);
        build_out = NULL;
    }

    if (exist_out) {
        out_destroy(exist_out);
        exist_out = NULL;
    }

    return final_out;
}

void out_multiplex(out_list **o, unsigned int min, unsigned int max) {
    unsigned int this_count;
    out_list     *current  = NULL;
    out_list     *new      = NULL;
    out_list     *this_out = NULL;

    for (this_count = min; this_count <= max; ++this_count) {
        current = this_out = out_numbered(*o, this_count);
        while (current) {
            out_string(&new, current->output);
            current = current->next;
        }

        out_destroy(this_out);
        this_out = NULL;
    }

    out_destroy(*o);
    *o = new;
}

out_list *out_merge(thing *t) {
    thing    *thing_current = t;
    out_list *out_current   = NULL;
    out_list *exist_current = NULL;
    out_list *final_out     = NULL;
    out_list *exist_out     = NULL;
    out_list *build_out     = NULL;
    char     buffer[1024];

    /* foreach thing */
    while (thing_current) {
        if (thing_current == t) {
            /* foreach output element in the current thing */
            out_current = thing_current->output;
            while (out_current) {
                /* append atom to existing output string (blank) */
                /* if we're at the bottom, store in final_out, otherwise
                   store it in existing strings */
                sprintf(buffer, "%s%s", "", out_current->output);
                if (thing_current->next == NULL) {
                    out_string(&final_out, buffer);
                } else {
                    out_string(&build_out, buffer);
                }
                out_current = out_current->next;
            }
        } else {
            /* foreach existing output element */
            exist_current = exist_out;
            while (exist_current) {
                /* foreach output element in the current thing */
                out_current = thing_current->output;
                while (out_current) {
                    /* append atom to existing output string (blank) */
                    /* if we're at the bottom, store in final_out, otherwise
                       store it in existing strings */
                    sprintf(buffer, "%s%s", exist_current->output,
                            out_current->output);
                    if (thing_current->next == NULL) {
                        out_string(&final_out, buffer);
                    } else {
                        out_string(&build_out, buffer);
                    }
                    out_current = out_current->next;
                }
                exist_current = exist_current->next;
            }
        }
        thing_current = thing_current->next;

        /* store build_out strings in exist_out, and remove build_out */
        out_destroy(exist_out);
        exist_out = NULL;

        exist_current = build_out;
        while (exist_current) {
            out_string(&exist_out, exist_current->output);
            exist_current = exist_current->next;
        }

        out_destroy(build_out);
        build_out = NULL;
    }

    if (exist_out) {
        out_destroy(exist_out);
        exist_out = NULL;
    }

    return final_out;
}

void re_add_branch(re *r, branch_list *b) {
    b->output = out_merge((thing *)(b->pieces));
    if (! r->branches)
        r->branches = b;
    else {
        branch_list *t = r->branches;
        while (t->next)
            t = t->next;
        t->next = b;
    }
}

void branch_add_piece(branch_list *b, piece_list *p) {
    if (! b->pieces)
        b->pieces = p;
    else {
        piece_list *t = b->pieces;
        while (t->next)
            t = t->next;
        t->next = p;
    }
}

void err_die(char *out) {
    printf("error: %s\n", out);
    exit(1);
}

void syn_die(char *out) {
    printf("syntax error: %s\n", out);
    exit(1);
}

int c_is_special(char c) {
    switch (c) {
        /* case '^': case '.': */ case '[': /* case '$': */ case '(':
        case ')': case '|': /* case '*': case '+': */ case '?':
        case '{': case '\\': return 1;
    };
    return 0;
}

unsigned int scan_int(char *s, unsigned int *n) {
    int b, c = 0;
    *n = 0;

    while (s[c] && ((b = s[c++] - '0') < 10) && (b >= 0))
        *n = *n * 10 + b;
    return c - 1;
}

int parse_bracket(char *s, bracket *b, out_list **o) {
    int c = 0;

    if (s[c] == '^') { b->inverted = 1; ++c; }
    if (s[c] == ']') { b->characters[']'] = 1; ++c; }
    while (s[c] && s[c] != ']') {
        out_char(o, s[c]);
        b->characters[(int)s[c]] = 1;
        ++c;
    }
    return c;
}

int parse_bounds(char *s, piece_list *p) {
    int n, num = 0;
    unsigned int n1, n2;

    if (! *s) return 0;

    switch (*s) {
        /* case '+':
            p->bound_min = 1;
            p->bound_max = -1;
            return 1;
        case '*':
            p->bound_min = 0;
            p->bound_max = -1;
            return 1; */
        case '?':
            p->bound_min = 0;
            p->bound_max = 1;
            out_multiplex(&(p->output), 0, 1);
            return 1;
        case '{':
            break;
        default:
            return 0;
    };

    num += 1;
    s += 1;

    n = scan_int(s, &n1);
    if (n) {
        if (n1 > RE_DUP_MAX) syn_die("bad {}: i is too big");
        num += n;
        s += n;
        switch (*s) {
            case ',':
                num += 1;
                s += 1; /* { */
                /* if (*s == '}') {
                    num += 1;
                    s += 1;
                    p->bound_min = n1;
                    p->bound_max = -1;
                    return num;
                } */
                n = scan_int(s, &n2);
                if (n) {
                    if (n2 > RE_DUP_MAX) syn_die("bad {}: j is too big");
                    num += n;
                    s += n; /* { */
                    if (*s == '}') {
                        num += 1;
                        s += 1;
                        if (n2 < n1) syn_die("bad {}: j smaller than i");
                        p->bound_min = n1;
                        p->bound_max = n2;
                        out_multiplex(&(p->output), n1, n2);
                        return num;
                    } else
                        syn_die("bad {}: no closing brace found");
                } else
                    syn_die("bad {}: no j value found"); /* { */
            case '}':
                num += 1;
                s += 1;
                p->bound_min = n1;
                p->bound_max = n1;
                out_multiplex(&(p->output), n1, n1);
                return num;
            default:
                syn_die("bad {}: expected comma or closing brace");
        };
    } else
        syn_die("bad {}: no i value found");

    err_die("impossible");
    return 0;
}

int parse_atom(char *s, piece_list *p) {
    if (! *s) return 0;

    switch (*s) {
        case '(':
            if ((*(s+1)) && (*(s+1) == ')')) {
                p->atom_flags = AFLAG_NULL;
                return 2;
            } else {
                re *r = 0;
                int n;

                r = (re *)malloc(sizeof(re));
                if (! r) err_die("out of memory");

                r->branches = 0;

                n = parse_re(s + 1, r);
                if ((n) && (r->branches) && (*(s + n + 1) == ')')) {
                    p->re = r;
                } else
                    syn_die("sub-expression trouble");
                out_cat(&(p->output), p->re->branches);
                return n + 2;
            }
        case '[': {
            int n;
            bracket *b = 0;

            b = (bracket *)malloc(sizeof(bracket));
            if (! b) err_die("out of memory");

            b->inverted = 0;
            bzero(b->characters, 255);

            n = parse_bracket(s + 1, b, &(p->output));
            if ((n) && (*(s + n + 1) == ']')) {
                p->bracket = b;
            } else
                syn_die("bracket expression trouble");

            return n + 2;
        } case '\\':
            if (! *(s+1))
                syn_die("regexp cannot end in \\");
            out_char(&(p->output), *(s+1));
            p->atom_char = *(s+1);
            return 2;
        /* case '.':
            p->atom_flags = AFLAG_ANY;
            out_char(&(p->output), '.');
            return 1;
        case '^':
            p->atom_flags = AFLAG_ANCHOR_FRONT;
            p->output = out_new();
            out_char(&(p->output), '^');
            return 1;
        case '$':
            p->atom_flags = AFLAG_ANCHOR_REAR;
            out_char(&(p->output), '$');
            return 1; */
        default:
            if (c_is_special(*s)) return 0;
            out_char(&(p->output), *s);
            p->atom_char = *s;
            return 1;
    };
    err_die("cannot happen");
    return 0;
}

int parse_piece(char *s, branch_list *b) {
    int n, num = 0;
    piece_list *p = 0;

    if (! *s) return 0;

    p = (piece_list *)malloc(sizeof(piece_list));
    if (! p) err_die("out of memory");

    p->atom_flags = 0;
    p->atom_char  = 0;
    p->re         = 0;
    p->bracket    = 0;
    p->bound_min  = 1;
    p->bound_max  = 1;
    p->next       = 0;
    p->output     = 0;

    if ((n = parse_atom(s, p))) {
        s += n;
        num += n;
        n = parse_bounds(s, p);
        s += n;
        num += n;
        branch_add_piece(b, p);
    } else {
        free(p);
        return 0;
    }

    return num;
}

int parse_branch(char *s, re *r) {
    int n, num = 0;
    branch_list *b = 0;

    if (! *s) return 0;

    b = (branch_list *)malloc(sizeof(branch_list));
    if (! b) err_die("out of memory");

    b->pieces = 0;
    b->output = 0;
    b->next   = 0;

    while ((n = parse_piece(s, b))) {
        s += n;
        num += n;
    }
    if (*s == '|') num += 1;
    if (num)
        re_add_branch(r, b);
    else if (*s != ')')
        syn_die("branch problem");

    return num;
}

int parse_re(char *s, re *r) {
    int n, num = 0;

    if ((! s) || (! *s))
        syn_die("input string is empty");

    while ((n = parse_branch(s, r))) {
        s += n;
        num += n;
    }
    r->output = out_merge((thing *)(r->branches));

    return num;
}
