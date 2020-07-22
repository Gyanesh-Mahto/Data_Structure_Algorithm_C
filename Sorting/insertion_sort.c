/*
INSERTION SORT
--------------
- In sorted list we have to insert an element at sorted position
- Time taken for insertion sort is:
Best case - O(1) - Inserting element in sorted list at the start of array or linked list
Worst case - O(n) - Inserting element in sorted list at the middle or end of array or linked list

No. of passes - for n elements, n-1 passes
No. of comparison - for n elements, O(n^2)
No. of swaps - for n elements, O(n^2)

Insertion sort is more compatible with linked list
*/

#include<stdio.h>

int main()
{
    int A[6]={10,5,10,3,13,1};
    int j=0, x;
    // printf("Please enter any 06 elements:\n");
    // for(int i=0; i<10; i++)
    // {
    //     scanf("%d", &A[i]);
    // }

    printf("Implementing Insertion sort\n");
    for(int i=1; i<10; i++)
    {
        j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;   
        }
        A[j+1]=x;
    }

    printf("Sorted elements:\n");
    for(int j=0; j<6; j++)
    {
        printf("%d ", A[j]);
    }   
    printf("\n");
}