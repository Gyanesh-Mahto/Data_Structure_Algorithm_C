#include<iostream>
using namespace std;

void SelectionSort(int A[], int ele)
{
    for(int i=0; i<ele-1; i++)
    {
        int i_min = i;
        for(int j=i+1; j<ele; j++)
        {
            if(A[j]<A[i_min])
            {
                i_min = j;
            }
            int temp = A[i];
            A[i] = A[i_min];
            A[i_min] = temp;
        }
    }
}

int main()
{
    int A[5] = {1,3,2,5,4};
    int ele = sizeof(A)/sizeof(A[0]);
    SelectionSort(A, ele);
    cout<<"After sorting elements are: "<<endl;   
    for(int i=0; i<ele; i++)
    {
        cout<<A[i]<<" ";
    }
}