#include <iostream>
void freeMemory(int* ptr1, int* ptr2) 
{
     delete ptr1; 
     delete ptr2; 
} 

int main() 
{ 
    int* p1 = new int; 
    *p1 = 100; 
    int* p2 = p1; 
    freeMemory(p1, p2); 
    std::cout << "Value of p1: " << *p1 << std::endl; 
    return 0; 
} 