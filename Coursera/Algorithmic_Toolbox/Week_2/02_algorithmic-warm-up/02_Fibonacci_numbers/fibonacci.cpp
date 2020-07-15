#include <iostream>
using namespace std;

void fibonacci(int n)
{
    int a=0, b=1, c;
    if(n==0)
        {
            cout<<a<<endl;
        }
        else if(n==1)
        {
            cout<<b<<endl;
        }
        else
        {
            for(int i=1; i<n; i++)
            {
            c=a+b;
            a=b;
            b=c;
            }
            cout<<c<<endl;
        }
}

int main()
{
    int n;
    cin>>n;
    fibonacci(n);
}