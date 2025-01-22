//Prime number --> Ase number jyana fakta 1 ne or swathanech bhag jato
//eg - 1,3,5,7,11,13,17 ...

#include<iostream>
using namespace std;

int main(void)
{
    int n = 10;
    bool flag = false;

    for (int i = 1; i<=n; ++i)
    {
       for (int j = 2 ; j<i ; j++) 
        { 
            if (i % j == 0) 
            {   
                flag = false;
                break;
            }
            else
            {
                flag = true;
            }

        }
     if (flag || i==1)
         cout<<i<<",";
    }

    exit(0);
}