#include<stdio.h>

void BubbleSort(int A[], int ele)
{
    for(int i = 0; i<ele; i++)
    {
        int flag = 0;
        // for(int j = 0; j<ele-1; j++)    //Now the problem with this is that it scans through sorted element as well
        for(int j = 0; j<ele-i-1; j++)      //Now it will not scan through sorted elements
        {
            if(A[j]>A[j+1]) //Swap 
            {
                int temp;
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
        break;
    }
}

int main()
{
    int A[5] = {2,3,1,5,7};
    int ele = sizeof(A)/sizeof(A[0]);
    printf("Elements are:\n");
    for(int i=0; i<ele; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    BubbleSort(A, ele); //Sort
    printf("After sorting:\n");
    for(int i=0; i<ele; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}