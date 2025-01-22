#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class demo
{
    public:
    int id;
    string name;
    string addr;

    demo(int no, string nm,string ad)
    {
        id = no;
        name = nm;
        addr = ad;
    }
    void display()
    {
        cout<<"id :: "<<id<<"\tname :: "<<name<<"\taddr :: "<<addr<<endl;
    }
};
int main(void)
{
    vector<demo*> vec;

    vec.push_back(new demo(20,"kedar","pune"));
    vec.push_back(new demo(10,"suresh","pune"));
    vec.push_back(new demo(01,"snehal","pune"));
    vec.push_back(new demo(22,"patil","pune"));
    vec.push_back(new demo(5,"bedds","pune"));

    //sort(vec.begin(),vec.end());

    vector<demo *>::iterator it1;
    vector<demo *>::iterator it2;

    int i = 0;
    demo *temp = nullptr;

    for(it1 = vec.begin(); it1!= vec.end();++it1)
    {
       for(it2 = vec.begin(); it2!= vec.end();++it2)
       {
            if((*it1)->id < (*it2)->id)
            {
                temp = (*it1);
                (*it1) = (*it2);
                (*it2) = temp;
            }
       }
    }

    for(it1 = vec.begin(); it1!= vec.end();++it1)
    {
        (*it1)->display();
    }
    return 0;
}