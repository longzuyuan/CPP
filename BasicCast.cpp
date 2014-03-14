#include <iostream>

std::string global_str;
int global_int;

struct Foo {};
int main()
{
    unsigned u = 10, u2 = 42;

    std::cout<<u2-u<<std::endl;
    std::cout<<u-u2<<std::endl;

    int i = 10, i2 = 42;
    std::cout<<i-i2<<std::endl;
    std::cout<<i2-i<<std::endl;
    std::cout<<i-u<<std::endl;
    std::cout<<u-i<<std::endl;

    signed char c = 256;
    std::cout<<c<<std::endl;

    std::cout<<"Who goes with F\145rgus?\012\n";

    int month = 07;
    std::cout<<month<<std::endl;;

    //std::cin>>int input_v;
    int ii = {3.14};
    long double w;
    double s = w = 9999.99;
    int a{w};
    std::cout<<ii<<" "<<w<<" "<<s<<" "<<a<<std::endl;

    int local_int;
    std::string local_str;
    std::cout<<global_str<<" : "<<global_int<<" : "<<local_int<<" : "<<local_str<<std::endl;

    int _ = 5;
    //int 1_or_2;
    int __A = 6;
    int Double = 3.14;
    std::cout<<_<<__A<<std::endl;


    int iii=100, sum=0;
    for(int iii=0; iii<5; iii++) sum+=iii;
    std::cout<<iii<<" "<<sum<<std::endl;

    int p, &r1=p;
    p=5;r1=10;
    std::cout<<p<<" "<<r1<<" "<<std::endl;

    //double *dp = &i;
    //int *ip = i;
    void *pp=&i;
    //*pp;

    int a1=42;
    int &ra1 = a1;
    int const &ra2 = a1;
    ra1 = 0;
    //ra2 = 0;
    std::cout<<"ra2:"<<ra2<<std::endl;
    double dval = 3.14;
    const int &rdval = dval;
    dval = 4.1;
    std::cout<<rdval<<std::endl;
    const int b1 = -1, &b2 = 0;
//    const int &const r2=1;
//    int *p1, *const p2;
    return 0;
}
