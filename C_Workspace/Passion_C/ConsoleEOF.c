#include <stdio.h>

int main(void)
{
    int ch;

    while(1){
        ch = getchar();
        if(ch == EOF){  //Ctrl + z �Է½� �ݺ��� ��������.
            break;
        }
        putchar(ch);
    }
    return 0;
}
