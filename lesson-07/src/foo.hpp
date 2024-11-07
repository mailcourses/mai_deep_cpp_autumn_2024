#include <iostream>

template<class T, double NUMBER>
struct Foo
{
    Foo(T data);
    T data_;
};

struct Boo
{
    int attr = 0;
};

#include "foo.tpp"
