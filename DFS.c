#include<stdio.h>
#include<stdlib.h>
int visited[7]={0,0,0,0,0,0,0};
int arr[7][7]={
        {0,1,1,1,0,0,1},
        {1,0,1,0,0,1,0},
        {1,1,0,0,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,0,1},
        {0,1,0,1,1,0,0}
    };
void dfs(int i)
{
    int j;
    printf("%d",i);
    visited[i]=1;
    for(j=0;j<7;j++)
    {
        if(arr[i][j]==1&&visited[j]==0)
        {
            dfs(j);
        }
    }
}
int main()
{
    int n;
    printf("enter the node of the graph from which you want to start dfs traversal : ");
    scanf("%d",&n);
    dfs(n);
    return 0;
}

