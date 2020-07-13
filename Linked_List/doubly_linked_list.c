#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *Prev;
    int data;
    struct Node *Next;
}*head=NULL;

void create(int A[], int n)
{
    struct Node *temp, *last;

    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    head->Next=head->Prev=NULL;
    last=head;

    for(int i=1; i<n; i++)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=A[i];
        temp->Next=last->Next;
        temp->Prev=last;
        last->Next=temp;
        last=temp;
    }
}

int Length(struct Node *h)
{
    struct Node *p;
    p=h;
    int len=0;
    while(p)
    {
        len++;
        p=p->Next;
    }
    printf("Length: %d\n", len);
    return len;
}

void insert(struct Node *h, int pos, int n)
{
    struct Node *p, *temp;
    p=head;
    if(pos<0 || pos>Length(head))
    exit(1);
    else if(pos==0)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=n;
     
        temp->Prev=NULL;
        temp->Next=head;
        head->Prev=temp;
        head=temp;
    }
    else if(pos>1)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=n;
        for(int i=1; i<pos-1; i++)
        {
            p=p->Next;
        }
        temp->Next=p->Next;
        temp->Prev=p;
        if(p->Next)
        p->Next->Prev=temp;
        p->Next=temp;
    }
    else if(pos==Length(head))
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->Next=temp->Prev=NULL;
        while(p)
        {
            p=p->Next;
        }
        temp->Prev=p;
        p->Next=temp;

    }
}

void Display(struct Node *h)
{
    struct Node *p;
    p=head; 
    while(p)
    {
        printf("%d ", p->data);
        p=p->Next;
    }
    printf("\n");
}

int main()
{
    int A[]={1,2,3,4,5,6,7,8,9};
    create(A, 9);
    Display(head);
    //Length(head);
    insert(head,8,10);
    Display(head);
    Length(head);
}