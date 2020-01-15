#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE * fp = fopen("C:\\schizophrenia\\simple.txt","wt");
    if(fp == NULL){
        puts("open failed!");
        return -1;
    }

    fputc('A',fp);
    fputc('B',fp);
    fputs("My name is Lee \n",fp);
    fputs("Yout name is Dong \n",fp);
    fclose(fp);
    return 0;
}
