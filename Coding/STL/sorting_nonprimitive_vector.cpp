
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class emp
{
    public:
    
    int id;
    string name;
    
    emp(int id,const string &refstr)
    {
        this->id = id;
        this->name = refstr;
    }
};

bool compare(const emp &lhs,const emp &rhs)
{
    return (lhs.id<rhs.id);
}
int main(void)
{
    vector<emp>vec;
    vec.push_back(emp(10,"kedar"));
    vec.push_back(emp(5,"k"));
    vec.push_back(emp(30,"ke"));
    vec.push_back(emp(12,"keda"));
    vec.push_back(emp(1,"r"));

    vector<emp>::iterator it;
    cout<<"Before Sorting :: "<<endl;
    for(it = vec.begin();it!= vec.end();++it)
    {
       cout<<it->id<<"\t"<<it->name<<endl;
    }
  
    sort(vec.begin(),vec.end(),&compare);
  
    cout<<"After Sorting :: "<<endl;
    
    for(it = vec.begin();it!= vec.end();++it)
    {
       cout<<it->id<<"\t"<<it->name<<endl;
    }

    return 0;
}