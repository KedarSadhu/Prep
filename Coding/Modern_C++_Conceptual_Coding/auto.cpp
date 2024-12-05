#include<iostream>
 
using namespace std;

//auto
int main()
{
 auto x = 10;
 cout << typeid(x).name() << endl; //int

 x = 1.2;
 cout << x << endl;  //1 -->implicit type casting --demotion -- loss of data
 cout << typeid(x).name() << endl; //int

 return 0;
}