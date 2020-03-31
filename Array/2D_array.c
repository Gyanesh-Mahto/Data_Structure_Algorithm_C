#include<stdio.h>
#include<stdlib.h>

int main()
{
    //1st Method: creating 2D array in stack
    int A[3][4]={{1,2,3,4}, {2,4,6,8}, {3,5,7,9}}; //This array will be created inside stack section.
    printf("printing elements of array A:\n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            printf("%d ", A[i][j]); //1 2 3 4 2 4 6 8 3 5 7 9
        }
    }
    printf("\n");

    //2nd Method: Array of pointers
    int *B[3];  //It will be created inside stack section of memory.
    B[0]=(int*)malloc(sizeof(int)*4);   //This array will be created inside heap section of memory.This array will be created in heap.
    B[1]=(int*)malloc(sizeof(int)*4);   //This array will be created inside heap section of memory.
    B[2]=(int*)malloc(sizeof(int)*4);   //This array will be created inside heap section of memory.

    int k=1;
    printf("Initializing array B with square of 2");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            k=k*2;
            B[i][j]=k;
        }
    }

    printf("printing elements of array B:\n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            printf("%d ", B[i][j]); //2 4 8 16 32 64 128 256 512 1024 2048 4096
        }
    }
    printf("\n");

    //3rd Method: double pointers
    int **p;    //double pointer created in stack
    p=(int**)malloc(sizeof(int*)*3);   //This array will be created in heap.
    p[0]=(int*)malloc(sizeof(int)*4);   //This array will be created in heap.
    p[1]=(int*)malloc(sizeof(int)*4);   //This array will be created in heap.
    p[2]=(int*)malloc(sizeof(int)*4);   //This array will be created in heap.

    int m=1;
    printf("Initializing array B with cube of 3");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            m=m*3;
            p[i][j]=m;
        }
    }

    printf("printing elements of array p:\n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            printf("%d ", p[i][j]); //3 9 27 81 243 729 2187 6561 19683 59049 177147 531441
        }
    }
    printf("\n");
}

/*
O/P:
printing elements of array A:
1 2 3 4 2 4 6 8 3 5 7 9 
Initializing array B with square of 2printing elements of array B:
2 4 8 16 32 64 128 256 512 1024 2048 4096 
Initializing array B with cube of 3printing elements of array p:
3 9 27 81 243 729 2187 6561 19683 59049 177147 531441 
*/
