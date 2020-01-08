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
    ptr1 = &num1, ptr2 = &num2; //ptr1, ptr2가 각각 num1 과 num2를 가리킨다.
    printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2); //10, 20

    SwapIntPtr(ptr1, ptr2); //함수를 통해 p1은 num2를 가리키고 p2는 num1을 가리킨다. 하지만 ptr1과 ptr2는 변함이 없다.
    printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2); //10, 20 기대했던 효과는 20, 10 이었지만 잘못짠 코드이다.
    return 0;
}
