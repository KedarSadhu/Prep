#include<iostream>
#include<cstring>
using namespace std;

class person
{
	public:
    char arr[10];
	int id;
	
    person()
    {
        arr[0] = 'K';
        arr[1] = 'e';
        arr[2] = 'd';
        arr[3] = 'a';
        arr[4] = 'r';
        arr[5] = '\0';
        arr[6] = '\0';
        arr[7] = '\0';
        arr[8] = '\0';
        arr[9] = '\0';
    }

    person(const char *ptr)
    {
        this->id = 0;
        strcpy(this->arr,ptr);
    }
	person(person &refobj)
	{
		this->id = refobj.id;
		//this->arr = refobj.arr;
		strcpy(this->arr,refobj.arr);
	}
	
	person &operator =(person &refobj)
	{
		if(this != &refobj)
		{
			this->id = refobj.id;
			strcpy(this->arr,refobj.arr);
		}
		return *this;
	}
	
};

int main()
{
    person obj;
    cout<<"obj.arr :: " << obj.arr<<endl;
    person obj2("Sadhu");
    cout<<"obj2.arr :: " << obj2.arr<<endl;

    person obj1(obj);	
    cout<<"obj1.arr :: " << obj1.arr<<endl;

    obj1 = obj2; // =(obj2,obj)
    cout<<"obj1.arr :: " << obj1.arr<<endl;

    return 0;
}