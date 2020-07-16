#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *Prev;
    int data;
    struct Node *Next;
} *head=NULL;

void create(int A[], int n)
{
    struct Node *last;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    head->Prev=head->Next=head;
    last=head;
    for(int i=1; i<n; i++)
    {
        struct Node *temp;
        temp=(struct Node*) malloc(sizeof(struct Node));
        temp->data=A[i];
        temp->Prev=last;
        last->Next=temp;
        temp->Next=head;
        head->Prev=temp;
        last=temp;
    }
}

void display()
{
    struct Node *p;
    p=head;
    do
    {
        printf("%d ", p->data);
        p=p->Next;
    } while (p!=head);
    printf("\n");
}

int Length()
{
    struct Node *p;
    p=head;
    int len=0;
    do
    {
        len++;
        p=p->Next;
    } while (p!=head);
    return len;
}

void insert(int n, int pos)
{
    if(pos<0 & pos >Length())
    {
        exit(1);
    }
    else if(pos==0)
    {
        struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=n;
        temp->Next=temp->Prev=NULL;
        temp->Next=head;
        temp->Prev=head->Prev;
        head->Prev=temp;
        temp->Prev->Next=temp;
        head=temp;
    }
    else if(pos>0)
    {
        struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=n;
        temp->Prev=temp->Next=NULL;
        struct Node *p;
        p=head;
        for(int i=0; i<pos-1; i++)
        {
            p=p->Next;
        }
        if(p->Next)
        {
            temp->Next=p->Next;
            p->Next->Prev=temp;
        }
        p->Next=temp;
        temp->Prev=p;
    }
}

int delete(int pos)
{
    if(pos<0 && pos>Length())
    exit(1);
    else if(pos==0)
    {
        int x;
        struct Node *p;
        p->Next->Prev=p->Next;
        p->Prev->Next=p->Next;
        head=p->Next;
        x=p->data;
        free(p);
        return x;
    }
    else if(pos>0)
    {
        int x;
        struct Node *p;
        p=head;
        for(int i=0; i<pos; i++)
        {
            p=p->Next;
        }
        p->Next->Prev=p->Next;
        p->Prev->Next=p->Next;
        x=p->data;
        free(p);
        return x;
    }
}

int main()
{
    int A[]={1,2,3,4,5,6};
    create(A, 6);
    display();
    Length();
    insert(10,0);
    display();
    insert(10,2);
    display();
    insert(10,8);
    display();
    int x;
    x=delete(8);
    printf("Popped Data: %d\n", x);
    display();
    x=delete(2);
    printf("Popped Data: %d\n", x);
    display();
    x=delete(0);
    printf("Popped Data: %d\n", x);
    display();
}