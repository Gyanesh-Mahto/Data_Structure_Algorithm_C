#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* Next;
}*head;

void create(int A[], int n)
{
    int i;
    struct Node *temp, *last;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    head->Next=head;
    last=head;

    for(i=1; i<n; i++)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=A[i];
        temp->Next=last->Next;
        last->Next=temp;
        last=temp;
    }
}

void display(struct Node* p)
{
    do
    {
        printf("%d ", p->data);
        p=p->Next;
    }while(p!=head);
    printf("\n");
}

void display_recursive(struct Node* p)
{
    static int flag=1;
    if(p==head && flag==1)
    {
    printf("%d ", p->data);
    ++flag;
    display(p->Next);
    }
    else if(p!=head)
    {
    printf("%d ", p->data);
    display(p->Next);
    }
}

int Length(struct Node *h)
{
    struct Node *p;
    int len=0;
    p=head;
    do
    {
       ++len;
       p=p->Next;
    } while (p!=head);
    return len;
}

void insert(struct Node *h, int pos, int x)
{
    struct Node *temp;
    struct Node *p;

    if(pos<0 || pos>Length(h))
    exit(1);

    if(pos==0)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=x;
        
        if(head==NULL)
        {
            head=temp;
            head->Next=head;
        }
        else
        {
            p=head;
            while(p->Next!=head)
            {
                p=p->Next;
            }
            p->Next=temp;
            temp->Next=head;
            head=temp;
        }
    }
    else
    {
        p=head;
        for(int i=0; i<pos-1; i++)
        p=p->Next;

        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=x;
        temp->Next=p->Next;
        p->Next=temp;
    }       
}

void delete_head(struct Node *h)
{
struct Node *p, *q;
p=head;
q=head;
while(p->Next!=head)
{
    p=p->Next;
}
head=head->Next;
p->Next=head;
free(q);
}

void delete_at_given_position(struct Node *h, int pos)
{
    struct Node *p, *q;
    p=q=head;
    if(pos<0 || pos>Length(h))
    exit(1);

    if(pos==1)
    {
        while(p->Next!=head)
        {
            p=p->Next;
        }
        head=head->Next;
        p->Next=head;
        free(q);
    }
    else
    {
        for(int i=0; i<pos-1; i++)
        {
            q=p;
            p=p->Next;
        }
        q->Next=p->Next;
        free(p);
    }
}

int main()
{
    int A[]={1,2,3,4,5};
    create(A, 5);
    display(head);
    display_recursive(head);
    //insert(head, 6, 10);
    //display(head);
    delete_head(head);
    display(head);
    delete_at_given_position(head, 1);
    display(head);
    delete_at_given_position(head, 2);
    display(head);
}
