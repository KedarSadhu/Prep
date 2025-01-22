#include <iostream>
int main() 
{ 
    int x = 10; 
    int* ptr1 = &x; 
    int** ptr2 = &ptr1; 
    *ptr1 = 20; 
    *ptr2 = nullptr; 
    std::cout << x << std::endl;    //20
    std::cout << *ptr1 << std::endl; //crash cant derefer nullptr
    return 0; 
} 