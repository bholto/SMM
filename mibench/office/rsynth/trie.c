#include <config.h>
/* $Id: trie.c,v 1.13 1994/11/08 13:30:50 a904209 Exp a904209 $
 */
char *trie_id = "$Id: trie.c,v 1.13 1994/11/08 13:30:50 a904209 Exp a904209 $";
#include <useconfig.h>
#include <stdio.h>
#include "proto.h"
#include "trie.h"

struct trie_s
 {
  struct trie_s *otherwise;
  struct trie_s *more;
  void *value;
  char ch;
 };

void
trie_insert(r, s, value)
trie_ptr *r;
char *s;
void *value;
{
    trie_ptr p = NULL;
    char ch;
    while ((ch = *s++))
    {
        int stop_inner_while_loop = 0;
        while ((p = *r) && stop_inner_while_loop == 0)
        {
            if (p->ch == ch)
                stop_inner_while_loop = 1;
            else
                r = &p->otherwise;
        }
        if (!p)
        {
            p = (trie_ptr) malloc(sizeof(*p));
            memset(p, 0, sizeof(*p));
            p->ch = ch;
            *r = p;
        }
        r = &p->more;
    }
    p->value = value;
}

void *
trie_lookup(r, sp)
trie_ptr *r;
char **sp;
{
    char *s = *sp;
    char *value = NULL;
    char ch;
    int stop_outer_while_loop = 0;
    while ((ch = *s) && stop_outer_while_loop == 0)
    {
        trie_ptr *l = r;
        trie_ptr p;
        int stop_inner_while_loop = 0;
        while ((p = *l) && stop_inner_while_loop == 0)
        {
            if (p->ch == ch)
                stop_inner_while_loop = 1;
            else
                l = &p->otherwise;
        }
        if (p)
        {
            *l = p->otherwise;
            p->otherwise = *r;
            *r = p;
            r = &p->more;
            value = (char *) p->value;
            s++;
        }
        else
        {
            stop_outer_while_loop = 1;
        }
    }
    *sp = s;
    return value;
}
