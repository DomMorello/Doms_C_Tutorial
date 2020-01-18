#include "ft_btree.h"
#include <stdio.h>
#include <stdlib.h>

t_btree *btree_create_node(void *item)
{
    t_btree *node;

    if(!(node = (t_btree*)malloc(sizeof(node))))
        return (NULL);
    node->item = item;
    node->right = 0;
    node->left = 0;
    return (node);
}

void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
    
}