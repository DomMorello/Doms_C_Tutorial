#include <stdio.h>

void SoSimpleFunc(void){
    printf("I'm so simple");
}

int main(void)
{
    int num = 20;
    void * ptr;

    ptr = &num; //���� num�� �ּҰ� ����
    printf("%p \n", ptr);

    ptr = SoSimpleFunc; //�Լ� SoSimpleFunc �ּҰ� ����
    printf("%p \n", ptr);
    return 0;
}
