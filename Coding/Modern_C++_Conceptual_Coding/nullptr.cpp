#include<iostream>
 
using namespace std;

//nullptr
int main()
{
 int *p = nullptr;
 cout << "address in p : " << p << endl;

 p = new (int);
 cout << "address in p : " << p << endl;

 *p = 10;

 delete(p);
 cout << "address in p : " << p << endl;

 p = nullptr;

 if (!p)
 {
   cout << "memory deallocation done\n";
 }
 return 0;
}