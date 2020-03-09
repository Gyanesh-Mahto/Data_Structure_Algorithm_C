#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* Next;
}*head=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    head->Next=NULL;
    last=head;

    for(i=1; i<n; i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->Next=NULL;
        last->Next=t;
        last=t;
    }
    last->Next=head->Next;
}

void display(struct Node *head)
{
    
}

int main()
{
    int A[12,13,14,15,16], ele;
    ele=sizeof(A)/sizeof(A[0]);
    cout<<"Creating circular Linked list"<<endl;
    create(A, ele);
}