/*
input = 5 output = 2
   5   --> 000000.....0101
A ~5   --> 111111.....1010
B mask --> 000000.....0111
A & B  --> 000000.....0010
*/



#include<iostream>
using namespace std;

int bitwiseComplement(int n)
{
        int mask = 0;
        int backup = n;
        if(n == 0)
            return 1;
            
        while(n!=0)
        {
            n = n>>1;
            mask = mask <<1 | 1;
        }

        //cout << ((~backup)& mask) ;
        return ((~backup)& mask);
}

int main(void)
{
    int no = 0;
    cout<<"Enter no : ";
    cin >> no;

    cout<<"Compliment :: "<<bitwiseComplement(no);
    
    exit(0);
}

