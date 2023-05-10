//PASCAL'S TRIANGLE//

#include<stdio.h>
#include<time.h>
void pascal(int n,FILE * fp);
main()
{

    int n;
    FILE * fp;
    fp=fopen("raksha.txt","w");
    printf("Enter the number of rows\n");
    scanf("%d",&n);
    pascal(n,fp);

}
void pascal(int n,FILE * fp)
{
    int i,k,j;
     int c=1;
     clock_t st,et;
     printf("The PASCAL'S triangle will be\n");
      st=clock();
    for(i=0;i<n;i++)
    {
        for (k=1;k<n-i;k++)
        {
            printf("  ");
            fprintf(fp,"  ");
        }
            for(j=0;j<=i;j++)
                {
                     if(j==0)
                       c=1;
                     else
                        c=c*(i-j+1)/j;
                        printf("%3d ",c);
                        fprintf(fp,"%3d ",c);
                }
                printf("\n");
                fprintf(fp,"\n");
    }
    et=clock();

    double time_taken1 = (double)(et-st);
    fprintf(fp,"Time taken to generate the PASCAL'S TRIANGLE is\t");
    fprintf(fp,"%lf\n\n",time_taken1);
}
