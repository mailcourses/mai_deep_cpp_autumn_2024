#include <iostream>

struct Foo
{
    int a;
    virtual void foo() {}
};

struct Boo
{
    int a;
    //virtual int foo() { return 100500; }
    virtual bool foo() { return 100500; }
};

struct Moo
{
    int a;
    virtual void foo(int) {}
};

template<typename T>
concept HasFoo =
    requires(T t) {
        { t.foo() } -> std::same_as<void>;
        //{ t.foo() } -> std::convertible_to<int>;
        //{ t.foo() } -> std::same_as<int>;
    };

//template<class T>
template<HasFoo T>
void optimize(T t)
{
    std::cout << "optimize func for has_foo" << std::endl;
    t.foo();
}

template<class T>
void optimize(T t)
{
    std::cout << "not optimize" << std::endl;
    //t.foo(); <-- ошибка
}

int main()
{
    {
        Foo foo;
        optimize(foo);
    }
    {
        Boo boo;
        optimize(boo);
    }
    {
        Moo moo;
        optimize(moo);
    }
}
