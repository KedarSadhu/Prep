#include<iostream>
using namespace std;

class base
{
    public:
    virtual void fun()
    {
        cout<<"In base fun()"<<endl;
    }
};
class derived : public base
{
    public:
    derived(){}
    void fun()
    {
        cout<<"In derived fun()"<<endl;
    }
};

int main(void)
{
     derived dobj;
     //base &obj = new derived  //this is error karn refrence la apan direct value nahi det apan tyala already banlelya memory la refre kar mhnun sangto.
     base &bobj = dobj;
     bobj.fun();
  
    return 0;
}