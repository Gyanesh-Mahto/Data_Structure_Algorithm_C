/*Model marble toy with finite automata*/

#include<iostream>
using namespace std;

int main()
{
    char lever;
    bool x1 = false, x2 = false, x3 = false;
    while(1)
    {
        cout<<"Where do you want to drop marble: A or B "<<endl;
        cin>>lever;
        switch(lever)
        {
            case 'A':
                cout<<"case A"<<endl;
                if(x1 == false)
                {
                    cout<<"Marble came through : 'C'"<<endl;
                    x1 = true;
                }
                else if((x1 == true) && (x2 == false))
                {
                    cout<<"Marble came through : 'C'"<<endl;
                    x1 = false;
                    x2 = true;
                }
                else if((x1 == true) && (x2 == true))
                {
                    cout<<"Marble came through : 'D'"<<endl;
                    x1 = false;
                    x2 = false;
                }
                break;
            case 'B':
                if(x3 == true)
                {
                    cout<<"Marble came through : 'D'"<<endl;
                    x3 = false;  
                }
                else if((x3 == false) && (x2 == false))
                {
                    cout<<"Marble came through : 'C'"<<endl;
                    x3 = true;
                    x2 = true;
                }
                else if((x3 == false) && (x2 == true))
                {
                    cout<<"Marble came through : 'D'"<<endl;
                    x3 = true;
                    x2 = false;
                }
                cout<<"case B"<<endl;
                break;
            default:
                exit(1);
                break;
        }
    }
    
}