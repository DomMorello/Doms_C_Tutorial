#include <stdio.h>

typedef struct listNode 
{
    int data;   //그 위치에 들어갈 data 정수값
    struct listNode* prev;  //앞에 있는 listNode를 가리킬 포인터
    struct listNode* next;  //뒤에 있는 listNode를 가리킬 포인터
} ListNode;

int main(int argc, char const *argv[])
{
    ListNode* list = NULL;  //list포인터는 아무곳도 가리키지 않는다.
    ListNode* node;

    printf("%p \n", list);
    printf("%p \n", node);

    return 0;
}
