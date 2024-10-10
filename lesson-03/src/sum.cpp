#include <cstdarg>
#include <iostream>

int sum(size_t n, ...)
 {
    va_list args;
    va_start(args, n);
    int result{};
    int i = 0;
    while(n--) {
        auto next_element = va_arg(args, int);
        std::cout << "i = " << i << ", " << next_element << std::endl;
        result += next_element;
        ++i;
    }
    va_end(args);
    return result;
 }

struct Foo
{
    Foo() = default;
};

int main()
{
   return sum(3, 10, "abc", Foo());
}
