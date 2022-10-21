#include <iostream>

using namespace std;

    int arr[10] = {25, 25, 25, 25, 25, 25, 25, 25, 25, 25};

    static int count = 0, index = 0, sum = 0, temp = 0, counter = 0;
    static bool firstTime = true;
    int average = 0;
//count = 5
//index = 8
/*
9 + 10 + 1 + 2 + 3
index = 3
count = 5
sum = sum - arr[8] = 25-9 = 16 + 4 = 20
*/
void execute()
{
    counter++;
    if(temp>0)
    {
        if((index == 9) && (firstTime == true))
        {
            sum+=arr[index];
            index = 0;
            temp--;
        }
        else if((index == 9) && (firstTime == false))
        {
            sum-=arr[index+count];
            sum+=arr[index];
            index = 0;
            temp--;
        }
        else if(((index < count) && (firstTime == true)) || ((index >= count) && (firstTime == true)))
        {
            sum+=arr[index];
            index++;
            temp--;
        }
        else if((index < count) && (firstTime == false) || ((index >= count) && (firstTime == false)))
        {
            sum-=arr[index+count]; //index = 3
            sum+=arr[index];
            index++;
            temp--;
        }
        
        if(temp == 0)
        {
            temp = count;
            firstTime = false;
        }
        
        cout<<endl<<endl<<"Counter: "<<counter<<endl<<endl;
        
        if(counter != 0)
        {
            average = sum / counter;
        }
        cout << average<<endl;
    }
    
    cout<<"Check Sum: "<<sum<<endl;
}

int main()
{
    bool flag = false;
    cout<<"Count: ";
    cin>>count;
    temp = count;
    cout<<"Index: ";
    cin>>index;
    temp=count;
    cout<<temp;
    
    execute();
    execute();
    execute();
    execute();
    execute();
    execute();
    execute();
    execute();
    execute();
    execute();
    execute();
    execute();
    execute();
    execute();
    execute();
    execute();
    execute();
    execute();
    execute();
    execute();
    
    return 0;
}
