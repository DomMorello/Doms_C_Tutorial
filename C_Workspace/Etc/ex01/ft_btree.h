#ifndef FT_BTREE_H
#define FT_BTREE_H

t_btree *btree_create_node(void *item);

typedef struct      s_btree
{
    struct s_btree  *left;
    struct s_btree  *right;
    void            *item;
}                   t_btree;

#endif