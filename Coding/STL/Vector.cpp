#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{

    //## Creation

    vector<int> v1 {1,2,3,4};
    vector<int> v2 (4,2);
    vector<int> v3 {v1};

    //## Iterate vector
    for(int i = 0; i<v1.size();i++)
    {
        cout<<v1[i]<<"\t";
    }
    cout<<endl;

    vector<int> :: iterator it;
    for(it = v2.begin(); it != v2.end(); ++it)
    {
        cout<<(*it)<<"\t";  // 2   2   2   2
    }
    
    cout<<endl;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);   //It is less efficient due to copying or moving the object.
    
    //## Size and Capacity

    cout<<"v1.size() :: "<< v1.size() << endl;  //12
    cout<<"v1.capacity() :: "<< v1.capacity() << endl;  //16

    v1.shrink_to_fit();
    cout << "v1.shrink_to_fit() :: size :: "<< v1.size() << endl;   // 12
    cout << "v1.shrink_to_fit() :: capacity :: "<< v1.capacity() << endl; //12


    //## Inserting elements

    /*
    
    Key Differences
        Copy/Move vs. Direct Construction:
        insert copies or moves an existing object into the vector.
        emplace constructs the object directly at the location, avoiding the overhead of copying or moving.
        Performance:

        emplace can be more efficient because it constructs the object directly in the vector, avoiding a copy or move.
        insert involves an additional step of copying or moving the object.
        Use Cases:

        insert is used when you have an existing object and want to insert it into the vector.
        emplace is used when you want to construct a new object directly at the desired position in the vector.
    */

    v1.emplace_back(111); //It is more efficient as it avoids the unnecessary copying or moving
    cout << *(v1.end() - 1) << endl;

    v1.insert(v1.begin() + 3, 222);
    v1.emplace(v1.begin() + 4, 333);
    cout<<endl;
    
    for(it = v1.begin(); it != v1.end(); ++it)
    {
        cout<<(*it)<<"\n";  
    }
    cout<<endl;

  
    //## Deleting elements
    cout << "after erase :: " << endl;
    it = v1.erase(v1.begin() + 3);//Returns an iterator pointing to the next element after deleted elements.
    while(it!=v1.end())
    {
        cout << *(it) << endl;
        ++it;
    }

    v1.pop_back();

    cout << *(v1.end() - 1) << endl;

    //## Useful Algorithm
    
    cout <<"Sort ascending order :: "<< endl << endl;
    sort(v1.begin(), v1.end()); //Ascending order
    for(int i = 0; i<v1.size();i++)
    {
        cout<<v1[i]<<"\t";
    }
    cout << endl << "Sort descending order :: "<< endl;

    sort(v1.begin(), v1.end(),greater<>()); //Descscending order
    for(int i = 0; i<v1.size();i++)
    {
        cout<<v1[i]<<"\t";
    }
    
    cout<<endl <<"Reverse :: "<<endl;
    reverse(v1.begin(), v1.end());
    for(int i = 0; i<v1.size();i++)
    {
        cout<<v1[i]<<"\t";
    }

    it = find(v1.begin(), v1.end(), 444);
    if(it!=v1.end())
    {
        cout << "\n\n Element found \n";
    }
    else
    {
        cout << "\n\n Element not found \n";
    }

    cout<<"Min elemenet :: "<< *(min_element(v1.begin(), v1.end())) <<endl;
    cout<<"Max elemenet :: "<< *(max_element(v1.begin(), v1.end())) <<endl;
    
    return 0;
}
