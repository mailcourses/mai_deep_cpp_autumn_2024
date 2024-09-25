#include "boo.hpp"
#include <cstdint>

//static float PI = 3.1415;
const int MAGIC_NUMBER = 100500;

int foo()
{
    return 100;
}

int foo(int num)
{
    return foo() + num;
}

int main()
{
    int result = 0;
    for (uint32_t i = 1; i > 0; i--)
    {
        result += foo();
    }
    return result;
}
