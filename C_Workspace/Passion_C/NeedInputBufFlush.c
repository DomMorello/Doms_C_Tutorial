#include <stdio.h>

void ClearLineFromReadBuffer(void){
    while(getchar() != '\n');
}

int main(void)
{
    char perID[7];
    char name[10];

    fputs("�ֹι�ȣ �� 6�ڸ� �Է�: ", stdout);
    fgets(perID, sizeof(perID), stdin);
    ClearLineFromReadBuffer();  //�Է¹��� ����

    fputs("�̸� �Է�: ", stdout);
    fgets(name, sizeof(name), stdin);

    printf("�ֹι�ȣ: %s \n", perID);
    printf("�̸�: %s \n", name);
    return 0;
}
