#include <stdio.h>

int main(void)
{
    char str1[] = "My String";  //���� ������ ���ڿ�
    char * str2 = "Your String";    //��� ������ ���ڿ�
    printf("%s %s \n", str1, str2);

    str2 = "Our String";    //����Ű�� ��� ����
    printf("%s %s \n", str1, str2);

    str1[0] = 'X';  //���ڿ� ���� ����!
    str2[0] = 'X';  //���ڿ� ���� ����!
    printf("%s %s \n", str1, str2);
    return 0;
}