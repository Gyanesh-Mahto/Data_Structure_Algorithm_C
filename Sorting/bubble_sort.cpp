#include<iostream>
using namespace std;

template<typename T>
void bubble_sort(T a[], int size)
{
    for(int i = 0; i<5; i++)
    {
        for(int j = i; j<5; j++)
        {
            if(a[i] > a[j])
            {
                T temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int a[5];
    cout<<"Enter any 5 numbers"<<endl;
    for(int i=0; i<5; i++)
    cin>>a[i];

    cout<<"The Numbers entered are as follows:"<<endl;
    for(int i = 0; i<5; i++)
    cout<<a[i];
    cout<<endl;
    bubble_sort<int>(a, 5);
    cout<<"After sorting, The Numbers are as follows:"<<endl;
    for(int i = 0; i<5; i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
