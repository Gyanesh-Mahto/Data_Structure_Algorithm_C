#include<iostream>
using namespace std;

long long greatest_common_divisor(long long a, long long b)
{
    long long greatest_divisor=0;
    for(long long i=1; i<=a && i<=b; i++)
    {
        if(((a%i)==0) && ((b%i)==0))
        {
            greatest_divisor= i;
        }
        
    }
    return greatest_divisor;
}

int main()
{
    long long best, a, b;
    cin>>a>>b;
    best=greatest_common_divisor(a,b);
    cout<<best<<endl;
}