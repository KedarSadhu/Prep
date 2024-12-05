#include<iostream>
using namespace std;

//can we inherit structur to the class?
//--> yes we can do 
// struct demo
// {
//     int i;
//     int j;
// };

// class test : public demo
// {
//     int k;
// };

// int main()
// {
//     cout<< "sizeof(demo) :: " <<sizeof(struct demo) <<endl;
//     cout<< "sizeof(test) :: " <<sizeof(class test) <<endl;
//     return 0;
// }

//Based on  Access specifire
/*
he cross verify karaycha asel tr main madhe derived obj ne print karaycha
Public inheritance-->
    public -> public
    protected -> protected
    private -> private   

Protected inheritance -->
    public -> protected
    protected -> protected
    private -> private
(He data members tumhi kuthlya hi derived class madhlya function madhe access karu shakta but main madhe tumhala issue yeil dobj ne public access karayla )    

Private inheritance -->
    public -> private
    protected -> private
    private -> private

(He data members grand child chya function madhe cant be accessible karn saglech derived madhe private zale)

*/

class base
{
    int i;
    public:
    int j;
    protected:
    int k;

    public:
    base()
    {
        i = 10;
        j = 20;
        k = 30;
    }
};

class d1 : public base
{
    int d1;
    public : 
    void d1Print()
    {   

       // cout<< i <<endl; //error: 'int base::i' is private within this context
        cout<< j <<endl;
        cout<< k <<endl;
    }
};

class d1_b : public d1
{
    public:
     d1_b()
     {
        cout<< j <<endl;
        cout<< k <<endl;
     }
};

class d2 : protected base
{
    int d2;
    public:
    void d2Print()
    {
       // cout<< i <<endl; //error: 'int base::i' is private within this context
        cout<< j <<endl;
        cout<< k <<endl;
    }
};

class d2_1: protected d2
{
    public:
    d2_1()
    {
       // cout<< i <<endl; //error: 'int base::i' is private within this context
        cout<< j <<endl;
        cout<< k <<endl;
    }
};

class d3 : base
{
    int d3;
    public:
    void d3Print()
    {
       // cout<< i <<endl; //error: 'int base::i' is private within this context
        cout<< j <<endl;
        cout<< k <<endl;
    }
};

class d3_1: d3
{
    public:
    d3_1()
    {
        // cout<< i <<endl; //error: 'int base::i' is private within this context
        //cout<< j <<endl;  
        //cout<< k <<endl;
    }
};

int main()
{
    // kuthlya pan typecha inheritance asu de sagle khali yetatch 
    cout<<"base :: "<<sizeof(class base)<<endl; //12
    cout<<"d1 : public base :: "<<sizeof(class d1)<<endl;   //16
    cout<<"d2 : protected base :: "<<sizeof(class d2)<<endl; //16
    cout<<"d3 : base :: "<<sizeof(class d3)<<endl; //16

    base b;
    d1 d1obj;
    d2 d2obj;
    d3 d3obj;

    //cout<<"d2obj.j :: "<<d2obj.j<<endl; //j is public in base but due to protected inheritance j convrted to protected

    // d1obj.d1Print();
    // d2obj.d2Print();
    // d3obj.d3Print();

    d1_b d1_bobj;
    d2_1 d2_1obj;
    d3_1 d3_1obj;

    return 0;
}