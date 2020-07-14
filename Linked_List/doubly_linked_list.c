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
    else
    {
        for(int i=0; i<pos-1; i++)
            p=p->Next;
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=n;
        temp->Prev=p;
        temp->Next=p->Next;
        if(p->Next)
            p->Next->Prev=temp;
        p->Next=temp;
    }
}

void delete(struct Node *h, int pos)
{
    if(pos<0 || pos>Length(head))
    exit(1);
    if(pos==0)
    {
        struct Node *p, *q;
        q=p=head;
        q=q->Next;
        head=q;
        q->Prev=NULL;
        free(p);
    }
    else
    {
    struct Node *p, *q;
    q=p=head;
    for(int i=0; i<pos; i++)
    {
        q=p;
        p=p->Next;
    }
    if(p->Next)
    {
    p->Next->Prev=q;
    q->Next=p->Next;
    }
    else
    {
        q->Next=NULL;
    }
    free(p);
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


void reverse(struct Node *p)
{
    struct Node *temp;
    p=head;
    while(p!=NULL)
    {
        temp=p->Next;
        p->Next=p->Prev;
        p->Prev=temp;
        p=p->Prev;
        
        if(p!=NULL && p->Next==NULL)
        head=p;
    }
}

int main()
{
    int A[]={1,2,3,4,5,6,7,8,9};
    create(A, 9);
    Display(head);
    //Length(head);
    insert(head,0,10);
    Display(head);
    delete(head, 9);
    Display(head);
    Length(head);
    reverse(head);
    Display(head);
}
