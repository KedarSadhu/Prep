#include<iostream>
 
using namespace std;

//Constructor delegation
class box
{
 int x;
 int y;

public:
 box(int w, int h)
 {
   x = w;
   cout << "width : " << x << endl;

   y = h;
   cout << "height : " << y << endl;
   
 }

 box(int s) :box(s, s) //Constructor delegation
 {

 }
};

int main()
{
 box rectangle(10, 20);
 box square(10);

 return 0;
}
