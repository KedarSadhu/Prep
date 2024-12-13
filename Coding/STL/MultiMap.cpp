#include<iostream>
#include<string>
#include<map>
#include<algorithm>


using namespace std;

void display(multimap<int,string>&mp)
{
    cout << "\n\n";
    multimap<int, string>::iterator it;
    for (it = mp.begin(); it != mp.end();++it)
    {
        cout << it->first << "\t";
        cout << it->second << endl;
    }
}

int main()
{
    multimap<int, string> mp1;

    mp1.insert(pair<int, string>(1, "Kedar")); //C++98
    mp1.insert({2, "Snehal"});//initializer list introduced in C++11
    mp1.insert(pair<int, string>(12, "Keda")); //C++98
    mp1.insert(pair<int, string>(13, "Ked")); //C++98
    mp1.insert(pair<int, string>(9, "Ke")); //C++98

    /*
        1       Kedar
        2       Snehal
        9       Ke
        12      Keda
        13      Ked
    */
    display(mp1);

    mp1.emplace(2, "MR.");  //allowed - multimap allows duplicate keys //C++14 and later
    mp1.insert({2, "MRS."}); //allowed - multimap allows duplicate keys
    
    /*
        1       Kedar
        2       Snehal
        2       MR.
        2       MRS.
        9       Ke
        12      Keda
        13      Ked
    */
    display(mp1);

    if(mp1.find(5) != mp1.end())
    {
        cout << "\n\nKey found";
    }
    else
    {
        cout <<"\n\nKey not found";
    }

    mp1.erase(2);

    /*
        1       Kedar
        9       Ke
        12      Keda
        13      Ked
    */
    display(mp1);

    return 0;
}