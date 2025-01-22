#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
    vector<int>vec{10,90,50,20,40,2};

    sort(vec.begin(),vec.end());

    vector<int>::iterator it;

    for(it = vec.begin();it<vec.end();++it)
        cout<<(*it)<<"\t";    

    int ele_tobe_searched =40;
    vector<int>::iterator it1 = find(vec.begin(),vec.end(),ele_tobe_searched);
    cout<<"\n searched ele :: "<<(*it1)<<endl;

    return 0;
}