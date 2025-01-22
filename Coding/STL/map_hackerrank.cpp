#include<iostream>
#include<map>

using namespace std;

class demo
{
    map<string,int>stud;
    public:
        void modify_map(string name,int marks)   //case 1 :: 
        {
            map<string,int>::iterator it = stud.find(name);
            if(it == stud.end())   //not found
            {
                stud.insert(pair<string,int>(name,marks));
            }
            else
            {
                it->second = it->second + marks;
            }
        }
        
        void modify_map(string name)
        {
            stud.erase(name);
        }


        void display()
        {
            map<string,int>::iterator it;
            for(it = stud.begin();it!= stud.end();++it)
            {
                cout<<"name :: "<<it->first<<"\tmarks :: "<<it->second<<endl;
            }
        }

        void display(string name)
        {
            map<string,int>::iterator it = stud.find(name);
            cout<<"name :: "<<it->first<<"\tmarks :: "<<it->second<<endl;
        }

};


int main(void)
{
    demo obj;
    char ch;
    string name;
    int marks;
    
    do
    {

        cout<<"\nEnter choice ::";
        cin>>ch;

        switch(ch)
        {
            case '1':
                cout<<"Enter name :: ";
                cin>>name;
                cout<<"Enter marks ::";
                cin>>marks;
                obj.modify_map(name,marks);
                obj.display();
                break;
            
            case '2':
                cout<<"Enter name ::";
                cin>>name;
                obj.modify_map(name);
                obj.display();
                break;
            
            case '3':
                cout<<"Enter name ::";
                cin>>name;
                obj.display(name);
                break;
        }

        cout<<"\nYou want to continue (y/n) ::";
        cin>>ch;
    } while (ch=='y');
    
    return 0;
}