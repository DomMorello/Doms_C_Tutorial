#include <stdio.h>

int main(void)
{
    int * ptr1 = 0x0010;
    double * ptr2 = 0x0010; //�������� �ʱ�ȭ

    printf("%p %p \n", ptr1 + 1, ptr1 + 2); //4�� �����ϰ� 8�� �����Ѵ�.
    printf("%p %p \n", ptr2 + 1, ptr2 + 2); //8�� �����ϰ� 16�� �����Ѵ�.

    printf("%p %p \n", ptr1, ptr2);
    ptr1++; //4����
    ptr2++; //8����
    printf("%p %p \n", ptr1, ptr2);
    return 0;
}
