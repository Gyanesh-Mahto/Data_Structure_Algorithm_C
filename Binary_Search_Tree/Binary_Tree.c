#include "myHeader.h"

struct Node         //Node of Binary Search Tree
{
    struct Node *Left_Smaller;
    int data;
    struct Node *Right_Greater;
}*Root=NULL;

void display_Inorder(struct Node *Root)     //Display-->Inorder
{ 
    if(Root)
    {
     /* first recur on left child */
     display_Inorder(Root->Left_Smaller); 
 
     /* then print the data of node */
     printf("%d ", Root->data);   
  
     /* now recur on right child */
     display_Inorder(Root->Right_Greater); 
    }
}

void Insert(int key)        //Inserting element in BST
{
    struct Node *p, *q, *r;
    r=Root;

    if(Root==NULL)      //If root is not present then create a Root Node
    {
        p=(struct Node*) malloc(sizeof(struct Node));
        p->data=key;
        p->Left_Smaller=p->Right_Greater=NULL;
        Root=p;
        return;
    }
    while(r!=NULL)  //Else search and insert element by creating a New node
    {
        q=r;
        if(key<r->data)
        r=r->Left_Smaller;
        else if(key>r->data)
        r=r->Right_Greater;
        else
        return;
    }
    r=(struct Node*)malloc(sizeof(struct Node));
    r->data=key;
    r->Left_Smaller=r->Right_Greater=NULL;
    if(key<q->data)
    q->Left_Smaller=r;
    else
    q->Right_Greater=r;
}

struct Node* Search(struct Node* t, int key)    //Searching Node in BST
    {
        while(t!=NULL)
        {
        if(key==t->data)
            return t;
        else if(key<t->data)
            t=t->Left_Smaller;
        else
            t=t->Right_Greater;
        }
        return NULL;
    }

int Height(struct Node *p)      //Height of BST
{
    int left_subtree_height, right_subtree_height;
    if(p==NULL)
    return 0;
    left_subtree_height=Height(p->Left_Smaller);
    right_subtree_height=Height(p->Right_Greater);
    return left_subtree_height>right_subtree_height?left_subtree_height+1:right_subtree_height+1;
}

struct Node* Inorder_Predecessor(struct Node *p)
{
    while(p && p->Right_Greater!=NULL)
    {
        p=p->Right_Greater;
    }
    return p;
}

struct Node* Inorder_Successor(struct Node *p)
{
    while(p && p->Left_Smaller!=NULL)
    {
        p=p->Left_Smaller;
    }
    return p;
}

struct Node* Delete(struct Node* t, int key)
{
    struct Node *q;
    if(t==NULL)
    return NULL;
    if(t->Left_Smaller==NULL && t->Right_Greater==NULL)
    {
        if(t==Root)
        Root=NULL;
        free(t);
        return NULL;
    }
    if(key < t->data)
    t->Left_Smaller=Delete(t->Left_Smaller, key);
    else if(key > t->data)
    t->Right_Greater=Delete(t->Right_Greater, key);
    else
    {
        if(Height(t->Left_Smaller)>Height(t->Right_Greater))
        {
        q=Inorder_Predecessor(t->Left_Smaller);
        t->data=q->data;
        t->Left_Smaller=Delete(t->Left_Smaller, q->data);
        }
        else
        {
        q=Inorder_Successor(t->Right_Greater);
        t->data=q->data;
        t->Right_Greater=Delete(t->Right_Greater, q->data);
        }
    }
    
return t;
}

int main()
{

    int number;
    char ch;
    struct Node *s;
    while(1)
    {
    printf("Please enter your choice\n1. Enter Element\n2. Display Element\n3. Search Element\n4. Delete Element:\n");
    scanf("%c", &ch);
    if(ch<='1' && ch>='3')
    printf("Please enter correct Input\n");
    switch (ch)
    {
    case '1':printf("Please enter your data\n");
             scanf("%d", &number);
             Insert(number);
             break;
    
    case '2':printf("Displaying the Data in BST\n");
            display_Inorder(Root);
            break;
    
    case '3':printf("Please enter your element for searching in BST\n");
            scanf("%d", &number);
            s=Search(Root, number);
            if(s)
            printf("Element is Found\n");
            else
            printf("Element is not found\n");
            break;
    
    case '4':printf("Please enter your element for deleting in BST\n");
            scanf("%d", &number);
            s=Delete(Root, number);
            if(s)
            printf("Element is Deleted\n");
            else
            printf("Element is not Deleted\n");
            break;
    default:
        break;
    }
    }

}

