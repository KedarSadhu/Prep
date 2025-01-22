#include<iostream>
using namespace std;

class base
{
    public:
    base()
    {
        cout << "In base constructor" << endl;
    }
    // ~base()
    // {
    //     cout << "In base destructor" << endl;
    // }
    virtual ~base()
    {
        cout << "In base destructor" << endl;
    }
};

class derived:public base
{
    int *ptr;

public:
    derived()
    {
        cout << "In derived constructor" << endl;
        ptr = (int *)malloc(100);
    }
    ~derived()
    {
        cout << "In derived destructor" << endl;
        if(ptr)
            free(ptr);
    }
};

int main(void)
{
    base *bp = new derived();   //upcasting
    delete bp;
    /*
        In base constructor
        In derived constructor
        In base destructor  --> delete bp mule base class destructor call zala pan derived cha zala nahi
        so memory leak mhnun virtual destructor

        pure virtual destructor pn astat
        virtual ~base()=0
        {
          //defination must
        } -->yane achive kahi hot nahi fakt Object banvnya pasun rokhu shakto

        NOTE- virtual ~base()=0; //error

    */

    /*
      After virtual ~base()    
        In base constructor
        In derived constructor
        In derived destructor
        In base destructor
    
    */

    return 0;
}