#include <stdio.h>

void SwapIntPtr(int *p1, int *p2){
    int * tmp = p1;
    p1 = p2;
    p2 = tmp;
}

int main(void)
{
    int num1 = 10, num2 = 20;
    int *ptr1, *ptr2;
    ptr1 = &num1, ptr2 = &num2; //ptr1, ptr2�� ���� num1 �� num2�� ����Ų��.
    printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2); //10, 20

    SwapIntPtr(ptr1, ptr2); //�Լ��� ���� p1�� num2�� ����Ű�� p2�� num1�� ����Ų��. ������ ptr1�� ptr2�� ������ ����.
    printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2); //10, 20 ����ߴ� ȿ���� 20, 10 �̾����� �߸�§ �ڵ��̴�.
    return 0;
}
