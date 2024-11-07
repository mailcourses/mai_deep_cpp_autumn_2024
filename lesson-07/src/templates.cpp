#include "foo.hpp"

int main()
{
    Foo<std::string, 3.14> foo_str("hello world");
    Foo<int, 3.14> foo_int(100500);
    Foo<double, 3.14> foo_dbl(3.1415);
    Foo<Boo, 3.14> foo_boo(Boo{});
}
