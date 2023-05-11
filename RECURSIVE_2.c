//FIBONACCI SERIES //

#include<stdio.h>
FILE * fp;
int main()
{

    int i;
    int n;
    fp=fopen("raksha.txt","w");
    printf("ENTER THE NUMBER\n");
    scanf("%d",&n);
    fprintf(fp,"THE FIBONACCI SERIES WILL BE\n");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d ",fibonacci(i));
    }
    fclose(fp);
}
int fibonacci(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
        else
            return fibonacci(n-1)+fibonacci(n-2);
}
