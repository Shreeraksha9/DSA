//BUBBLE SORT//

#include<stdio.h>
#include<time.h>
void bubblesort(int n,int ar2[n]);
void main()
{
    int i,j;
    int n;
     FILE* fp3,*fp4;
     fp3=fopen("raksha.txt","w");
     fp4=fopen("hello.txt","w");
     time_t t;
     srand((unsigned) time(&t));
     printf("ENTER THE NUMBER OF RANDOM NUMBERS SHOULD GENERATE\n");
     scanf("%d",&n);
     int p=n;
     int ar2[n];


   //generating 100 random numbers//

    for(i=0;i<n;i++)
    {
        ar2[i]=rand()%1000;
        fprintf(fp3,"%d\n",ar2[i]);

    }
     clock_t st,et;
     st=clock();

     bubblesort(n,ar2);

     et=clock();

    double time_taken1 = (double)(et-st);
    fprintf(fp4,"Time taken to generate the sorted random numbers is\t");
    fprintf(fp4,"%lf\n\n",time_taken1);

    //storing the sorted random numbers into a file//
      for(i=0;i<n;i++)
    {
         fprintf(fp4,"%d\n",ar2[i]);
    }



    fclose(fp3);
    fclose(fp4);


}
void bubblesort(int n,int ar2[n])
{
    int i,j;
     int temp=0;

    //sorting the generated random numbers//
     for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
           if(ar2[j]>ar2[j+1])
           {
              temp=ar2[j];
               ar2[j]=ar2[j+1];
               ar2[j+1]=temp;
           }
        }
    }



}
