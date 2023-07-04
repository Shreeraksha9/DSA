#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
};

int max(int a, int b);
int height(struct node* node);
struct node* newNode(int data);
struct node* rightRotate(struct node* y);
struct node* leftRotate(struct node* x);
int getBalance(struct node* node);
struct node* insert(struct node* node, int data);
struct node* deleteNode(struct node* root, int data);
struct node* minValueNode(struct node* node);
void inorder(struct node* root);
void freeTree(struct node* root);
FILE* fp3,*fp4,*fp5,*fp6,*fp7 ,*fp1;
int main()
{
    struct node* root = NULL;
    int choice, data;
    int n,i;
    fp1=fopen("verilog.txt","w");
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


    printf("AVL Tree Operations\n");

    while (1)
    {
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Print inorder traversal\n");
        printf("4. Print preorder traversal\n");
        printf("5. Print postorder traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                for(i=0;i<n;i++)
                         {
                              fscanf(fp3,"%d", &data);
                              root = insert(root, data);


                         }
                         fclose(fp4);
                 break;

            case 2:
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);
                 fprintf(fp1,"DELETED ELEMENT IS :  ");
                fprintf(fp1,"%d ",data);
                root = deleteNode(root, data);
                break;

            case 3:
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

            case 4:
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
            case 5:
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


            case 6:
                freeTree(root);
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct node* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct node* rightRotate(struct node* y)
{
    struct node* x = y->left;
    struct node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct node* leftRotate(struct node* x)
{
    struct node* y = x->right;
    struct node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct node* node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct node* insert(struct node* node, int data)
{
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
    // Duplicate keys are not allowed in AVL tree
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct node* deleteNode(struct node* root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct node* temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            free(temp);
        }
        else
        {
            struct node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(struct node* root)
{
    if (root != NULL)
    {

        inorder(root->left);
       fprintf(fp5,"%d ", root->data);
        inorder(root->right);
    }
}

void freeTree(struct node* root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void preorder(struct node* root)
{
    if (root != NULL)
    {
         fprintf(fp6,"%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
         fprintf(fp7,"%d ", root->data);
    }
}


