#include <stdio.h>

typedef struct listNode 
{
    int data;   //�� ��ġ�� �� data ������
    struct listNode* prev;  //�տ� �ִ� listNode�� ����ų ������
    struct listNode* next;  //�ڿ� �ִ� listNode�� ����ų ������
} ListNode;

int main(int argc, char const *argv[])
{
    ListNode* list = NULL;  //list�����ʹ� �ƹ����� ����Ű�� �ʴ´�.
    ListNode* node;

    printf("%p \n", list);
    printf("%p \n", node);

    return 0;
}
