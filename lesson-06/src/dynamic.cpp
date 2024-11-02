#include <iostream>
#include <cstring>

class Base
{
public:
    Base() = default;
    virtual void foo()
    {
        std::cout << "Base::foo" << std::endl;
    }
};

class Derived : public Base
{
public:
    Derived() = default;
    void foo() override
    {
        std::cout << "Derived::foo" << std::endl;
    }

    void boo()
    {
        std::cout << "Derived::boo" << std::endl;
    }
};


class Derived2 : public Base
{
public:
    Derived2() = default;
    virtual void foo() override
    {
        std::cout << "Derived2::foo" << std::endl;
    }
    void moo()
    {
        std::cout << "Derived2::moo" << std::endl;
    }
};

void callback(Base* base)
{
    base->foo();
    Derived* d1 = dynamic_cast<Derived*>(base);
    if (d1 != nullptr) {
        d1->boo();
    }

    Derived2* d2 = dynamic_cast<Derived2*>(base);
    if (d2 != nullptr) {
        d2->moo();
    }
}

void callback(Base& base)
{
    base.foo();
    try {
        Derived& d1 = dynamic_cast<Derived&>(base);
        d1.boo();
    } catch(std::bad_cast) {}

    try {
        Derived2& d2 = dynamic_cast<Derived2&>(base);
        d2.moo();
    } catch(std::bad_cast) {}
}

int main(int argc, char** argv)
{
    Base* base = nullptr;
    if (strcmp(argv[1], "d1") == 0) {
        base = new Derived();
    }
    else if (strcmp(argv[1], "d2") == 0) {
        base = new Derived2();
    }
    callback(base);

    callback(*base);
}
