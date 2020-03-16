//Creating and displaying a linked list.
#include<stdio.h>
#include<stdlib.h>

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

void create1(int B[], int n)
{
    int i;
    struct Node *t, *last;
    head1=(struct Node*)malloc(sizeof(struct Node));
    head1->data=B[0];
    head1->Next=NULL;
    last=head1;

    for(i=1; i<n; i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=B[i];
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

void recursive_display(struct Node *p)      //Function for recursive display of data in nodes
{
    if(p)
    {
    printf("%d\n", p->data);
    printf("Data Address:%u\n", p);
    recursive_display(p->Next);
    }
}

void reverse_recursive_display(struct Node *p)      //reverse recursive display function
{
    if(p)
    {
    reverse_recursive_display(p->Next);
    printf("%d\n", p->data);
    printf("Data Address:%u\n", p);
    }
}

int count(struct Node *p)     //Function for counting the nodes
{
int count=0;
while(p)
{
    count+=1;
    p=p->Next;
}
return count;
}

int fist_method_recursive_count(struct Node *p)     //Function for counting the nodes
{
static int count=0;
if(p)
{
    count+=1;
    fist_method_recursive_count(p->Next);
}
return count;
}

int second_method_recursive_count(struct Node *p)     //Function for counting the nodes
{
if(p==0)
return 0;
else
return(second_method_recursive_count(p->Next)+1);
}

int sum_of_all_elements(struct Node *p)     //Function for sum of all elements in a node
{
    int sum=0;
    while(p)
    {
        sum=sum+p->data;
        p=p->Next;
    }
    return sum;
}

int recursive_sum_of_all_elements(struct Node *p)
{
    static int sum=0;
    if(p)
    {
        sum=sum+p->data;
        recursive_sum_of_all_elements(p->Next);
    }
    return sum;
}

int maximum_valued_element(struct Node *p)
{
    int max=0;
    while(p)
    {
        if(p->data>max)
        {
        max=p->data;
        p=p->Next;
        }
        else
        p=p->Next;
    }
    return max;
}

int recursive_maximum_valued_element(struct Node *p)
{
    static int max=0;
    if(p)
    {
    if(p->data>max)
    {
        max=p->data;
        recursive_maximum_valued_element(p->Next);
    }
    else
        recursive_maximum_valued_element(p->Next);
    return max;
    }
}

int search_element(struct Node *p, int key)
{
    while(p)
    {
        if(key==p->data)
        return 1;
        else
        p=p->Next;
    }
}

int recursive_search_element(struct Node *p, int key)
{
    if(p==NULL)
    return NULL;
    if(key==p->data)
    return 1;
    return recursive_search_element(p->Next, key);
}


struct Node* another_search_method(struct Node *p, int key)
{
    while(p)
    {
        if(key==p->data)
        return(p);
        p=p->Next;
    }
    return NULL;
}

struct Node* recursive_another_search_method(struct Node *p, int key)
{
    if(p==NULL)
    return NULL;
    if(key==p->data)
    return p;
    return recursive_another_search_method(p->Next, key);
}

struct Node* linear_search(struct Node *p, int key)
{
    struct Node *q=NULL;
    if(key==p->data)
    {
        q->Next=p->Next;
        p->Next=head;
        head=p;
        return p;
    }
    q=p;
    p=p->Next;
    
}

void add_at_begin(struct Node **head)
{
    struct Node *t;
    t=(struct Node*) malloc (sizeof(struct Node));
    printf("Please insert the data which you want to enter in new node\n");
    scanf("%d", &t->data);
        t->Next=*head;
        *head=t;
}

void add_at_position(struct Node **head)
{
    int pos;
    struct Node *t=(struct Node*) malloc (sizeof(struct Node));
    printf("Please insert the data which you want to enter in new node\n");
    scanf("%d", &t->data);
    struct Node *p=(struct Node*) malloc (sizeof(struct Node));
    p=*head;
    printf("Please enter the position where you want to enter the data\n");
    scanf("%d", &pos);
    if(pos<0 || pos>count(p))
    return;
    
    if(pos==0)
    {
        t->Next=*head;
        *head=t;
    }
    else
    {
    for(int i=0; i<pos-1 && p; i++)
    p=p->Next;
    t->Next=p->Next;
    p->Next=t;
    }
}


void add_at_end(struct Node **head)
{
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    printf("Please enter the data which you want to enter\n");
    scanf("%d", &t->data);
    t->Next=NULL;
    if(*head==0)
    {
        *head=t;
    }
    else
    { 
    struct Node *p;
    p=*head;
    while(p->Next)
    p=p->Next;
    t->Next=p->Next;
    p->Next=t;
    }
}

void sort_linked_list(struct Node *p)
{
    struct Node *t=(struct Node*) malloc (sizeof(struct Node));
    struct Node *q=(struct Node*) malloc (sizeof(struct Node));
    t=p;
    q=NULL;
    int temp;
    struct Node *r=NULL;
    while(t)
    {
        q=t->Next;
        while(q)
        {
        if(t->data>q->data)
        {
            temp=t->data;
            t->data=q->data;
            q->data=temp;
           /*
            r=q->Next;
            q->Next=t->Next;
            t->Next=r;
            */
        }
        q=q->Next;
        }
        t=t->Next;
    }
}

void insert_in_sorted_linked_list(struct Node *first)
{
    sort_linked_list(first);
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data which you want to enter in new node\n");
    scanf("%d", &t->data);
    t->Next=NULL;
    struct Node *p;
    p=first;
    struct Node *q=NULL;

    if(first==NULL)
    {
        first=t;
    }
    else
    {    
    while(p && p->data<t->data)
    {
        q=p;
        p=p->Next;
    }
    if(p==first)
    {
        t->Next=first;
        first=t;
    }
    else
    {
    t->Next=q->Next;
    q->Next=t;   
    }
    }
}

void delete(struct Node **first)
{
    int n=0, c, x;
    c=count(*first);
    printf("Total Number of Nodes:%d\n", c);
    printf("Please enter the node which you want to delete\n");
    scanf("%d", &n);
    struct Node *q=*first;
    struct Node *r=NULL;
    if(n==1)
    {
    x=(*first)->data;
    printf("Deleted Element: %d\n", x);
    struct Node *p=*first;
    *first=(*first)->Next;
    free(p);
    }
    else if(n>1 && n<=c)
    {
        for(int i=0; i<n-1; i++)
        {
            r=q;
            q=q->Next;
        }
        r->Next=q->Next;
        printf("Deleted Element: %d\n", q->data);
        free(q);
    }
    else
    {
        printf("Please enter the correct Node\n");
        exit(1);
    }
}

void isSort(struct Node *first)
{
    int flag=0, c;
    char ch;
    c=count(first);
    struct Node *p;
    struct Node *q;
    p=first;
    q=NULL;
    while(p->Next!=0)
    {
        q=p;
        p=p->Next;
        if(q->data>p->data)
        flag=1;
    }
    if(flag==0)
    printf("Linked list is sorted\n");
    else
    {
    printf("Linked list is not sorted\n");
    printf("Do you want to sort data\n");
    scanf("%c", &ch);
    if(ch=='y'||ch=='Y')
    {
        sort_linked_list(first);
    }
    else 
    {
        printf("Not sorting linked list\n");
    }
    
    }
}

void Remove_Duplicates_from_Linked_List(struct Node *first)
{
    printf("Sorting the linked list\n");
    sort_linked_list(first);
     printf("After Sorting the linked list\n");
    struct Node *p=first;
    struct Node *q=p->Next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {   
            p=q;
            q=q->Next;
        }
        else
        {
                p->Next=q->Next;
                free(q);
                q=p->Next;
        }
    }
}

void ReverseLinkedListElements(struct Node *first)
{
    struct Node *p=first;
    int ele=count(first);
    int A[ele], i=0;
    printf("Elements before reversing\n");
    while(p)
    {
        A[i]=p->data;
        p=p->Next;
        i++;
    }
    for(int i=0; i<ele; i++)
    printf("%d\n", A[i]);
    p=first; i--;
    printf("Elements after reversing\n");
    while(p)
    {
        A[i]=p->data;
        p=p->Next;
        i--;
    }
    for(int i=0; i<ele; i++)
    printf("%d\n", A[i]);
}

void ReverseLinks(struct Node **first)
{
    struct Node *p=*first;
    struct Node *q=NULL;
    struct Node *r=NULL;
    printf("Reversing links\n");
    while(p)
    {
        r=q;
        q=p;
        p=p->Next;
        q->Next=r;
    }
    *first=q;
}

void ReverseRecursion(struct Node *q, struct Node *p)
{
    if(p)
    {
        ReverseRecursion(p, p->Next);
        p->Next=q;
    }
    else
    {
        head=q;
    }
    
}

void Concatination2Linkedlist(struct Node *first, struct Node *second)
{
    struct Node *p=first;
    struct Node *q=second;
    while(p->Next!=NULL)
    {
        p=p->Next;
    }
    p->Next=second;
    second=NULL;
}

void Merging2LinkedList(struct Node *first, struct Node *second)
{
    struct Node *last=NULL;
    if(first->data<second->data)
    {
        head2=last=first;
        first=first->Next;
        head2->Next=NULL;
    }
    else
    {
        head2=last=second;
        second=second->Next;
        head2->Next=NULL;
    }
    while(first!=NULL && second!=NULL)
    {
       if(first->data<second->data)
       { 
        last->Next=first;
        last=first;
        first=first->Next;
        last->Next=NULL;
       }
       else
       {
        last->Next=second;
        last=second;
        second=second->Next;
        last->Next=NULL;
       }
    }
    if(first!=NULL)
    {
        last->Next=first;
        //last=first;
        //last->Next=NULL;
    }
    if(second!=NULL)
    {
        last->Next=second;
    }
    
}

int isLoop(struct Node *first)
{
 struct Node *p,*q;
 p=q=first;
 
 do
 {
 p=p->Next;
 q=q->Next;
 q=q?q->Next:q;
 }while(p && q && p!=q);

 if(p==q)
 return 1;
 else
 return 0;
}

int main()
{
    struct Node *temp;
    int A[]={3,25,26,27,28,29,30}, ele, ele1, Number_of_nodes, sum, Max=0, n, comp, isloop=0;
    ele=sizeof(A)/sizeof(A[0]);
    create(A, ele);

    printf("Normal Display Function\n");
    display(head);
    
    printf("Recursive Display Function\n");
    recursive_display(head);
    
    printf("Reverse Recursive Display Function\n");
    reverse_recursive_display(head);
    
    printf("Iterative function for counting:");
    Number_of_nodes=count(head);
    printf("Total Number of nodes:%d\n", Number_of_nodes);
    
    printf("First Method Recursive function for counting:");
    Number_of_nodes=fist_method_recursive_count(head);
    printf("Total Number of nodes:%d\n", Number_of_nodes);
    
    printf("Second Method of Recursive function for counting:");
    Number_of_nodes=second_method_recursive_count(head);
    printf("Total Number of nodes:%d\n", Number_of_nodes);
    
    printf("Sum of all elements:");
    sum=sum_of_all_elements(head);
    printf("%d\n", sum);
    
    printf("Sum of all elements recursively:");
    sum=recursive_sum_of_all_elements(head);
    printf("%d\n", sum);
    
    printf("Maximum valued element in a linked list:");
    Max=maximum_valued_element(head);
    printf("%d\n", Max);
    
    printf("Maximum valued element in a linked list through recursion:");
    Max=recursive_maximum_valued_element(head);
    printf("%d\n", Max);
    
    printf("Searching element function:\n");
    printf("Which element you want to search:");
    scanf("%d", &n);
    comp=search_element(head, n);
    if(comp==1)
    printf("Element is present\n");
    else
    printf("Element is not present\n");

    printf("Searching element recursive function:\n");
    printf("Which element you want to search:");
    scanf(" %d", &n);
    comp=recursive_search_element(head, n);
    if(comp==1)
    printf("Element is present\n");
    else
    printf("Element is not present\n");

    printf("Another searching element function:\n");
    printf("Which element you want to search: ");
    scanf(" %d", &n);
    temp=another_search_method(head, n);
    if(temp)
    printf("Key is found\nData:%d\nAddress:%u\n", temp->data, temp);
    else
    printf("Key is not found\n");

    printf("Another searching element function:\n");
    printf("Which element you want to search: ");
    scanf(" %d", &n);
    temp=recursive_another_search_method(head, n);
    if(temp)
    printf("Key is found\nData:%d\nAddress:%u\n", temp->data, temp);
    else
    printf("Key is not found\n");

    printf("Iterative Linear searching element function:\n");
    printf("Which element you want to search: ");
    scanf(" %d", &n);
    temp=linear_search(head, n);
    if(temp)
    printf("Key is found\nData:%d\nAddress:%u\n", temp->data, temp);
    else
    printf("Key is not found\n");

  
    printf("Normal Display Function\n");
    display(head);
    printf("Add at begin function\n");
    add_at_begin(&head);
    display(head);

    printf("Normal Display Function\n");
    display(head);
    printf("Add at position function\n");
    add_at_position(&head);
    display(head);

    printf("Normal Display Function\n");
    display(head);
    printf("Add at end function\n");
    add_at_end(&head);

    printf("Sorting Function\n");
    display(head);
    sort_linked_list(head);
    display(head);

    printf("Insert in sorted linked list\n");
    display(head);
    insert_in_sorted_linked_list(head);
    display(head);

    printf("Delete a Node in a linked list\n");
    display(head);
    delete(&head);
    display(head);

    printf("Is linked list sorted function\n");
    display(head);
    isSort(head);
    display(head);


    printf("Remove duplicates function\n");
    display(head);
    Remove_Duplicates_from_Linked_List(head);
    display(head);

    printf("Reversing element function:\n");
    display(head);
    ReverseLinkedListElements(head);
    display(head);
  
    printf("Reversing link function:\n");
    display(head);
    ReverseLinks(&head);
    display(head);

    printf("Recursive Reversing link function:\n");
    display(head);
    ReverseRecursion(NULL, head);
    display(head);

    printf("concatinating 2 linked List Function:\n");

    int B[]={10,20,30,40,50}, ele1;
    ele1=sizeof(B)/sizeof(B[0]);
    create1(B, ele1);

    printf("First Linked list\n");
    display(head);
    printf("Second Linked list\n");
    display(head1);
    printf("Concatinating both linked lists\n");
    Concatination2Linkedlist(head, head1);
    display(head);

    int B[]={10,20,30,40,50};
    ele1=sizeof(B)/sizeof(B[0]);
    create1(B, ele1);
    printf("Merging 2 Linked List Function:\n");
    printf("First Linked list\n");
    display(head);
    printf("Second Linked list\n");
    display(head1);
    printf("\nMerging both linked lists\n");
    Merging2LinkedList(head, head1);
    display(head2);

   
    struct Node *t1, *t2;
   
    printf("Linked list\n");
    display(head);
    printf("Is Loop or Linear Function:\n");
    
    t1=head->Next->Next;
    t2=head->Next->Next->Next->Next;
    t2->Next=t1;
    
    isloop=isLoop(head);
    if(isloop==1)
    printf("Looped Link\n");
    else
    printf("Linear Link\n");
    
}
