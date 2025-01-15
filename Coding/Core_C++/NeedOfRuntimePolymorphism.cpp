#include<iostream>
using namespace std;

class base
{
    public:
    void fun()
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

    bp->fun();  //In base fun()
    bp->gun();  //In base gun()

    /*
    bp madhe jar derived class chya obj cha address store kela ahe tar apla expectation ahe ki
    derived cha fun call vhayla pahije hota pan tasa zala nahi.

    base class pointer la fakt base chach part disto ani varchya case madhe compiler ne 
    early binding kely...

    jar aplyala he nako asel tr late binding/function over riding/dyanamic linking/runtime polymorphism 
    vaprave lagel
    i.e virtual
    
    
    */


    return 0;
}