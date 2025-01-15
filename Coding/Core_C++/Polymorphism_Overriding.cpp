#include<iostream>
using namespace std;

class base
{
    public:
    virtual void fun()
    {
        cout << "in base fun()" << endl;
    }

    void gun()
    {
        cout << "In base gun()" << endl;
    }
};

class derived : public base
{
    public:
    void fun()  //function redefination--> same name in base and derived -->hides inherited base fun
    {
        cout << "In derived enhanced fun()" << endl;
    }
    void mun()
    {
        cout << "In derived mun()" << endl;
    }
};

int main(void)
{
    derived dobj;
    base *bp = &dobj;  //upcasting
    
    cout << "sizeof(class base) :: " << sizeof(class base) << endl; //8 vptr
    cout << "sizeof(class derived) :: " << sizeof(class derived) << endl; //8 vptr

    bp->fun();  //In derived enhanced fun()
    bp->gun();  //In base gun()

    base &bref = dobj;  //upcasting using reference
    bref.fun(); //In derived enhanced fun()
    bref.gun(); //In base gun()

    /*
        Some imp points

        1. jar ekhadya class madhe virtual function asel or ek asa class jo derived zalay from a class containg virtual function
        tar compiler creates VTABLE for it.
        2. VTABLE is an array of function pointer contains address of virtual functions.bcz of inheritance base class vtable entries
        get inherited in derived class vtable.
        3.VTABLE is seprate for classes but not for objects.VTABLES gets shared among the objects of same class. he sharing achive karayla 
        class madhe sarvat top la VPTR navacha data member add kela jato

    
    
    */


    return 0;
}