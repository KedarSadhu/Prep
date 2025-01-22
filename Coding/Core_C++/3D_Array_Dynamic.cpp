#include<iostream>

using namespace std;

int main()
{
    int ***ppptr = nullptr;
    int planes = 0;
    int rows = 0;
    int cols = 0;
    int num = 0;
    
    cout<<"Enter number of planes for 3d array :: ";
    cin>>planes;
    
    cout<<"Enter number of rows for 3d array :: ";
    cin>>rows;

    cout<<"Enter number of column for 3d array :: ";
    cin>>cols;

    try
    {
        ppptr = new int **[planes];

        for (int iCounter1 = 0; iCounter1 < planes;iCounter1++)
            ppptr[iCounter1] = new int *[rows];

        for (int iCounter1 = 0; iCounter1 < planes;iCounter1++)
        {
            for (int iCounter2 = 0; iCounter2 < rows;iCounter2++)
            {
                ppptr[iCounter1][iCounter2] = new int[cols];
            }
        }

        for (int iCounter1 = 0; iCounter1 < planes;iCounter1++)
        {
            for (int iCounter2 = 0; iCounter2 < rows;iCounter2++)
            {
                for (int iCounter3 = 0; iCounter3 < cols;iCounter3++)
                {
                    cout << "Enter number at arr[" << iCounter1 << "][" << iCounter2 << "]["<<iCounter3 <<"] ::";
                    cin >> num;
                    ppptr[iCounter1][iCounter2][iCounter3] = num;
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << "\n\nDisplaying dynamic array :: \n";
        for (int iCounter1 = 0; iCounter1 < planes;iCounter1++)
        {
            for (int iCounter2 = 0; iCounter2 < rows;iCounter2++)
            {
                for (int iCounter3 = 0; iCounter3 < cols;iCounter3++)
                {
                    cout<< ppptr[iCounter1][iCounter2][iCounter3] <<"\t";
                }
                cout << endl;
            }
            cout << endl;
        }

        cout << "\n\ndeleting allocated memory\n";
        for (int iCounter1 = 0; iCounter1 < planes;iCounter1++)
        {
            for (int iCounter2 = 0; iCounter2 < rows;iCounter2++)
            {
                delete[] ppptr[iCounter1][iCounter2];
            }
        }

        for (int iCounter1 = 0; iCounter1 < planes;iCounter1++)
        {
            delete[] ppptr[iCounter1];
        }

        delete[] ppptr;
        cout << "\nDeallocation successfull\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
     
}