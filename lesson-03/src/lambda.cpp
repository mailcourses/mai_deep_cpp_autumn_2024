#include <iostream>

/*
int base = 7;

int func(int x, int y)
{
    return (x + y) % base;
}
*/

int main()
{
    int base = 7;
    auto func = [base](int x, int y) { return (x + y) % base; };
    int res = func(10, 20);
    std::cout << "res = " << res << std::endl;
    return 0;
}
