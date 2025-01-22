#include<iostream>
#include<memory>
using namespace std;

class Array
{
 public:
    int size;
    int* data;

    Array(int size)
    {
        cout<<"default\n";
        this->size =size;
        this->data = new int[size];
    }

    /*Array(const Array& other)
    {
        cout<<"copy\n";
        this->size = other.size;
        this->data = new int[other.size];

        memcpy(this->data,other.data,other.size);
    }*/
    ~Array()
    {
        if(data != nullptr)
            delete[] data;
    }

};

int main(void)
{
    Array first(20);
    first.data[0] = 25;
    Array copy = first;
    cout<< first.data[0] << "\t" <<copy.data[0] <<endl;
    first.data[0] = 10; //segmentation fault if we dont give our copy constructor
    cout<< first.data[0] << "\t" <<copy.data[0] <<endl;

    exit(0);
}

/*

jar apn constructor nahi dila tr swatha compiler 
copy constructor deto .
tyane dilela copy constructor -->

Array(const Array &other)
{
    this -> size = other.size;
    this -> data = other.data; 
}
yane shallow copy zali navin heap memory create nahi zali
ata 2 pointer milun ekach heap memory la baghtayet ani jenva 
copy (object) cha scope sampto ani destrctor call hoto.
destructor memory deallocate zali .
ata first ti deallocated memory access karayala gela ani 
segmentation fault ala.

yachyavr solution mhnje apn apla copy constructor liha tyat
heap memory allocate kara ani copy kara data i.e deep copy

Array(const Array& other)
{
    this->size = other.size;
    this->data = new int[other.size]

    memcpy(this->data,other.data,other.size)
}
*/