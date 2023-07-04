#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* insert(struct node* root, int data);
FILE* fp3,*fp4,*fp5,*fp6,*fp7 ;
int main()
{
    struct node* root = NULL;
    int choice, data;
    int n,i;
    fp3=fopen("raksha.txt","w");
     fp4=fopen("hello.txt","w");
     fp5=fopen("positive.txt","w");
     fp6=fopen("bcd.txt","w");
     fp7=fopen("abc.txt","w");
     time_t t;
      srand((unsigned) time(&t));
    printf("ENTER THE NUMBER\n");
    scanf("%d",&n);
      int ar2[n];


    for(i=0;i<n;i++)
    {
        ar2[i]=rand()%100;
        fprintf(fp3,"%d\n",ar2[i]);
    }
    printf("\n");
     fclose(fp3);
      fp3=fopen("raksha.txt","r");


    printf("Binary Search Tree Insertion\n");

    while(1)
    {

        printf("1. Insert a node\n");
        printf("2. Print inorder traversal\n");
        printf("3. print preorder traversal\n");
        printf("4. print postorder traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice)
         {
            case 1:
                         for(i=0;i<n;i++)
                         {
                              fscanf(fp3,"%d", &data);
                              root = insert(root, data);
                              fprintf(fp4,"%d ",data);

                         }
                         fclose(fp4);
                 break;
            case 2:
                if(root==NULL)
                {
                      printf("TREE IS EMPTY\n");
                }
                else
                {
                     fprintf(fp5,"Inorder Traversal:  ");
                     inorder(root);
                     fprintf(fp5,"\n");
                }
                fclose(fp5);

                break;

            case 3:
                if(root==NULL)
                {
                    printf("TREE IS EMPTY\n");
                }
                else
                {
                    fprintf(fp6,"preorder Traversal:  ");
                    preorder(root);
                    fprintf(fp6,"\n");
                }
                fclose(fp6);
                break;

            case 4:
                if(root==NULL)
                {
                    printf("TREE IS EMPTY\n");
                }
                else
                {
                    fprintf(fp7,"postorder Traversal:  ");
                    postorder(root);
                    fprintf(fp7,"\n");
                }
                fclose(fp7);
                break;


            case 5:
                 exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }


    return 0;
}


struct node* newnode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        fprintf(fp5,"%d ", root->data);
        inorder(root->right);
    }
}

struct node* insert(struct node* root, int data)
{
    if (root == NULL)
        return newnode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        fprintf(fp6,"%d ", root->data);
        preorder(root->left);
        preorder(root->right);

    }
}
void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        fprintf(fp7,"%d ", root->data);

    }
}

