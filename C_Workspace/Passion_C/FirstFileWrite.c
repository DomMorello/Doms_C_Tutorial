#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE * fp = fopen("C:\\schizophrenia\\data.text","wt");
    if(fp == NULL){
        puts("���� ���� ����!");
        return -1;  //������ ����
    }

    fputc('A', fp);
    fputc('B', fp);
    fputc('C', fp);
    fclose(fp);
    return 0;
}
