#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

typedef struct node
{
    int num;
    struct node *prev, *next;
}NODE;

void process(NODE *,NODE *);

NODE *insert(int);
int findRoot(NODE *);
void preOrder(NODE *);

int main()
{
    NODE *root,*temp;
    int choice,elem,n,i;
    int num1,num2,rootnum,n1,n2;
    int search,hNum,max,min,lvl;
    bool sFound,bSib;
    char ch;

    root=NULL;
    do
    {
        system("cls");
        printf("\nDSW Tree\n\n");
        printf("\nChoose a desired operation:\n");
        printf("\n1]  Insert");
        printf("\n2]  Traverse");
        printf("\n3] Exit");
        printf("\n\nChoice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: system("cls");
                    do
                    {
                        printf("\nEnter an element: ");
                        scanf("%d",&elem);
                        temp=insert(elem);
                        if(root==NULL)
                            root=temp;
                        else
                            process(root,temp);
                        printf("\nEnter more data (y/n)?");
                        scanf(" %c",&ch);
                    }while(ch=='y'||ch=='Y');
                    break;
            case 2: printf("Preorder traversal\n");
                     preOrder(root);
                     getch();
                     break;
            case 3: system("cls");
                     printf("Exiting...");
                     getch();
                     break;
            default: system("cls");
                     printf("Error: invalid choice. Please try again.");
                     getch();
                     break;
        }
    }while(choice!=3);
    return 0;
}

//Functions
NODE *insert(int elem)
{
    NODE *temp;
    temp=(NODE *)malloc(sizeof(NODE));
    temp->num=elem;
    temp->prev=temp->next=NULL;
    return temp;
}

void process(NODE *root,NODE *temp)
{
    if(temp->num<root->num)
    {
        if(root->prev!=NULL)
            process(root->prev,temp);
        else
            root->prev=temp;
    }
    if(temp->num>root->num)
    {
        if(root->next!=NULL)
            process(root->next,temp);
        else
            root->next=temp;
    }
}

void preOrder(NODE *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->num);
        preOrder(root->prev);
        preOrder(root->next);
    }
}
