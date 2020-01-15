#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[30];
    int ch;
    FILE * fp = fopen("C:\\schizophrenia\\simple.txt","rt");
    if(fp == NULL){
        puts("open failed!");
        return -1;
    }

    ch = fgetc(fp);
    printf("%c \n", ch);
    ch = fgetc(fp);
    printf("%c \n", ch);

    fgets(str, sizeof(str), fp);
    printf("%s", str);
    fgets(str, sizeof(str), fp);
    printf("%s", str);

    fclose(fp);
    return 0;
}
