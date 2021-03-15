#include<stdio.h>

void bubble_sort(int a[], int size)
{
    for(int i = 0; i<5; i++)
    {
        for(int j = i; j<5; j++)
        {
            if(a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int a[5];
    printf("Enter any 5 numbers\n");
    for(int i=0; i<5; i++)
    scanf("%d", &a[i]);

    printf("The Numbers entered are as follows:\n");
    for(int i = 0; i<5; i++)
    printf("%d ", a[i]);
    printf("\n");
    bubble_sort(a, 5);
    printf("After sorting, The Numbers are as follows:\n");
    for(int i = 0; i<5; i++)
    printf("%d ", a[i]);
}