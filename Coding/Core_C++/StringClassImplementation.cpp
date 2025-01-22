#include<iostream>
#include<cstring>

using namespace std;

class MyString
{
    char * str;
    size_t len;

    public:

        MyString()
        {
            str = new char[1];
            *str = '\0';
            len = 0;
        }

        MyString(const char * s)
        {
            len =  strlen(s);
            str = new char[len + 1];
            strcpy(str,s);
        }

        MyString(const MyString &other)
        {
            cout<<"In copy constructor"<<endl;
            len =  strlen(other.str);
            str = new char[len + 1];
            strcpy(str,other.str);
        }

        ~MyString()
        {
            if(str)
                delete[]str;
        }

        MyString& operator= (const MyString &other)
        {
            cout<<"In copy assignment operator"<<endl;

            if(this != &other)  //check for self assignment
            {
                delete[] str;   //delete existing data
                
                //copy data from other object
                len = other.len;
                str = new char[len+1];
                strcpy(str,other.str);
            }
            
            return *this;
        }

        void display()
        {
            cout << str << endl;
        }
};

int main()
{
    MyString str1("Hello");
    str1.display();

    MyString str2(str1);    //copy constructor
    str2.display();

    MyString str3 = str2;   //copy constructor
    str3.display();

    MyString str4;
    str4 = str3;    //In copy assignment operator
    str4.display();

    return 0;
}