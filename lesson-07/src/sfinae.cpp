#include <iostream>
#include <type_traits>

struct Foo
{
    int a;
    virtual void foo() {}
};

struct Boo
{
    int a;
    virtual void foo() {}
};

struct Moo
{
    int a;
    virtual void foo(int) {}
};

namespace my
{
template<class T>
struct is_pod
{
    static const bool value = false;
};

template<>
struct is_pod<int>
{
    static const bool value = true;
};

template<class T, class Y>
struct is_same
{
    static const bool value = false;
};

template<class T>
struct is_same<T, T>
{
    static const bool value = true;
};

template<class T>
class has_foo
{
public:
    static const bool value = my::is_same<void, decltype(my::has_foo<T>::check(static_cast<T*>(nullptr)))>::value;
private:
    template<class U>
    static auto check(U* u) -> decltype(u->foo());

    // Вариантивная функция.
    static int check(...);
};

/*
template<>
struct has_foo<Foo>
{
    static const bool value = true;
};
*/

} // namespace my

template<class T>
void optimize(T t, typename std::enable_if<my::has_foo<T>::value>::type* = nullptr)
{
    std::cout << "optimize func for has_foo" << std::endl;
    t.foo();
}

template<class T>
void optimize(T t, typename std::enable_if<!my::has_foo<T>::value>::type* = nullptr)
{
    std::cout << "not optimize" << std::endl;
    //t.foo(); <-- ошибка
}

int main()
{
    std::cout << "int is pod? " << std::boolalpha << std::is_pod<int>::value << std::endl;
    std::cout << "Foo is pod? " << std::boolalpha << std::is_pod<Foo>::value << std::endl;

    std::cout << "int is my::pod? " << std::boolalpha << my::is_pod<int>::value << std::endl;
    std::cout << "Foo is my::pod? " << std::boolalpha << my::is_pod<Foo>::value << std::endl;

    Foo foo;
    optimize(foo);

    int no_foo;
    optimize(no_foo);

    Boo boo;
    optimize(boo);

    Moo moo;
    optimize(moo);
}
