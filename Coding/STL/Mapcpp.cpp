#include<iostream>
#include<string>
#include<map>
#include<algorithm>


using namespace std;

void display(map<int,string>&mp)
{
    cout << "\n\n";
    map<int, string>::iterator it;
    for (it = mp.begin(); it != mp.end();++it)
    {
        cout << it->first << "\t";
        cout << it->second << endl;
    }
}

int main()
{
    map<int, string> mp1;

    mp1.insert(pair<int, string>(10, "Kedar")); //C++98
    mp1.insert({2, "Snehal"});//initializer list introduced in C++11
    mp1[12] = "Sadhu";  // C++11 and later
    /*
        2       Snehal
        10      Kedar
        12      Sadhu
    */
    display(mp1);

    //Trying to insert same key
    mp1.emplace(2, "MR.");  //ignored -> no effect //C++14 and later
    mp1.insert({2, "MR."}); //ignored -> no effect
    mp1.insert(pair<int, string>(2, "MR.")); //ignored -> no effect
    /*
        2       Snehal
        10      Kedar
        12      Sadhu
    */
    display(mp1);

    //C++17 ->
    mp1.insert_or_assign(2, "MR."); //insert if key does not exist, or update value if key exists
    /*
        2       MR.
        10      Kedar
        12      Sadhu
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
        10      Kedar
        12      Sadhu
    */
    display(mp1);

    return 0;
}