#include<iostream>
using namespace std;

class base
{
    protected:
    void fun()
    {
        cout << "In void fun" << endl;
    }
    
    public:
    void bun()
    {
        cout << "In void bun" << endl;
    }
    private:
    void mun()
    {
        cout << "In void mun" << endl;
    }

    friend void sun();
};

void sun()
{
    base bobj;
    bobj.fun();     //fun is protected still allowed as sun is friend
    bobj.bun();     //allowed as public
    bobj.mun();     //mun is private still allowed as sun is friend
}

void gun()
{
    base bobj;
    //bobj.fun();   //fun is protected not allowed as gun is not a friend
    bobj.bun();     //allowed as public
    //bobj.mun();   //mun is private not allowed as gun is not a friend
   
}

int main(void)
{
    sun();
    gun();
    return 0;
}