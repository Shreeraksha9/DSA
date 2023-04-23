#include<stdio.h>
#include<time.h>
struct node
{
    int data;
    struct node *next;
};
 FILE* fp3,*fp4,*fp5,*fp6;
struct node * head,* temp,* temp1,*temp2,* newnode;
struct node*Insert_node_beg(struct node * newnode);
int count_nodes(struct node * head);
struct node*Insert_node_beg(struct node * newnode);
void sort(struct node * head,int n);
void display(struct node * head,int n);


void main()
{
    int i,j;
    int n;
     int c;

     time_t t;
     srand((unsigned) time(&t));


     fp3=fopen("raksha.txt","w");
     fp4=fopen("hello.txt","w");
     fp5=fopen("abc.txt","w");
     fp6=fopen("bcd.txt","w");
     printf("enter the number of elements to be generated\n");
     scanf("%d",&n);
     clock_t st,et,st2,et2,st3,et3,st4,et4;

     st=clock();


   //generating 100 random numbers//

    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=rand();
        head=Insert_node_beg(newnode);
        fprintf(fp3,"%d\n",head->data);
        c=count_nodes(head);

    }
    et=clock();

    double time_taken1 = (double)(et-st);
    fprintf(fp6,"Time taken to generate the random numbers is\t\t\t\t");
    fprintf(fp6,"%lf\n\n",time_taken1);

      st2=clock();

      //sorting the generated random numbers//

         sort(head,n);

          et2=clock();

    double time_taken = (double)(et2-st2);
    fprintf(fp6,"Time taken to execute the sorting of random numbers is\t\t");
    fprintf(fp6,"%lf\n\n\n",time_taken);

    //display the sorted random numbers //

         display(head,n);

















}

struct node*Insert_node_beg(struct node * newnode)
{
    if(head==NULL)
    {
        head=newnode;
        head->next=NULL;

    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
    return(head);
}

void sort(struct node * head,int n)
{

    struct node* temp;
    struct node * temp1;
    int i,j;
if(head==NULL)
    {
        printf("linked list is empty\n");

    }
    else
    {
        if(head->next==head)
        {
            return(head);
        }


      else
        {


            temp1=(struct node * )malloc(sizeof(struct node));

    for(i=0;i<n;i++)
    {
         temp=head;
        for(j=0;j<n-i-1;j++)
        {
            if(temp->data>temp->next->data)
            {
                temp1->data=temp->data;
                temp->data=temp->next->data;
                temp->next->data=temp1->data;

            }
            temp=temp->next;

        }
        }


}
    }

}



void display(struct node * head,int n)
{

    clock_t st3,et3,st4,et4;
    if(head==NULL)
    {
        printf("Singly linked list is empty\n");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {

            fprintf(fp4,"%d->",temp->data);
            temp=temp->next;

        }

   //splitting the sorted linked list into 100's group//



          int p=n/100;
          int p1=n%100;

          printf("The number of group of 100's will be\n");
          printf("%d\n",p);
          printf("The remaining numbers except 100's group is\n");
          printf("%d\n",p1);
         int i=0;
        int  j=1;
          temp=head;
           st3=clock();
          while(p)
          {
                 fprintf(fp5,"The %d's group is\n\n",100*(p-(p-j)));

              for(i=i;i<100*(p-(p-j))&i<n;i++)
              {


            fprintf(fp5,"%d->",temp->data);
            temp=temp->next;

        }


              et3=clock();

    double time_taken5= (double)(et3-st3);
    fprintf(fp6,"Time taken to generate the %d group is\t\t\t\t\t",100*(p-(p-j)));
    fprintf(fp6,"%lf\n",time_taken5);

    j++;
              p--;
           fprintf(fp5,"\n\n\n");


          }

      st4=clock();

          if(p1!=0)
          {
              fprintf(fp5,"The remaining %d's group is\n\n",p1);
              for(i=i;i<100*(p1-(p1-j))&i<n;i++)
              {

             fprintf(fp5,"%d->",temp->data);
            temp=temp->next;

              }
              j++;
              p--;
           fprintf(fp5,"\n\n\n");

          }
          }
           et4=clock();
           int p1=n%100;
    double time_taken3 = (double)(et4-st4);
    fprintf(fp6,"Time taken to generate the remaining %d group is\t\t\t",p1);
    fprintf(fp6,"%lf\n",time_taken3);



      }





int count_nodes(struct node * head)
{
    int count=0;
if(head==NULL)
    {
         printf("Number of nodes is zero\n");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return(count);
    }
}
