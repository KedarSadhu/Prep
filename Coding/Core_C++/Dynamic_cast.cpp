#include<iostream>
using namespace std;

class Animal
{
    public:
    virtual void speak()
    {
        cout<<"Animal speaks ...\n";
    }
};

class Dog : public Animal
{
    public:
    void speak()
    {
        cout<<"Dog barks ...\n";
    }

    void food()
    {
        cout<<"Eat dog food ...\n";
    }
};

class Cat : public Animal
{
    public:
    void speak()
    {
        cout<<"Cat meows ...\n";
    }
};

int main()
{
    Animal *ptr1 = new Dog(); //Upcasting
    ptr1->speak(); //Dog barks
    //ptr1->food();//not possible base class pointer cant call derived functn

    //Dog *dogPtr = new Animal(); // Downcasting error: invalid conversion from 'Animal*' to 'Dog*'

    /*The need for dynamic_cast

    When dealing with polymorphism, you’ll often encounter cases 
    where you have a pointer to a base class, 
    but you want to access some information that 
    exists only in a derived class*/

    //use dynamic cast to convert Base pointer into Derived 
    Dog *dogPtr = dynamic_cast<Dog *>(ptr1); //perfect downcast acchived using dynamic cast

    if(dogPtr)    
    {
        dogPtr->speak();
        dogPtr->food();  
    }
    else
    cout<<"Casting Failed" <<endl;

    Animal *ptr2 = new Cat();//upcasting
    ptr2->speak(); //Cat meows

    Cat *catPtr = dynamic_cast<Cat *>(ptr1); //he fail hoil karan ptr1 madhe dog cha addr ahe
    if(catPtr)    
        catPtr->speak();
    else
        cout<<"Casting Failed" <<endl;

    Cat *catPtr2 = dynamic_cast<Cat *>(ptr2); //passed as ptr2 have cat address
    if(catPtr2)    
        catPtr2->speak();
    else
        cout<<"Casting Failed" <<endl;

    return 0;
}
