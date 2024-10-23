#include <iostream>

struct S {
    int m3;
    int m4;
    char m1;
    double m2;
};

/*
 *
 * [    int   ][   char   ][      double          ]
 * [i][i][i][i][c][.][.][.][d][d][d][d][d][d][d][d]
 *
 */
int main()
{
    std::cout << "sizeof(char): " << sizeof(char) << std::endl;
    std::cout << "sizeof(double): " << sizeof(double) << std::endl;
    std::cout << "sizeof(int): " << sizeof(int) << std::endl;

    std::cout << alignof(char) << std::endl; // 1
    std::cout << alignof(double) << std::endl; // 8
    std::cout << alignof(int) << std::endl; // 4

    std::cout << "sizeof(S): " <<sizeof(S) << std::endl;

    std::cout << "offsetof(S, m1): " << offsetof(S, m1) << std::endl;
    std::cout << "offsetof(S, m2): " << offsetof(S, m2) << std::endl;
    std::cout << "offsetof(S, m3): " << offsetof(S, m3) << std::endl;
}
