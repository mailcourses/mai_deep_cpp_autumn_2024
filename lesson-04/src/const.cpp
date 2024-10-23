#include <iostream>

void moo(int num)
{
}

struct Foo
{
    Foo() = default;
    void foo(/*const Foo* this,*/ int num) const
    {
        this->num_ += num;
    }

    void boo(int num)
    {
        num_ += num;
    }

    static void moo(/**/int num)
    {
        ///*this->*/num_ += num;
        ///*this->*/foo(num);
        ::moo(num);
    }
public:
    mutable int num_ = 100;
};

int main()
{
    Foo foo1;
    const Foo foo2;
    foo1.foo(10);
    foo1.boo(20);
    foo2.foo(30);
    //foo2.boo(40);
    Foo::moo(50);
    moo(50);
}
