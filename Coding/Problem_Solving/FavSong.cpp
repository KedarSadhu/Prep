#include<iostream>
#include<vector>
#include<map>

using namespace std;

int findfav(vector<int> &pl)
{
    map<int, int> plcount;
    map<int, int>::iterator it;

    for (int i = 0; i < pl.size();i++)
    {
        if((it = plcount.find(pl[i]))!= plcount.end())
        {
            ++(it->second);
        }
        else
        {
            plcount.insert(make_pair(pl[i], 1));
        }
    }
    int max = 0;
    for (it = plcount.begin(); it != plcount.end();++it)
    {
        if(it->second > max)
        {
            max = it->second;
        }
    }
    
    return max;
}

int main(void)
{
    int count=0;
    cout << "Enter number of songs ::";
    cin >> count;
    
    vector<int> vec;
    int num;

    cout << "Enter songs frequancy ::" << endl;
    for (int i = 0; i < count;i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    cout << "number of fav singer :: " << findfav(vec) << endl;
    return 0;
}