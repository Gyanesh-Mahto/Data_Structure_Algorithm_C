#include<stdio.h>
#include<stdlib.h>

int main()
{
    //Declaration and initialization of an Array
    int A[5];   //Garbage Value
    int B[5]={2,4,6,8,10};  //2 4 6 8 10
    int C[10]={2,4,6};     //2 4 6 0 0 0 0 0 0 0
    int D[5]={0};       //0 0 0 0 0
    int E[]={1,2,3,4,5,6,7,8};  //1 2 3 4 5 6 7 8
    int ele1, ele2, ele3, ele4, ele5;
    ele1=sizeof(A)/sizeof(A[0]);    //Finding the size of Array A
    ele2=sizeof(B)/sizeof(B[0]);    //Finding the size of Array B
    ele3=sizeof(C)/sizeof(C[0]);    //Finding the size of Array C
    ele4=sizeof(D)/sizeof(D[0]);    //Finding the size of Array D
    ele5=sizeof(E)/sizeof(E[0]);    //Finding the size of Array E

    for(int i=0; i<ele1; i++)   //Printing all the elements in Array A
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("Address:\n");
    for(int i=0; i<ele1; i++)   //Printing the address of memory occupied by Array A in Stack section of RAM
    {
        printf("%u ", &A[i]);   //2839941664 2839941668 2839941672 2839941676 2839941680
    }
    printf("\n");
    for(int i=0; i<ele2; i++)   //Printing all the elements in Array B
    {
        printf("%d ", B[i]);
    }
    printf("\n");
    for(int i=0; i<ele3; i++)   //Printing all the elements in Array C
    {
        printf("%d ", C[i]);
    }
    printf("\n");
    for(int i=0; i<ele4; i++)   //Printing all the elements in Array D
    {
        printf("%d ", D[i]);
    }
    printf("\n");
    for(int i=0; i<ele5; i++)   //Printing all the elements in Array E
    {
        printf("%d ", E[i]);
    }
    printf("\n");
}
