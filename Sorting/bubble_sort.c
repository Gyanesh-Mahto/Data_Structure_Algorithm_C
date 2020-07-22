/*
BUBBLE SORT
-----------
- Minimum time taken by bubble sort is O(n) - Best Case(Already sorted)
- Maximum time taken by bubble sort is O(n^2) - Worst Case(Unsorted elements)
- So, Bubble sort is adaptive by using flag 
- Bubble sort is stable
*/

#include<stdio.h>

int main()
{
    int A[6]={10,10,10,3,13,1};
    // printf("Please enter any 06 elements:\n");
    // for(int i=0; i<10; i++)
    // {
    //     scanf("%d", &A[i]);
    // }

    int flag;
    printf("Implementing Bubble sort\n");
    for(int i=0; i<6-1; i++)
    {
        flag=0;
        for(int j=0; j<6-1-i; j++)
        {
            if(A[j]>A[j+1])
            {
                int temp;
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
        break;
    }

    printf("Sorted elements:\n");
    for(int j=0; j<6; j++)
    {
        printf("%d ", A[j]);
    }   
    printf("\n");
}