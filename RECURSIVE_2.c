//SUM OF CUBES//

#include<stdio.h>
int main()
{
    int m,n,s;
    printf("ENTER THE NUMBER\n");
    scanf("%d",&n);
    s=sum(n);
    printf("THE SUM OF CUBES %d IS\n",n);
    printf("%d ",s);
    return 0;
}
int sum(int n)
{
    if(n==0)
    return 0;
    else
        return n*n*n+sum(n-1);

}
