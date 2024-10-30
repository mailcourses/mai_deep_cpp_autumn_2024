#include <iostream>

struct A
{
    A()
    {
        std::cout << "A ctr" << std::endl;
        //try {
        a = new int[1024];
            throw std::exception();
        /*} catch(...) {
            std::cout << "catch up" << std::endl;
        }*/
    }

    ~A()
    {
        delete[] a;
        std::cout << "A dctr" << std::endl;
    }
    int * a;
};

struct B : public A
{
    B() : A()
    {
        std::cout << "Fantom B ctr" << std::endl;
    }

    ~B()
    {
        std::cout << "Fantom B dctr" << std::endl;
    }

};

int main()
{
    try {
    B b;
    } catch(...) {
        std::cout << "catch up main" << std::endl;
    }
}
