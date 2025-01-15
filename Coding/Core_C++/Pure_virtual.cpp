#include<iostream>
using namespace std;

//gives interface
class base  //pure abstract class --> saglech function pure virtual
{
    public:
        virtual void fun() = 0; //pure virtual function
};

class derived:public base
{
    public:
    void fun()
    {
        cout << "In derived enhanced fun()" << endl;
    }
};

int main(void)
{
    //base bobj; //cant create object of base class --> incomplete vtable   
    derived dobj;   //can create object of r=derived as implemented pure virtual function --> vtable completed

    base *bp = &dobj;
    bp->fun();  //In derived enhanced fun()

    return 0;
}