#include<iostream>
 
using namespace std;


//Explicit keyword in C++
 
//Implicit conversion
 
//class demo
//{
//  int iNo;
//public:
//  demo(int i)
//  {
//    iNo = i;
//  }
//
//  int getNo(demo d)
//  {
//    return d.iNo;
//  }
//};
 
class demo
{
  int iNo;
public:
  demo(int i)
  {
    iNo = i;
  }
 
  int getNo(demo d)
  {
    return d.iNo;
  }
};
 
int main()
{
  demo d(10);
  cout << d.getNo(10) << endl;  //compiler performs implicit conversion of demo object to int
 
  return 0;
}