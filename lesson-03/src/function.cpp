#include <functional>
#include <vector>
#include <iostream>

using MoveFunction = std::function<void (int& x, int& y)>;

void moveLeft(int &x, int &y) {
    std::cout << "moveLeft function" << std::endl;
}

struct RightMover
{
    void operator()(int&x, int&y)
    {
        std::cout << "RightMover functor" << std::endl;
    }
};

int main()
{
    std::vector<MoveFunction> trajectory =
    {
        [](int& x, int& y)  { std::cout << "lambda" << std::endl; },
        moveLeft,
        RightMover()
    };

    int x = 10;
    int y = 20;
    for (auto func : trajectory) {
        func(x, y);
    }
}
