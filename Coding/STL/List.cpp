#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

void display(list<int> &lst)
{
    list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); ++it)
    {
        cout << *(it) << "\t";
    }
    cout << endl;
}

int main()
{
    //Creation
    list<int> l1{1, 2, 3, 4};
    list<int> l2 (4,2);
    list<int> l3 {l1};

    display(l2);    //2       2       2       2
    display(l3);    //1       2       3       4

    cout << "size :: " << l3.size() <<endl; //4 i.e num of elements

    //Insertion
    l1.push_front(10);
    l1.push_back(40);

    display(l1); //10      1       2       3       4       40

    // insert(iterator pos, value)
    l1.insert(next(l1.begin()), 11);
    l1.insert(find(l1.begin(), l1.end(), 3), 22);   // find 3 insert 22 before 3

    display(l1); //10      11      1       2       22      3     40

    l1.emplace_back(9);
    l1.emplace_front(7);
    l1.emplace(next(find(l1.begin(), l1.end(), 3)), 44);

    display(l1); //7       10      11      1       2       22       44       4       40      9

    //Deleting element
    l1.pop_back();
    l1.pop_front();

    l1.erase(find(l1.begin(), l1.end(), 2));
    cout << endl << "After deletion :: " << endl;
    display(l1); //10      11      1       22      3       44    40

    l1.remove(22);
    display(l1); //10      11      1       3       44      4     40


    return 0;
}