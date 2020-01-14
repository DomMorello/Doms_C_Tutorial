#include <stdio.h>
 
#define MAX_NODE 100
 
typedef struct listNode 
{
    int data;   //�� ��ġ�� �� data ������
    struct listNode* prev;  //�տ� �ִ� listNode�� ����ų ������
    struct listNode* next;  //�ڿ� �ִ� listNode�� ����ų ������
} ListNode;
 
typedef struct
{
    int use;    //����ϴ°��� �� �ϴ°��� �˷��ִ� identifier
    ListNode node;  //��带 �����Ѵ�
} ListNodeHeap;
 
ListNodeHeap heap[MAX_NODE];    //��ü 100���� ListNodeHeap�迭
     
void initHeap(void)
{
    int i;
    for (i = 0; i < MAX_NODE; i++)
    {
        heap[i].use = 0;    //��ü ListNodeHeap�迭�� �ɹ������� use�� 0���� �ʱ�ȭ
    }
}
 
void initListNode(ListNode* node)   //ListNode�� ���� �����ͼ� ��ȭ�� �ֱ����ؼ� call by refernece
{
    node->data = 0; //�Ű������� �޾ƿ��� node�� ����Ű�� data�� ���� 0���� �ʱ�ȭ
    node->prev = node;  //�ڱ� �ڽ��� ����Ų��.
    node->next = node;  //�ڱ� �ڽ��� ����Ų��.
}
 
ListNode* getListNode(void) //ListNode�� �����͸� ��ȯ�ϴ� �Լ�
{
    int i;
    for (i = 0; i < MAX_NODE; i++)  //heap �迭�� ó������ ������ �� �˻��Ѵ�.
    {
        if (!heap[i].use)   //use�� 0 �϶� ����(������ �ʴ� ����� �� �ؿ� �ڵ带 ����)
        {
            heap[i].use = 1;    //������ �ʴ� ���� ������ ������ ����Ѵ�. �׷��� 1�� �ٲ۴�.
            initListNode(&heap[i].node);    //i��° heap�迭 ����� ListNodeHeap �ȿ� �ִ� node�� �ʱ�ȭ�Ѵ�.
            return &heap[i].node;   //�ʱ�ȭ�� �� node�� ��ȯ�Ѵ�.
        }
    }
    return NULL;    //�迭�� ���� use 1�� �����ִ� ��� null�� ��ȯ�Ѵ�. ���� �� �ִ� node�� ����.
}
 
//�ش� ListNode�� ���ش�.
void destroyListNode(ListNode* node)
{
    ListNodeHeap* heap_node = (ListNodeHeap*)((int*)node - 1);
    heap_node->use = 0;
}
 
//ListNode�� �߰��Ѵ�.
ListNode* appendListNode(ListNode* list, int data)
{
    ListNode* node = getListNode(); //use�� 0�� �� �߿� ���ʿ� �߰ߵǴ� node�� �����´�.
    node->data = data;  //�� node�� �Ű������� �޾ƿ��� ������ data�� �ִ´�. 
    if (list == NULL)
    {
        return node;    //ó������ ù ��° ��ġ�� node�� ��ȯ�� ����.
    }
    else    //�� ���� ���ʹ� �Ʒ� �ڵ带 ����.
    {
        ListNode* last = list->prev;    //last��� �����ʹ� list�� prev�� �ڱ� �ڽ��� ����Ű�� �־��� ������ last�����ʹ� �ᱹ ���� ���� ListNode�� ����Ų��.
        last->next = node;  //���� �߰��� node�� ����Ű�� �Ѵ�
        list->prev = node;  //���� �߰��� node�� ����Ű�� �Ѵ�(circular linked list)
        node->prev = last;  //���� �߰��� node�� prev�� ���� �ִ� ListNode�� ����Ű�� �Ѵ�.
        node->next = list;  //���� �߰��� node�� next�� �� list�� ����Ű�� �Ѵ�.
        return list;    //�߰��� list�� ��ȯ�Ѵ�. 
    }
}
 
ListNode* removeListNode(ListNode* list, ListNode* node)
{
    if (list == list->next)
    {
        destroyListNode(node);
        return NULL;
    }
    else
    {
        ListNode* prev = node->prev;
        ListNode* next = node->next;
        prev->next = next;
        next->prev = prev;
        destroyListNode(node);
        return (list == node) ? next : list;
    }
}
 
int main(int argc, char* argv[])
{
 
    int T, N;
 
    setbuf(stdout, NULL);
    scanf("%d", &T);    //testCase �� �Է� �޴´�.
 
    for (int test_case = 1; test_case <= T; ++test_case)
    {
        ListNode* list = NULL;  //list�����ʹ� �ƹ����� ����Ű�� �ʴ´�.
        ListNode* node; //�����Ⱚ ����
        int i;
 
        initHeap(); //��ü ListNodeHeap�迭 ��� ����� use�� 0���� �ʱ�ȭ
 
        scanf("%d", &N);    //���� ������ ���� �Է� ����.
        for (i = 0; i < N; i++)
        {
            int data;
            scanf("%d", &data); //���� ���� data�� �Է¹���.
            list = appendListNode(list, data);  //ó������ list�� NULL�� ������ �� ���ĺ��ʹ� ���� ���� list�� ����.
        }
 
        node = list;    //ù ��° ListNode�� list�� node�� �־��ش�.
        while (list != list->next)  //�� ���ְ� �ڱ� �ڽ��� ����ų ������
        {
            ListNode* nextNode = node->next;
            list = removeListNode(list, node);
            node = nextNode->next->next;
        }
 
        printf("#%d %d\n", test_case, list->data);
    }
    return 0;
}