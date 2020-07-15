#include<iostream>
#include <chrono>
#include<cstdlib> 
#include<vector>
#include<algorithm>
using namespace std;
using namespace std::chrono;


long long max_pairwise_product(long long A[], int n)
{
    long long big=0, second_big=0, result;
    static int count=0;
    for(int i=0; i<n; i++)
    cin>>A[i];
    auto start = high_resolution_clock::now();
    for(int i=0; i<n; i++)
    {
        if(A[i]>big)
        {
        second_big=big;
        big=A[i];
        }
        else if(A[i]>second_big && A[i]!=big)
        {
            second_big=A[i];
        }
    }
    for(int i=0; i<n; i++)
    {
        if(big==A[i])
        {
            count+=1;
        }
    }
    if(count==1)
    {
        result=big*second_big;
    }
    else
    {
        result=big*big;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
    return result;
}

int main()
{
    int n;
    long long result;
    cin>>n;
    long long A[n];
    result=max_pairwise_product(A, n);
    cout<<result<<endl;
}