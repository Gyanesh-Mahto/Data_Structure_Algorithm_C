/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *Next;
}*head = NULL;

void createLL(int n)
{
    if(head == NULL)
    {
        head = (struct Node*) malloc(sizeof(struct Node));
        head -> data = n;
        head -> Next = NULL;
    }
    else
    {
        struct Node *p = (struct Node*) malloc(sizeof(struct Node));
        p -> data = n;
        p -> Next = NULL;
        struct Node *q;
        q = head;
        while(q->Next!=NULL)
        {
            q = q->Next;
        }
        q -> Next = p;
    }
}

void printLL()
{
    struct Node *p = head;
    while(p)
    {
        printf("Data:%d\n", p->data);
        p=p->Next;
    };
}

int main()
{
    int n, choice;
    while(1)
    {
        printf("Please enter your choice\n1. Enter element\n2. Print LL\n3. Exit LL\n");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Please enter your data\n");
                scanf("%d", &n);
                createLL(n);
            break;
            case 2:
                printLL();
            break;
            case 3:
                exit(1);
                break;
            default:
                printf("Please enter correct input\n");
        }
    }
}
