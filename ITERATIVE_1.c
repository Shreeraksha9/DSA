// FLOYD TRIANGLE//

#include<stdio.h>
#include<time.h>
void floyd(int n,FILE * fp);
main()
{
    FILE * fp;
    fp=fopen("raksha.txt","w");
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    floyd(n,fp);

}
void floyd(int n,FILE * fp)
{
    int i,j;
    int c=1;
    clock_t st,et;
    printf("THE FLOYD TRIANGLE WILL BE\n");
     st=clock();
     for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d ",c);
            fprintf(fp,"%d ",c);
            c++;
        }
        printf("\n");
        fprintf(fp,"\n");
    }

     et=clock();

    double time_taken1 = (double)(et-st);
    fprintf(fp,"Time taken to generate the FLOYD TRIANGLE is\t");
    fprintf(fp,"%lf\n\n",time_taken1);
}

