#include<iostream>
 
using namespace std;
 
//Lambda and its diffrent types of capture list

int main()
{

 int iNo1 = 10;
 int iNo2 = 20;

 //Capture by the value
 auto iRes1 = [iNo1, iNo2]() { return iNo1 + iNo2; };
 
 //auto iRes = [iNo1, iNo2]() { iNo1++; return iNo1 + iNo2; }; //This is not allowd , Reason -> Expression must be modifiable L value;
 cout << "Capture by the value :: " << iRes1(); //30
 cout << "\tiNo1 = " << iNo1 << " iNo2 = " << iNo2 << endl;  // 10 20

 //Capture by the reference
 auto iRes2 = [&iNo1, &iNo2]() { iNo1++; iNo2++; return iNo1 + iNo2; };
 cout << "Capture by the reference :: " << iRes2(); // 32
 cout << "\tiNo1 = " << iNo1 << " iNo2 = " << iNo2 << endl;  // 11 21

 //Mixed capture 
 auto iRes3 = [iNo1, &iNo2]() {iNo2--; return iNo1 + iNo2; };
 cout << "Mixed capture :: " << iRes3(); // 31
 cout << "\tiNo1 = " << iNo1 << " iNo2 = " << iNo2 << endl;  // 11 20

 //Capture all by value
 auto iRes4 = [=]() {return iNo1 + iNo2; };
 cout << "Capture all by value :: " << iRes4(); // 31
 cout << "\tiNo1 = " << iNo1 << " iNo2 = " << iNo2 << endl;  // 11 20

 //Capture all by reference
 auto iRes5 = [&]() {iNo1--; iNo2--; return iNo1 + iNo2; };
 cout << "Capture all by reference :: " << iRes5(); // 29
 cout << "\tiNo1 = " << iNo1 << " iNo2 = " << iNo2 << endl;  // 10 19
 

 //passing param to lambda
 auto iRes6 = [=](int x) {return iNo1 + iNo2 + x; };
 cout << "passing param to lambda iRes6(5) :: " << iRes6(5); // 34
 
 return 0;
}
