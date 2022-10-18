/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int count = 0, index = 0, sum = 0, temp = 0;
    bool flag = false;
    cout<<"Count: ";
    cin>>count;
    temp = count;
    cout<<"Index: ";
    cin>>index;

    while(temp>0)
    {
        if((index >= temp) || ((index < temp) && (index !=0)))
        {
            sum+=arr[index];
            index--;
            temp--;
        } 
        
        if(index == 0)
        {
            sum+=arr[index];
            index = 9;
            temp--;
        }
        
    }
    
    cout << "Sum: "<< sum << endl;
    
    return 0;
}
