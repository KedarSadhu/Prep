#include<iostream>
using namespace std;

class Base
{
    public:
    Base()
    {
        cout << "In Base default Constructor"<<endl;
    }
    ~Base()
    {
        cout << "In Base destructor"<<endl;
    }
};

class Derived1 : public Base
{
    public:
    Derived1()
    {
        cout << "In Derived1 default Constructor"<<endl;
    }
    ~Derived1()
    {
        cout << "In Derived1 destructor"<<endl;
    }
};

class Derived2 : public Derived1
{
    public:
    Derived2()
    {
        cout << "In Derived2 default Constructor"<<endl;
    }
    ~Derived2()
    {
        cout << "In Derived2 destructor"<<endl;
    }
};

int main(void)
{
    Derived2 obj;
    /*
        In Base default Constructor
        In Derived1 default Constructor
        In Derived2 default Constructor
        In Derived2 destructor
        In Derived1 destructor
        In Base destructor
    */
    return 0;
}

