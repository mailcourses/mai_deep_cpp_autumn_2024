#include <iostream>

#include "square.hpp"

extern "C" {
    int* boo()
    {
        int* i = new int(10);
        return i;
    }
}

void foo()
{
    int i = 0;
    static int j = 0;
    std::cout << "i = " << i << ", j = " << j << std::endl;
    ++i; // i++
    // for (int i = 0; i < 100500; i++)
    // operator++(int) {
    //    int tmp = this->val;
    //    this->val += 1;
    //    return tmp;
    // }
    ++j;
}

int main()
{
    foo();
    foo();
    foo();
    //int *i  = boo();
    //
    return square(2);
}
