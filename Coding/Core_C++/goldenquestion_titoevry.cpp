#include<iostream>
class Base
{
 virtual void method()
 {
	std::cout << "from Base"<< std::endl;
 }
public:
 virtual ~Base() 
 {
	std::cout<<"In Base destructor ()"<<std::endl;
	method();
 }
 void baseMethod() 
 {
	method();
 }
};

class A: public Base 
{
  void method() 
  {
	std::cout << "from A"<< std::endl;
  }
 public:
 ~A() 
 {
	std::cout<<"In A destructor ()"<<std::endl;
	method();
 }
};

int main(void)
{
 Base* base = new A;
 base->baseMethod();
 delete base;
 return 0;
}

/*
from A
bcz of delete base;->
In A destructor ()
from A
In Base destructor ()
from Base
*/