#include <stdio.h>
#define MAX_N 100

int front;
int rear;
int queue[MAX_N];

void queueInit(void)
{
    front = 0;
    rear = 0;
}

int queueIsEmpty(void)
{
    return (front == rear);
}
 
int queueIsFull(void)
{
    if ((rear + 1) % MAX_N == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int queueEnqueue(int value)
{
    if (queueIsFull())
    {
        printf("queue is full!");
        return 0;
    }
    queue[rear] = value;
    rear++;
    if (rear == MAX_N)
    {
        rear = 0;   //배열에 꽉 차면 rear를 0으로 초기화
    }

    return 1;
}

int queueDequeue(int *value)
{
    if (queueIsEmpty())
    {
        printf("queue is empty!");
        return 0;
    }
    *value = queue[front];
    front++;
    if (front == MAX_N)
    {
        front = 0;
    }
    return 1;
}

int main(int argc, char* argv[])
{
    int T;  
    int N;

    scanf("%d", &T);    //testcase 몇 번 실험해볼지 입력받는다.

    for (int test_case = 1; test_case <= T; test_case++)
    {
        scanf("%d", &N);    //큐에 몇 개를 넣을지

        queueInit();    //새로운 테스트를 할 때마다 queue를 초기화. front rear를 0으로 초기화
        for (int i = 0; i < N; i++)
        {
            int value;
            scanf("%d", &value);
            queueEnqueue(value);
            printf("setValue");
        }

        printf("#%d ", test_case);

        while (!queueIsEmpty())
        {
            int value;
            if (queueDequeue(&value) == 1)
            {
                printf("%d ", value);
            }
        }
        printf("\n");
    }
    return 0;
}