#include<iostream>
#include <memory>  // For smart pointers

using namespace std;

class demo
{
public:

  demo()
  {
    cout << "In constructor :: " << this;
    cout << endl;
  }
  ~demo()
  {
    cout << "In destructor :: " << this; 
    cout<< endl;
  }

  void fun()
  {
    cout << "In fun()" << endl;
  }
};

void useUnique_Ptr()
{
  //1. Using unique_ptr --> ekach owner
  cout << "Using unique_ptr :: \n";
  unique_ptr<demo> uPtr1 = make_unique<demo>();
  uPtr1->fun();

  unique_ptr<demo> uPtr2 = make_unique<demo>();
  uPtr2->fun();
  /*
      make_unique<demo>()
      dynamically allocates memory for a new demo object on the heap using the new operator

      uPtr1,uPtr2 madhe different addresses 2 vegvegle object
  */

  //demo obj;
  //cout << &obj << endl;
  //unique_ptr<demo> uPtr3(&obj); //obj sathi pahile destructir call zala ani to gela ani jenva uptr3 sathi call zala tenva obj already deleted ahe-->crash
 
  unique_ptr<demo> uPtr3(new demo);
  uPtr3->fun();

  cout << "uPtr1 = " << uPtr1 << "\tuPtr2 = " << uPtr2 << "\tuPtr3 = " << uPtr3 << endl;

  // unique_ptr<demo> uPtr4(&obj);
  // uPtr4->fun();

  /*
      Purpose of unique pointer --> eka object la ekach jan baghnar ani scope sampla ki automatic delete honar

      2 unique ptr jar ekach object la baghayla lagle tr kay hota?
      -->CRASH

      jenva scope sampto tenva detructor call hoil ani uPtr1 jya object la point kartoy ti memory deallocate hoil.
      ata prt uPtr4 cha pan scope sampla destructor call zala pn obj1 is already deleted ahe prt delete nahi hou shakat
      so CRASH
  */
}

void useShared_Ptr()
{
  cout << "Using shared_ptr :: \n";
  shared_ptr<demo> sPtr1 = make_shared<demo>();
  sPtr1->fun();

  {
    shared_ptr<demo> sPtr2 = make_shared<demo>();
    shared_ptr<demo> sPtr3 = sPtr1; //Refcount++
    cout << "Reference count (sPtr1) :: " << sPtr1.use_count() << endl;
    cout << "Reference count (sPtr2) :: " << sPtr2.use_count() << endl;
    cout << "Reference count (sPtr3) :: " << sPtr3.use_count() << endl;
  }

  cout << "Reference count decreased (sPtr1) :: " << sPtr1.use_count() << endl;
}

void useWeak_Ptr()
{
  //Non - owning Reference, used to avoid circular references
  cout << "Using weak_ptr :: \n";

  shared_ptr<demo> sPtr1 = make_shared<demo>();
  sPtr1->fun();

  weak_ptr<demo> wPtr1 = sPtr1; // weak_ptr does not affect reference count
  
  //wPtr1->fun(); //not allowed swathach kahi astitva nahi dependent on shared ptr
  
  if (auto lockedPtr = wPtr1.lock()) // lock() returns a shared_ptr if the object is still valid
  {  
    lockedPtr->fun();
  }

  cout << "Reference count (sPtr1) :: " << sPtr1.use_count() << endl;

}

int main()
{

  useUnique_Ptr();

  cout << "\n\n";

  useShared_Ptr();

  cout << "\n\n";

  useWeak_Ptr();

  return 0;
}



