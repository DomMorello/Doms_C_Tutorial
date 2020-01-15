#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE * fp = fopen("C:\\schizophrenia\\data.text","wt");
    if(fp == NULL){
        puts("파일 오픈 실패!");
        return -1;  //비정상 종료
    }

    fputc('A', fp);
    fputc('B', fp);
    fputc('C', fp);
    fclose(fp);
    return 0;
}
