#include<iostream>
#include <vector>
 
using namespace std;
 
class Demo
{
    private:
 
    size_t length;
    int * data;
 
    public:
 
    Demo (size_t len):length(len),data(new int)
    {
        cout<<"In simple constructor :: length = "<<length<<endl;
        *data = len;
    }
 
    //Move Constructor
    Demo(Demo && other):data(nullptr),length(0)
    {
        cout<<"In move constructor :: length = "<<other.length<< "\nMoving resource." <<endl;
       
        //Copy data and length from source
        data = other.data;
        length = other.length;
 
        //source data pointer la null kela
        other.data = nullptr;
        other.length = 0;
    }
 
    //Move assignment operator
    Demo& operator=(Demo && other)
    {
        cout<<"In operator = :: length = "<<other.length<<endl;
 
        if(this != &other)
        {
            //Free existing resource
            delete data;
 
            //Copy data and length from source
            data = other.data;
            length = other.length;
 
            //source data pointer la null kela
            other.data = nullptr;
            other.length = 0;
        }
 
        return *this;
    }
 
    void display()
    {
        if(data != nullptr)
            cout<<"data = "<< (*data) <<endl;
        else
            cout<<"Can not print data as its moved" <<endl;
    }
    ~Demo()
    {
        cout<<"In Destructor :: length = "<<length;
 
        if(data != nullptr)
        {
            cout<<". Deleting resource";
            delete data;
        }
       
        cout<<endl;
    }
};
 
 
int main()
{
    Demo obj1(20);
    obj1.display();

    Demo obj2 = move(obj1);
    obj2.display();

    obj1.display();

    return 0;
}