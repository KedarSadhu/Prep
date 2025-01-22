#include<iostream>
using namespace std;

class demo
{
    public:
        int iNo;
        demo()
        {
            iNo = 10;
            cout<<"Default Constructor \n";
        }
        demo(int i)
        {
            iNo = i;
        }
        demo(demo &refObj)
        {
            iNo =20;
            cout<<"Inside Copy Constructor \n";
        }

        demo& operator = (demo &obj)
        {
            cout << "Inside = operator"<<endl;
            cout<<"this->iNo :: " << this->iNo << "\tobj.iNo :: " <<obj.iNo <<endl;
            // ya method mule changes obj3 madhe reflect nahi zale
            // demo temp;
            // temp.iNo = obj.iNo;
            // return temp;

            this->iNo = obj.iNo;
            return *this;
        }
};


int main(void)
{
    cout<<"sizeof(demo) :: "<<sizeof(demo)<<endl;

    demo obj1;
    demo obj2(obj1);
    cout<<obj1.iNo<<endl;   //10
    cout<<obj2.iNo<<endl;   //20
    demo obj3(30);
    cout<<obj3.iNo<<endl;   //30
    obj3 = obj1;   //asa syntax lihio tenva operator call hota //= (obj3,obj1) -->expectation is obj3 madhe changes reflect vhave 
    cout<<obj3.iNo<<endl;    //10
    demo obj4 = obj2;   // asa syntax lihito tenva copy constructor call hoto
    cout<<obj4.iNo<<endl;   //20
    return 0;
}