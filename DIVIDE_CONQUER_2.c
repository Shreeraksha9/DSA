#include<stdio.h>
#include<stdlib.h>
#include<time.h>
FILE *fp,*fp1;
int a[1000],c[1000];
  int ch,n;
int l=0;
int h;
int main()
{

    fp=fopen("raksha.txt","w");
     fp1=fopen("hello.txt","w");
     clock_t st,et;
    printf("Enter number of elements\n");
    scanf("%d",&n);
       h=n-1;
    readarray(a,n);

    st=clock();
    mergeSort(a,0,n-1);
     printf("Quick Sort\n");
     displayarray(a,n);
     et=clock();

    double time_taken1 = (double)(et-st);
    fprintf(fp1,"\nTime taken to generate the sorted random numbers is\t");
    fprintf(fp1,"%lf\n\n",time_taken1);
}
void mergeSort(int a[1000], int p, int r)
{
    if (p<r)
    {
        int q=(p+r)/2;
        mergeSort(a,p,q);
        mergeSort(a,q+1,r);
        merge(a,p,q,r);
    }
}
void merge(int a[1000],int p,int q, int r)
{
    int i, j, k;
    int leftside=q-p+1;
    int rightside=r-q;
    int Leftarray[leftside], Rightarray[rightside];

    for (i = 0; i < leftside; i++)
    {
         Leftarray[i]=a[p+i];
    }

    for (j = 0; j < rightside; j++)
    {
         Rightarray[j]=a[q+1+j];
    }

    i=0;
    j=0;
    k=p;
    while (i <leftside && j < rightside)
    {
        if (Leftarray[i] <= Rightarray[j])
        {
            a[k] = Leftarray[i];
            i++;
        }
        else
        {
            a[k] = Rightarray[j];
            j++;
        }
        k++;
    }
    while (i < leftside)
    {
        a[k] = Leftarray[i];
        i++;
        k++;
    }
    while (j < rightside)
    {
        a[k] = Rightarray[j];
        j++;
        k++;
    }
}
void displayarray(int a[1000],int n)
{
    int i;
    for(i=0;i<n;i++)
        fprintf(fp1,"%d\t",a[i]);
}

void readarray(int a[1000],int n)
{
    int i;
    time_t t;
    srand(time(&t));
    for(i=0;i<n;i++)
        a[i]=rand()%1000;
}




