#include<iostream>
using namespace std;

class base
{
    const int i;
    const int k = 20; //allowed from c++11 -> class madhe initialization
    int j = 30;
    
    public:
    
    base():i(10)
    {
        cout<<i<<endl;
    }
    void fun() const
    {   
        //void fun(base const * const this)
        // this is const ptr which points const base
        
        //j++; //cant modify object
        cout<<"j = "<<j <<endl;
    } 
    void gun()
    {
        //void gun(base * const this)
        cout<<"in non const function" <<endl;
    }  
};

int main(void)
{
    base b;
    b.fun();    //fun(b);
    b.gun();    // allowed normal obj can call const function 

    cout<<"sizeof(b) :: "<<sizeof(b);   //4

    const base b1;
    b1.fun();
    //b1.gun();   // not allowed - const obj !() non const function, security kami karto not allowed

    return 0;
}