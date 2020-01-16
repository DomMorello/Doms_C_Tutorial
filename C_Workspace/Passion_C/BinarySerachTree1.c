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

/*** 
 이진탐색트리 삭제 알고리즘
 ***/

void delete_node(TreeNode **root, int key)
{
	TreeNode *parent, *child, *suc, *suc_p, *t;

	// key를 갖는 노드 t를 탐색한다. parent는 t의 부모노드다.
	parent = NULL; // 시초가 되는 root의 부모는 없다.
	t = *root;

	// key를 갖는 노드 t를 탐색한다.
	while (t != NULL && t->key != key)
	{
		parent = t; // 부모를 t값과 동일하게 준 후 t를 통해 탐색한다.
					// t는 왼쪽이나 key값에 따라 왼쪽이나 오른쪽으로 내려간다.
		t = (key < parent->key) ? parent->left : parent->right;
	}

	// 탐색이 끝난 시점에서 만약 키 값이 트리에 없었다면 t는 NULL일 것이다.
	if (!t)
	{
		printf("key is not in the tree");
		return; // 원하는 값이 없으므로 return 한다.
	}
	// 위에서 탐색을 못했을 경우를 다뤘기 때문에 이 아래부터는 탐색이
	// 성공적으로 이루어졌다는 가정 하에 경우의 수를 따진다.

	// 첫 번째: 단말노드였을 경우
	if (t->left == NULL && t->right == NULL)
	{
		if (parent) // 부모 노드가 NULL이 아닐 때, 즉 존재할 때
		{
			if (parent->left == t)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else // 부모 노드가 NULL 이라면, 삭제하려는 노드가 루트 노드다.
			*root = NULL;
	}
	// 두 번째: 하나의 서브트리만 가지는 경우
	else if ((t->left == NULL) || (t->right == NULL))
	{
		child = (t->left != NULL) ? t->left : t->right;
		if (parent)
		{
			if (parent->left == t)
				parent->left = child;
			else
				parent->right = child;
		}
		else // 부모 노드가 NULL이라면 삭제되는 노드가 루트노드다.
			*root = child;
	}
	// 세 번째: 두개의 서브트리를 모두 가지는 경우
	else
	{
		// 오른쪽 서브트리에서 가장 작은 값을 찾는다.
		suc_p = t;
		suc = t->right;
		while (suc->left != NULL)
		{
			suc_p = suc;
			suc = suc->left;
		}
		// 후속자의 부모와 자식을 연결
		if (suc_p->left == suc)
			suc_p->left = suc->right;
		// 왼쪽 끝까지 내려왔지만 그 끝에 오른쪽 서브트리가 있을 수도 있는데,
		// 이 경우를 대비해 suc->right 값을 대입하는 것이다.
		// 그림을 그려 보면 편하다. 포스팅에 그림을 첨부하겠다.

		else
			suc_p->right = suc->right;

		// 아래 두 개의 문장을 실행하는 이유는 무엇일까?
		// 포스팅에 자세히 풀어 설명해보았다.
		t->key = suc->key;
		t = suc;
	}
	free(t);
}