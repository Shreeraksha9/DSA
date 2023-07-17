#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int * arr;
    int front;
    int rear;
    int size;
};
void enqueue(struct queue *q,int item)
{
    if(q->rear==q->size-1)
    {
      printf("queue is full");
    }
    else
    {
        q->rear++;
        q->arr[q->rear]=item;
    }

}
int dequeue(struct queue *q)
{
    int item;
    if(isqempty(&q))
    {
        printf("queue is empty");
    }
    else
    {
        q->front++;
        item=q->arr[q->front];
    }

    return item;
}
int isqempty(struct queue *q)
{
    if(q->front==-1&&q->rear==-1)
        return 1;
    else
        return 0;
}

int main()
{
    struct queue q;
    q.size=400;
    q.front=q.rear=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));
    int u,j;
    int i=0;
    int visited[7]={0,0,0,0,0,0,0};
    int arr[7][7]={
        {1,0,1,0,0,1,0},
        {1,0,1,0,0,1,0},
        {0,1,1,0,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,1,0}
    };
    printf("%d",i);
    visited[i]=1;
    enqueue(&q,i);
    while(!isqempty(&q))
    {
        int u=dequeue(&q);
        for(j=0;j<7;j++)
        {
            if(arr[u][j]==1&&visited[j]==0)
            {
                printf("%d",j);
                visited[j]=1;
                enqueue(&q,j);



            }
        }
    }
    return 0;

}
