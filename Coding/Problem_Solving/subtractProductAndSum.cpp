/* Subtract the Product and Sum of Digits of an Integer
Input: n = 234
Output: 15 
Explanation: 
Product of digits = 2 * 3 * 4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15
*/

#include<iostream>
using namespace std;

int subtractProductAndSum(int n) ;

int main(void)
{
    int no = 0;
    cout << "Enter no :: ";
    cin>>no;

    cout << subtractProductAndSum(no) << endl;
    exit(0);
}


int subtractProductAndSum(int n) {

        int rem =0;
        int a = 1;
        int b = 0;

        while(n != 0)
        {
            rem = n % 10;
            n = n / 10;
            a = rem * a;
            b = rem + b; 
        }
        
        cout << "a = " <<a <<"\t b = " <<b<<endl;
        return (a-b);
}