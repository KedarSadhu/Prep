#include<iostream>

using namespace std;

//2D array -> arr[3][3] --> arr[rows][cols]
/*
            [300]   ->  [1  2   3]
[100]/_     [400]   ->  [4  5   6]
     \      [500]   ->  [7  8   9]
*/
int main()
{
    int **pptr = nullptr;
    int rows = 0;
    int cols = 0;
    int num = 0;

    cout<<"Enter number of rows for 2d array :: ";
    cin>>rows;

    cout<<"Enter number of column for 2d array :: ";
    cin>>cols;

    try
    {
        pptr = new int*[rows];  //allocating memory for pointers to hold cols

        for(int iCounter1 = 0; iCounter1 < rows;iCounter1++)
        {
            pptr[iCounter1] = new int[cols];
        }

        for (int iCounter1 = 0; iCounter1 < rows;iCounter1++)
        {
            for (int iCounter2 = 0; iCounter2 < cols;iCounter2++)
            {
                cout << "Enter number at arr[" << iCounter1 << "][" << iCounter2 << "] ::";
                cin >> num;
                pptr[iCounter1][iCounter2] = num;
            }
            cout << endl;
        }

        cout << "\n\nDisplaying dynamic array :: \n";
        for (int iCounter1 = 0; iCounter1 < rows;iCounter1++)
        {
            for (int iCounter2 = 0; iCounter2 < cols;iCounter2++)
            {
                cout << pptr[iCounter1][iCounter2] <<"\t";
            }
            cout << endl;
        }

        cout << "\n\ndeleting allocated memory\n";

        for (int iCounter1 = 0; iCounter1 < rows;iCounter1++)
        {
            delete[] pptr[iCounter1];
        }

        delete[] pptr;
        cout << "\nDeallocation successfull\n";
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}