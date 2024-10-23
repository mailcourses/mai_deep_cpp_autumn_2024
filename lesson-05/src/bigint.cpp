#include "bigint.hpp"

int main()
{
    int a1[2] = {1, 7};
    int a2[2] = {1, 9};
    BigInt b1(a1);
    BigInt b2(a2);
    BigInt res = b1 + b2;
    //res << std::cout << std::endl;
    std::cout << res << std::endl;
}
