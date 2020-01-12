#include <stdio.h>

int main(void)
{
    int ch;

    while(1){
        ch = getchar();
        if(ch == EOF){  //Ctrl + z 입력시 반복문 빠져나옴.
            break;
        }
        putchar(ch);
    }
    return 0;
}
