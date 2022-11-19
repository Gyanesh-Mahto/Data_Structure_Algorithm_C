/*
Given a positive integer, target, print all possible combinations of positive integers that sum up to the target number.
For example, if we are given input ‘5’, these are the possible sum combinations.

1, 4
2, 3
1, 1, 3
1, 2, 2
1, 1, 1, 2
1, 1, 1, 1, 1
*/
#include<iostream>
#include<vector>
using namespace std;

void fun(int index, vector<int> &v, int arr[], int num, int len, int target)
{
    if(index == len)
    {
        if(target == 0)
        {
            for(auto it : v)
                cout<<it<<" ";
                cout<<endl;
        }
        return;
    }
    if(arr[index] <= target)
    {
        v.push_back(arr[index]);
        fun(index, v, arr, num, len, target-arr[index]);
        v.pop_back();
    }
    fun(index+1, v, arr, num, len, target);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n;
    int len=3;
    cin>>n;
    vector<int> v;
    fun(0, v, arr, n, len, n);
}
