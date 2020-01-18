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

int compare(void *a, void *b)
{
    return *((int *)a) - *((int *)b);
}

// void btree_insert_data(t_btree ** root, void * item, int (*cmpf)(void *, void *))
// {   
//     t_btree * leftNode;
//     t_btree * rightNode;
//     t_btree * node;
//     int cmpf_result;
//     void * root_item;
//     int * realpp;
//     int * itempp;

//     root_item = (**root).item; //root의 item
//     cmpf_result = cmpf(root_item, item); //root의 item과 insert item 비교
//     realpp = (int *) root_item;
//     itempp = (int *) item;

//     printf("현재 부모 노드 아이템 : %d\n", *realpp);
//     printf("삽입 할 노드 : %d\n", *itempp);
//     node = btree_create_node(item);
    
//     if (!(*root)){
//         *root = node;
//         return;
//     }
    
//     if (cmpf_result > 1){ //부모가 더 클때 root의 left로 이동
//         printf("왼쪽 노드로 이동합니다.");
//         leftNode = (**root).left;
//         btree_insert_data(&leftNode, item, cmpf);
//     } else { //insert item이 더 클 때 root의 right로 이동
//         printf("오른쪽 노드로 이동합니다.");
//         rightNode = (**root).right;
//         btree_insert_data(&rightNode, item, cmpf);
//     }
// }

void   btree_insert_data(t_btree **root, void *item,
   int (*cmpf)(void *, void *))
{
   if (!*root)
    {
        printf("root가 NULL 입니다! \n");
        *root = btree_create_node(item);
        // printf("item값을 넣어서 노드를 생성함. %d \n", *((int *)(*root)->item));
    }
   else if (cmpf((*root)->item, item) > 0)
    {
        printf("root보다 item이 더 작습니다. 왼 쪽으로 이동합니다. \n");
        btree_insert_data(&((*root)->left), item, cmpf);
    }
   else
    {
        printf("root보다 item이 더 큽니다. 오른쪽으로 이동합니다. \n");
        btree_insert_data(&((*root)->right), item, cmpf);
    }
}

int main(int argc, char const *argv[])
{
    t_btree root;
    t_btree *proot = NULL;
    t_btree **pproot = &proot;

    int a = 10;
    int b = 7;
    int c = 13;

    // printf("%p \n", root);
    // printf("%p \n", proot);
    // printf("%p \n", pproot);

    btree_insert_data(pproot, &a, compare);
    btree_insert_data(pproot, &b, compare);
    btree_insert_data(pproot, &c, compare);

    
    return 0;
}