#include<iostream>
using namespace std;

class demo
{
    int m_iNo1;
    int m_iNo2;
    public:
        demo(int no1=10,int no2=20)
        {
            m_iNo1 = no1;
            m_iNo2 = no2;
        }

        demo & operator ++()
        {
            cout<<"In preIncrement\n";
            ++m_iNo1;
            ++m_iNo2;
            return *this;
        }
        demo operator ++(int)
        {
            cout<<"\nIn PostIncrement\n";
            demo temp(m_iNo1,m_iNo2);
            m_iNo1++;
            m_iNo2++;
            return temp;
        }
        void display()
        {
            cout<<"m_iNo1 = " << m_iNo1 <<"\tm_iNo2 = "<<m_iNo2<<endl;    
        }
};


int main(void)
{
    demo obj1(50);
    demo obj2;

    obj2 = ++obj1;
    obj2.display();     //51,21
    obj1.display();     //51,21
    demo obj3(30);
    demo obj4;
    
    obj4 = obj3++;
    obj4.display();     //30,20
    obj3.display();     //31,21

    exit(0);
}