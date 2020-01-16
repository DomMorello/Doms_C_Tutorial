#include <stdio.h>
 
#define MAX_NODE_NUM 10000
#define MAX_CHILD_NUM 2
 
//node 구조체
typedef struct
{
    int parent;
    int child[MAX_CHILD_NUM];
} TreeNode;

//node배열 10000개 
TreeNode tree[MAX_NODE_NUM];

int nodeNum;    //노드개수
int edgeNum;    //간선개수
int root;   //루트노드 번호
 
void initTree(void) 
{
    int i;
    int j;
    for (i = 0; i <= nodeNum; i++)
    {
        tree[i].parent = -1;    //입력받은 노드 전부를 -1로 초기화
        for (j = 0; j < MAX_CHILD_NUM; j++)
        {
            tree[i].child[j] = -1;  //자식도 -1로 초기화
        }
    }
}
 //11 13
void addChild(int parent, int child) 
{
    int i;
    for (i = 0; i < MAX_CHILD_NUM; i++)
    {
        if (tree[parent].child[i] == -1)
        {
            break;
        }
    }
    tree[parent].child[i] = child;
    tree[child].parent = parent;
}
 
int getRoot(void) 
{
    int i;
    int j;
    for (i = 1; i <= nodeNum; i++) 
    {
        if (tree[i].parent == -1) 
        {
            return i;
        }
    }
    return -1;
}
 
void preOrder(int root) 
{
    int i;
    int child;
    printf("%d ", root);
 
    for (i = 0; i < MAX_CHILD_NUM; i++) 
    {
        child = tree[root].child[i];
        if (child != -1)
        {
            preOrder(child);
        }
    }
}
 
int main(void)
{
    int test_case;
    int T;
    int i;
    int parent;
    int child;
 
    scanf("%d", &T);
 
    for (test_case = 1; test_case <= T; ++test_case) 
    {
        scanf("%d %d", &nodeNum, &edgeNum);
 
        initTree(); //tree 초기화
 
        for (i = 0; i < edgeNum; i++)
        {
            scanf("%d %d", &parent, &child);
            addChild(parent, child);
        }
 
        root = getRoot();
 
        printf("#%d ", test_case);
        preOrder(root);
        printf("\n");
    }
 
    return 0;
}