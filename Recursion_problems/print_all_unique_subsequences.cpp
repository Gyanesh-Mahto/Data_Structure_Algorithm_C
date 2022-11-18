//Print unique subsequences
#include<iostream>
#include<vector>
using namespace std;

void printSubsequence(int index, vector<int> &v, int arr[], int len)
{
    if(index == len)
    {
        // for(int i=0; i<v.size(); i++)
        // {
        //     cout<<v[i]<<" ";
        // }
        
        for(auto it : v)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    
    v.push_back(arr[index]);
    printSubsequence(index+1, v, arr, len);
    v.pop_back();
    printSubsequence(index+1, v, arr, len);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    printSubsequence(0, v, arr, len);
}