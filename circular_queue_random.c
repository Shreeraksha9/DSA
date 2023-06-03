#include<stdio.h>
#define max 5
int Q[max];
int f,r;
FILE* fp3,*fp4,*fp5,*fp6,*fp7 ;
int main()
{
     f=-1;
     r=-1;
    int ch;
    int data,n,i,ele;
    fp3=fopen("raksha.txt","w");
     fp4=fopen("hello.txt","w");
     fp5=fopen("positive.txt","w");
     fp6=fopen("bcd.txt","w");
     fp7=fopen("abc.txt","w");
      time_t t;
      srand((unsigned) time(&t));
    printf("Enter the element\n");
        scanf("%d",&n);
        int ar2[n];

    for(i=0;i<n;i++)
    {
        ar2[i]=rand()%1000;
        fprintf(fp3,"%d\n",ar2[i]);

    }
   fclose(fp3);
      fp3=fopen("raksha.txt","r");
    while(1)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("Exit\n");

    printf("enter the choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 : if((r+1)%max==f)
                {
                        printf("circular Queue is Full\n");

                }
                else
                {

                        fscanf(fp3,"%d", &data);
                         printf("inserted element %d into the queue",data);
                 Insert(data);
                fprintf(fp4,"INSERTED ELEMENT %d \n",data);
                 fprintf(fp6,"INSERT\n");


                }
                break;

        case 2 :


                     delete();
                     fprintf(fp6,"DELETE\n");


                 break;

        case 3 : if(f==-1&&r==-1)
                   {
                       printf("circular Queue is empty\n");
                   }
                else
                    display();
                    break;
        case 4 : exit(0);
        default : printf("Invalid Choice\n");
    }
    }
}

void Insert(int ele)
{
    if(f==-1&&r==-1)
    {
        f=(f+1)%max;
        r=(r+1)%max;
        Q[r]=ele;

    }
    else
    {
         r=(r+1)%max;
        Q[r]=ele;

    }
}

void delete()
{
    if(f==-1&&r==-1)
    {
        printf("circular Queue is empty\n");

    }
    else
    {
        if(f==r)
        {
            printf("Element deleted = %d \n",Q[f]);
            fprintf(fp4,"DELETED ELEMENT %d \n",Q[f]);
            f=-1;
            r=-1;
        }
        else
        {
            printf("Element deleted = %d \n",Q[f]);
            fprintf(fp4,"DELETED ELEMENT %d \n",Q[f]);
             f=(f+1)%max;

        }
    }
}

void display()
{
    int i;
    for(i=f;i!=r;i=(i+1)%max)
    {
         printf("%d ",Q[i]);
          fprintf(fp4,"%d\n",Q[i]);
    }
      printf("%d ",Q[i]);
          fprintf(fp4,"%d\n",Q[i]);
     fprintf(fp4,"\n");

}


