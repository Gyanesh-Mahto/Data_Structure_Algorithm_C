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
    ele1=sizeof(A)/sizeof(A[0]);
    ele2=sizeof(B)/sizeof(B[0]);
    ele3=sizeof(C)/sizeof(C[0]);
    ele4=sizeof(D)/sizeof(D[0]);
    ele5=sizeof(E)/sizeof(E[0]);

    for(int i=0; i<ele1; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    for(int i=0; i<ele2; i++)
    {
        printf("%d ", B[i]);
    }
    printf("\n");
    for(int i=0; i<ele3; i++)
    {
        printf("%d ", C[i]);
    }
    printf("\n");
    for(int i=0; i<ele4; i++)
    {
        printf("%d ", D[i]);
    }
    printf("\n");
    for(int i=0; i<ele5; i++)
    {
        printf("%d ", E[i]);
    }
    printf("\n");
}