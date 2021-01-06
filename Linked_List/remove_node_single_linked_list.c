//Creating and displaying a linked list.
#include<stdio.h>
#include <stdlib.h>
struct Node     //Creating a structure for a Node
{
    int data;
    struct Node *Next;
}*head=NULL, *head1=NULL, *head2=NULL;    //Creating a head pointer globally to point the first node.

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

}

void display(struct Node *p)    //Function for displaying the data in nodes
{
    while(p)
    {
        printf("Data:%d\n", p->data);
        printf("Data Address:%u\n", p);
        p=p->Next;
    };
}

void rm_node(struct Node *list_elem)
{
    if(head == list_elem)
    {
        head = head->Next;
        free(list_elem);
    }
    else
    {
        struct Node *p = list_elem;
        while(p->Next)
        {
            if(p->Next == list_elem)
            {
                p->Next = list_elem->Next;
                free(list_elem);
                break;
            }
            p = p->Next;
        }
    }
}

int main()
{
    struct Node *temp;
    int A[]={3,25,26,27,28,29,30}, ele, ele1, Number_of_nodes, sum, Max=0, n, comp, isloop=0, k;
    ele=sizeof(A)/sizeof(A[0]);
    create(A, ele);

    printf("Normal Display Function\n");
    display(head);
    printf("///////////////////////////");
    printf("head - > %d\n", head->data);
    printf("///////////////////////////");
    struct Node *list_elem;
    list_elem = head;
    rm_node(list_elem);
    printf("/////////////////////////////");
    display(head);
}
