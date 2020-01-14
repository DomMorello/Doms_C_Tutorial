#include <stdio.h>
 
#define MAX_NODE 100
 
typedef struct listNode 
{
    int data;   //그 위치에 들어갈 data 정수값
    struct listNode* prev;  //앞에 있는 listNode를 가리킬 포인터
    struct listNode* next;  //뒤에 있는 listNode를 가리킬 포인터
} ListNode;
 
typedef struct
{
    int use;    //사용하는건지 안 하는건지 알려주는 identifier
    ListNode node;  //노드를 포함한다
} ListNodeHeap;
 
ListNodeHeap heap[MAX_NODE];    //전체 100개의 ListNodeHeap배열
     
void initHeap(void)
{
    int i;
    for (i = 0; i < MAX_NODE; i++)
    {
        heap[i].use = 0;    //전체 ListNodeHeap배열의 맴버변수인 use를 0으로 초기화
    }
}
 
void initListNode(ListNode* node)   //ListNode를 직접 가져와서 변화를 주기위해서 call by refernece
{
    node->data = 0; //매개변수로 받아오는 node가 가리키는 data의 값을 0으로 초기화
    node->prev = node;  //자기 자신을 가리킨다.
    node->next = node;  //자기 자신을 가리킨다.
}
 
ListNode* getListNode(void) //ListNode의 포인터를 반환하는 함수
{
    int i;
    for (i = 0; i < MAX_NODE; i++)  //heap 배열을 처음부터 끝까지 다 검사한다.
    {
        if (!heap[i].use)   //use가 0 일때 실행(사용되지 않는 노드일 때 밑에 코드를 실행)
        {
            heap[i].use = 1;    //사용되지 않는 노드기 때문에 이제는 사용한다. 그래서 1로 바꾼다.
            initListNode(&heap[i].node);    //i번째 heap배열 요소인 ListNodeHeap 안에 있는 node를 초기화한다.
            return &heap[i].node;   //초기화한 그 node를 반환한다.
        }
    }
    return NULL;    //배열이 전부 use 1로 꽉차있는 경우 null을 반환한다. 얻을 수 있는 node가 없다.
}
 
//해당 ListNode를 없앤다.
void destroyListNode(ListNode* node)
{
    ListNodeHeap* heap_node = (ListNodeHeap*)((int*)node - 1);
    heap_node->use = 0;
}
 
//ListNode를 추가한다.
ListNode* appendListNode(ListNode* list, int data)
{
    ListNode* node = getListNode(); //use가 0인 것 중에 최초에 발견되는 node를 가져온다.
    node->data = data;  //그 node에 매개변수로 받아오는 정수값 data를 넣는다. 
    if (list == NULL)
    {
        return node;    //처음에는 첫 번째 위치한 node를 반환할 것임.
    }
    else    //그 다음 부터는 아래 코드를 실행.
    {
        ListNode* last = list->prev;    //last라는 포인터는 list의 prev가 자기 자신을 가리키고 있었기 때문에 last포인터는 결국 전에 넣은 ListNode를 가리킨다.
        last->next = node;  //새로 추가한 node를 가리키게 한다
        list->prev = node;  //새로 추가한 node를 가리키게 한다(circular linked list)
        node->prev = last;  //새로 추가한 node의 prev는 전에 있는 ListNode를 가리키게 한다.
        node->next = list;  //새로 추가한 node의 next는 또 list를 가리키게 한다.
        return list;    //추가한 list를 반환한다. 
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
    scanf("%d", &T);    //testCase 를 입력 받는다.
 
    for (int test_case = 1; test_case <= T; ++test_case)
    {
        ListNode* list = NULL;  //list포인터는 아무곳도 가리키지 않는다.
        ListNode* node; //쓰레기값 저장
        int i;
 
        initHeap(); //전체 ListNodeHeap배열 모든 요소의 use를 0으로 초기화
 
        scanf("%d", &N);    //넣을 데이터 개수 입력 받음.
        for (i = 0; i < N; i++)
        {
            int data;
            scanf("%d", &data); //각각 넣을 data를 입력받음.
            list = appendListNode(list, data);  //처음에는 list에 NULL이 들어가지만 그 이후부터는 전에 넣은 list가 들어간다.
        }
 
        node = list;    //첫 번째 ListNode인 list를 node에 넣어준다.
        while (list != list->next)  //다 없애고 자기 자신을 가리킬 때까지
        {
            ListNode* nextNode = node->next;
            list = removeListNode(list, node);
            node = nextNode->next->next;
        }
 
        printf("#%d %d\n", test_case, list->data);
    }
    return 0;
}