//PATTERN PRINTING USING RECUSION WITH TIME T(N)=T(N-1)+N//

#include<stdio.h>
FILE * fp;
int main()
{

    fp=fopen("raksha.txt","w");
    int n;
    printf("ENTER THE NUMBER\n");
    scanf("%d",&n);
    pattern(n);
    fclose(fp);

}
void pattern(int n)
{
    int i;
     if(n==0)
    {
       ;
    }
    else
    {
        for(i=1;i<=n;i++)
           {
               fprintf(fp,"%d ",i*n);
           }
           fprintf(fp,"\n");
           pattern(n-1);


    }
}
