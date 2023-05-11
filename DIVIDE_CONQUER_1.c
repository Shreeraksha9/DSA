#include<stdio.h>
#include<stdlib.h>
#include<time.h>
FILE *fp,*fp1;
int main()
{

    fp=fopen("raksha.txt","w");
     fp1=fopen("hello.txt","w");
    int a[1000];
    int ch,n;
    clock_t st,et;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    generateinput(a,n);
    st=clock();
    quicksort(a,0,n-1);

     printf("Quick Sort\n");
     displayarray(a,n);
     et=clock();

    double time_taken1 = (double)(et-st);
    fprintf(fp1,"\nTime taken to generate the sorted random numbers is\t");
    fprintf(fp1,"%lf\n\n",time_taken1);
}
void generateinput(int a[1000],int n)
{
    int i;
    time_t t;
    srand(time(&t));
    for(i=0;i<n;i++)
    {
         a[i]=rand()%1000;
         fprintf(fp,"%d ",a[i]);
    }



}
void displayarray(int a[1000],int n)
{
    int i;
    for(i=0;i<n;i++)
    {

        fprintf(fp1,"%d ",a[i]);
    }
    printf("\n");

}

int quicksort(int a[1000],int l,int h)
{
    if(l<h)
    {
    int temp;
    int pivot=a[l];
    int i=l;
    int j=h;
    while(i<j)
    {

        while(a[i]<=pivot)
            i++;


        while(a[j]>pivot)
        j--;
        if(i<j)
        {
            temp=a[i];
                a[i]=a[j];
                a[j]=temp;
        }




    }
    temp=a[l];
    a[l]=a[j];
    a[j]=temp;
    quicksort(a,l,j);
    quicksort(a,i+1,h);
}
}
