#include<iostream>
using namespace std;

class demo1
{
    int m_iNo1;
    int m_iNo2;

    public:
        demo1(int no1 = 10,int no2 = 20)
        {
            m_iNo1 = no1;
            m_iNo2 = no2;
        }

        demo1 operator +(demo1 &refObj)
        {
            return (demo1(m_iNo1+refObj.m_iNo1 , m_iNo2+refObj.m_iNo2));
        }

        void display()
        {
            cout<<"m_iNo1 = "<<this->m_iNo1<<"\tm_iNo2 = "<<this->m_iNo2 <<endl;
        }

};



int main(void)
{
    demo1 obj1;
    demo1 obj2(30,40);

    demo1 obj3 = obj1+obj2;
    /*
        obj1+obj2
        call --> +(obj1,obj2)
        Defination -->+(demo1 * const this, demo1 &refObj)
    */

    obj3.display();

    exit(0);
}