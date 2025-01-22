#include<iostream>

using namespace std;

class ComplexNumbers
{
    int real;
    int imaginary;

    public:
    ComplexNumbers(int r = 0,int i =0)
    {
        real = r;
        imaginary = i;
    }

    ComplexNumbers operator +(ComplexNumbers &refObj)
    {
        ComplexNumbers temp;
        temp.real = this->real + refObj.real;
        temp.imaginary = this->imaginary + refObj.imaginary;
        return temp;
    }

    void display()
    {
        cout << real << " + i" << imaginary;
    }
};

int main()
{
    ComplexNumbers c1(9, 2);
    ComplexNumbers c2(2, 9);

    ComplexNumbers c3 = c1 + c2;
    c3.display();
    return 0;
}