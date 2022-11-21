//Print subsequences whose sum is k
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

void printSubsequence(int index, vector<int> &v, int arr[], int len, int n, int sum)
{
    if(index == len)
    {
        if(sum == n)
        {
            for(auto it : v)
            {
                cout<<it<<" ";
            }
            cout<<endl;   
        }
        return;
    }
    
    v.push_back(arr[index]);
    sum+=arr[index];
    printSubsequence(index+1, v, arr, len, n, sum);
    v.pop_back();
    sum-=arr[index];
    printSubsequence(index+1, v, arr, len, n, sum);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr)/sizeof(arr[0]);
    int n;
    cout<<"Find sum of no. equivalent to: "<<endl;
    cin>>n;
    vector<int> v;
    printSubsequence(0, v, arr, len, n, 0);
}