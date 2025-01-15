#include<iostream>
using namespace std;

class base
{
    public:
    void fun()
    {
        cout<<"fun with no param"<<endl;
    }

    void fun(int a)
    {
        cout<<"fun with 1 int param"<<endl;
    }

    void fun(int a,int b)   //change in number of param
    {
        cout<<"fun with 2 int param"<<endl;
    }

    void fun(int a,char c)  //change in types of param
    {
        cout<<"fun with 1 int 1 char param"<<endl;
    }

    void fun(char c,int a)  //change in sequence of param
    {
        cout<<"fun with 1 char 1 int param"<<endl;
    }
};

int main(void)
{
    base obj;
    //1 name many form
    obj.fun();
    obj.fun(10);
    obj.fun(10,20);
    obj.fun(10,'a');
    obj.fun('a',10);
    
    /*
    Overloading is not possible in below cases
    1.depending on return type
    2.const qualifier (constant param) ---- const member function is allowed for overloading
    3.depend on reference as param
    4.default argument
    
    */

    return 0;
}