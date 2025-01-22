#include <iostream>

int main() 
{ 
    int arr[] = {10, 20, 30, 40, 50}; 
    int* ptr1 = arr; 
    int* ptr2 = arr + 4; 
    std::cout << (ptr2 - ptr1) << std::endl; 
    
    // 1st part 
    std::cout << *(ptr1 + 3) << std::endl; 
    // 2nd part 
    std::cout << *(ptr2--) << std::endl; 
    // 3rd part 
    std::cout << *(++ptr1) << std::endl; 
    // 4th part 
    return 0; 
} 