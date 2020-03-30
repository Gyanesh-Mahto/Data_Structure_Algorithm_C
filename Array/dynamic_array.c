#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p, *q;
    p=(int*)malloc(sizeof(int)*5);  //Array of size 5 is created in heap memory pointed by p.
    
    for(int i=0, j=1; i<5; i++) //Allocating elements to memory pointed by p.
    {
        j=j*2;
        p[i]=j;
    }

    for(int i=0; i<5; i++)  
    {
        printf("%d ", p[i]);    //2 4 8 16 32
    }
    printf("\n");

    /*Now, Suppose, this array size is not sufficient and we want larger array, then we need to
    create new array with larger size.
    */
   q=(int*)malloc(sizeof(int)*10);  //Created new Array of size 5 is created in heap memory
                                    // pointed by q
    for(int i=0; i<5; i++)      //Allocating the elements of array pointed by p in array pointed by q
    {
        q[i]=p[i];
    }

    for(int i=5, j=32; i<10; i++)      //Allocating extra elements in array pointed by q.
    {
        j=j*2;
        q[i]=j;
    }

    for(int i=0; i<10; i++)
    {
        printf("%d ", q[i]);    //2 4 8 16 32 64 128 256 512 10
    }
    printf("\n");

    free(p);    //Freeing up the memory of array allocated in heap pointed by p

    p=q;    //Making p point to the array pointed by q

    q=NULL; //Removing q since p is pointing to the newly created array.

    for(int i=0; i<10; i++)  
    {
        printf("%d ", p[i]);    //2 4 8 16 32 64 128 256 512 1024
    }
    printf("\n");

}