#include<stdio.h>
#include<stdlib.h>

struct node
{
    int num;
    struct node *prev;
    struct node *next;
    int height;
};

void preOrder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->num);
        preOrder(root->prev);
        preOrder(root->next);
    }
}

int Search(int key, struct node *root)
{
    int i=0;
    if(root==NULL)
        return i;
    if(key>root->num)
        return Search(key,root->next);
    else if(key<root->num)
        return Search(key,root->prev);
    else
        i=1;

    return i;
}

struct node* newNode(int key)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->num = key;
    node->prev = NULL;
    node->next = NULL;
    node->height = 1;
    return(node);
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->prev;
    struct node *z = x->next;
    x->next = y;
    y->prev = z;
    y->height = max(height(y->prev), height(y->next))+1;
    x->height = max(height(x->prev), height(x->next))+1;

    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->next;
    struct node *z = y->prev;
    y->prev = x;
    x->next = z;
    x->height = max(height(x->prev), height(x->next))+1;
    y->height = max(height(y->prev), height(y->next))+1;

    return y;
}

int max(int a, int b);

int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->prev) - height(N->next);
}

struct node* insert(struct node *node, int key)
{
    if (node == NULL)
        return(newNode(key));

    if (key < node->num)
        node->prev  = insert(node->prev, key);
    else
        node->next = insert(node->next, key);

    node->height = max(height(node->prev), height(node->next)) + 1;

    int balance = getBalance(node);

    if (balance > 1 && key < node->prev->num)
        return rightRotate(node);

    if (balance < -1 && key > node->next->num)
        return leftRotate(node);

    if (balance > 1 && key > node->prev->num)
    {
        node->prev =  leftRotate(node->prev);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->next->num)
    {
        node->next = rightRotate(node->next);
        return leftRotate(node);
    }
    return node;
}

int main(void)
{
  struct node *root = NULL;
  int key, choice, num;
  do
  {
    system("cls");
    printf("AVL Tree Menu\n");
    printf("1] Insert\n2] Traverse\n3] Exit");
    printf("\n\nEnter choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter a number: ");
                scanf("%d", &key);
                num = Search(key, root);
                if(num == 0)
                    root = insert(root, key);
                else
                {
                    printf("Error: duplicate number.");
                    getch();
                }
                break;
        case 2: system("cls");
                printf("Preorder traversal: \n");
                preOrder(root);
                getch();
                break;
        case 3: printf("\nExiting...");
                getch();
                break;
        default:printf("Error: invalid input");
                getch();
                break;
    }
  }while(choice!=3);
  getch();
  return 0;
}
