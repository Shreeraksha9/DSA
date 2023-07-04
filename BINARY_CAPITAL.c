#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct node
{
    char data;
    struct node* left;
    struct node* right;
};
struct node* insert(struct node* root, char data);
FILE* fp3,*fp4,*fp5,*fp6,*fp7 ;
int main()
{
    struct node* root = NULL;
    int choice, data;
    int n,i;
    int p=1;
    fp3=fopen("raksha.txt","w");
     fp4=fopen("hello.txt","w");
     fp5=fopen("positive.txt","w");
     fp6=fopen("bcd.txt","w");
     fp7=fopen("abc.txt","w");
     time_t t;
      srand((unsigned) time(&t));
    printf("ENTER THE NUMBER\n");
    scanf("%d",&n);
      char ar2[n];


    for(i=0;i<n;i++)
    {
        ar2[i]='A' + rand()%26;
        fprintf(fp3,"%c",(ar2[i]));
    }
    printf("\n");
     fclose(fp3);
      fp3=fopen("raksha.txt","r");

      for(i=0;i<n;i++)
    {
        fscanf(fp3,"%c", &(data));
        root = insert(root, (data));
        fprintf(fp4,"%c",data);

    }


        fprintf(fp5,"Inorder Traversal:  ");
                     inorder(root);
                     fprintf(fp5,"\n");


        fprintf(fp6,"preorder Traversal:  ");
                    preorder(root);
                    fprintf(fp6,"\n");

        fprintf(fp7,"postorder Traversal:  ");
                    postorder(root);
                    fprintf(fp7,"\n");
}
struct node* newnode(char item)
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
        fprintf(fp5,"%c ", root->data);
        inorder(root->right);
    }
}

struct node* insert(struct node* root, char data)
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
        fprintf(fp6,"%c ", root->data);
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
        fprintf(fp7,"%c ", root->data);

    }
}


