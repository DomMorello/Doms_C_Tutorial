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

//     root_item = (**root).item; //root�� item
//     cmpf_result = cmpf(root_item, item); //root�� item�� insert item ��
//     realpp = (int *) root_item;
//     itempp = (int *) item;

//     printf("���� �θ� ��� ������ : %d\n", *realpp);
//     printf("���� �� ��� : %d\n", *itempp);
//     node = btree_create_node(item);
    
//     if (!(*root)){
//         *root = node;
//         return;
//     }
    
//     if (cmpf_result > 1){ //�θ� �� Ŭ�� root�� left�� �̵�
//         printf("���� ���� �̵��մϴ�.");
//         leftNode = (**root).left;
//         btree_insert_data(&leftNode, item, cmpf);
//     } else { //insert item�� �� Ŭ �� root�� right�� �̵�
//         printf("������ ���� �̵��մϴ�.");
//         rightNode = (**root).right;
//         btree_insert_data(&rightNode, item, cmpf);
//     }
// }

void   btree_insert_data(t_btree **root, void *item,
   int (*cmpf)(void *, void *))
{
   if (!*root)
    {
        printf("root�� NULL �Դϴ�! \n");
        *root = btree_create_node(item);
        // printf("item���� �־ ��带 ������. %d \n", *((int *)(*root)->item));
    }
   else if (cmpf((*root)->item, item) > 0)
    {
        printf("root���� item�� �� �۽��ϴ�. �� ������ �̵��մϴ�. \n");
        btree_insert_data(&((*root)->left), item, cmpf);
    }
   else
    {
        printf("root���� item�� �� Ů�ϴ�. ���������� �̵��մϴ�. \n");
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