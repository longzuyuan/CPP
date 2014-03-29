#include <iostream>
#include <memory>
using namespace std;

class Parent
{
public:
    Parent()
    {
        cout<<"parent"<<endl;
    }

    virtual ~Parent()
    {
        cout<<"~parent"<<endl;
    }
};

class Child : public Parent
{
public:
    //Child()
    //{
    //    cout<<"child"<<endl;
    //}
    Child(int a)
    {
        cout<<"child "<<a<<endl;
    }

    ~Child()
    {
        cout<<"~child"<<endl;
    }
};
//Child *c3 = new Child;
//delete c3;
int main()
{
    //Child c2(1);
    
    Parent *p = new Child(1);
    delete p;
Child p1(1);
Child p2(2);
p2 = p1;
    //Child *c = new Child(1);
    
    cout<<p<<endl;
    //cout<<c<<endl;

    //delete c; 
    //delete p;
    //delete c3;
}
