#include <stdio.h>

int main(int argc, char const *argv[])
{
    int ch, i;
    FILE * fp = fopen("C:\\schizophrenia\\data.text","rt");
    if(fp == NULL){
        puts("���� ���� ����!");
        return -1;
    }

    for(i=0; i < 3; i++)
    {
        ch = fgetc(fp);
        printf("%c \n", ch);
    }
    fclose(fp);
    return 0;
}
