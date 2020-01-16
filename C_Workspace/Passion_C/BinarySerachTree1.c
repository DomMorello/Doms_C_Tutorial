#include <stdio.h>
#include <stdlib.h>

/*** 
 2가지 버전의 이진탐색트리 탐색 알고리즘
 ***/

typedef struct TreeNode
{
    int key;
    struct TreeNode * left;
    struct TreeNode * right;
} TreeNode;

/* circular version */
TreeNode *search1(TreeNode *node, int key)
{
    //찾고자 하는 값을 찾아봤는데 아예 없었을 경우
    //혹은 애초에 node 자체가 NULL이었을 경우
    if(!node)
        return NULL;
    
    //순환으로 탐색 중 원하는 값을 찾았을 때
    if(key == node->key)
        return node;    //해당 노드의 주소를 반환

    //찾는 값보다 루트키값이 작은 경우
    else if(key > node->key)
        search1(node->right, key);  //오른쪽 서브트리로 이동
    
    //찾는 값보다 루트키값이 큰 경우
    else
        search1(node->left, key);   //왼쪽 서브트리로 이동
}

/* repeating version */
TreeNode *search2(TreeNode *node, int key)
{
    /* 찾고자 하는 값을 찾아봤는데 아예 없었을 경우
    혹은 애초에 node자체가 NULL이었을 경우 while문 탈출 */
    
    while(node) //node가 NULL이 아니라면 일단 탐색을 계속한다.
    {
        if(key == node->key)
            return node;
        //찾고자 하는 값보다 루트키값이 더 큰 경우
        else if(key < node->key)
            node = node->left;   //왼 쪽 서브트리로 이동
        //찾고자 하는 값보다 루트키값이 더 작은 경우
        else
            node = node->right; //오른쪽 서브트리로 이동
    }
    return NULL;
}

/*** 
 이진탐색트리 삽입 알고리즘
 ***/

typedef struct TreeNode
{
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

//key를 이진탐색트리 root에 삽입한다.
//key가 이미 root안에 있으면 삽입하지 않는다.
void insert_node(TreeNode **root, int key)
{
    //t는 탐색을 위한 포인터이다.
    TreeNode *parent;   //부모노드를 가리키는 포인터
    TreeNode *current;    //현재 노드 포인터
    TreeNode *new;  //새로운 노트 포인터

    current = *root;    //처음 시작시 현재 노드는 root 그 자체
    parent = NULL;  //root의 부모노드는 없다. 

    //탐색을 먼저 수행
    while(current)
    {
        if(key == current->key)
            return;

        parent = current;   //부모 노드를 현재 노드로 설정한다. 새로운 루트노드
        //서브트리의 새로운 루트노드가 등장하는 것과 같은 원리

        if(key < parent->key)
            current = parent->left; //현재 노드는 부모의 왼 쪽 서브트리가 된다.
        else
            current = parent->right;    //현재 노드는 부모늬 오른쪽 서브트리가 된다.
    }
    //key가 트리 안에 없으므로 삽입이 가능하다.

    //새로 삽입될 노드를 생성한다.
    new = (TreeNode*)malloc(sizeof(TreeNode));
    if(!new)
        return; //동적할당 실패했을 경우 return
    
    //데이터를 복사한다.
    if(parent)  //부모노드가 존재할 경우
    {
        if(key < parent->key)
            parent->left = new;
        else
            parent->right = new;
    }
    else    //부모 노드가 없으니 새로 생긴 노드가 루트노드가 된다.
        *root = new;
}
