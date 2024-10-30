#include <iostream>

enum COLOUR
{
    C_RED,
    C_BLACK,
    C_WHITE,
    C_NONE
};

enum SHAPE
{
    SH_CIRCLE,
    SH_SQUARE,
    SH_OVAL,
    SH_NONE
};

enum class COLOR
{
    RED,
    BLACK,
    NONE
};

enum class NEW_SHAPE
{
    CIRCLE,
    SQUARE,
    NONE
};

struct A
{
//public:
    int a = 0;
};

struct B
{
public:
    B() {
        std::cout << "Ctr B()" << std::endl;
    }
public:
    B(int a_b) {
    }

    B(const B& rhs) {
    }

    B& operator=(const B& rhs) {
        //...
        return *this;
    }

public:
    ~B() {
        std::cout << "Dctr B()" << std::endl;
    }
/*
public:
    <методы>
protected:
    <методы>
private:
    <методы>

public:
    <аттрибуты>
protected:
    <аттрибуты>
private:
    <аттрибуты>
*/
//private:
public:
    int b = -1;
};

int main()
{
    COLOUR cup_color = C_RED;
    if (cup_color == C_RED) {
        std::cout << "RED" << std::endl;
    }
    else if (cup_color == C_BLACK) {
        std::cout << "BLACK" << std::endl;
    }
    else if (cup_color == C_WHITE) {
        std::cout << "WHITE" << std::endl;
    }

    SHAPE cup_shape = SH_CIRCLE;

    COLOR color = COLOR::NONE;
    NEW_SHAPE shape = NEW_SHAPE::NONE;

    A a;
    std::cout << "Before a.a = " << a.a << std::endl;
    {
        B b;
        std::cout << "b.b = " << b.b << std::endl;
    }
    std::cout << "After a.a = " << a.a << std::endl;
    B b2(10);
    B b1 = b2;

    b1 = b2;

}
