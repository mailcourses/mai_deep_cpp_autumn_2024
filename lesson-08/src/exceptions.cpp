#include <iostream>

struct Foo
{
    Foo() : data_(new int[1024])
    {
        try {
            std::cout << "Foo::ctr" << std::endl;
            throw 10;
        } catch (int) {
            //...
        }
    }

    ~Foo() noexcept(false)
    {
        std::cout << "~Foo::dctr" << std::endl;
        delete[] data_;
        throw 'a';
    }
    int* data_ = nullptr;
};

int main()
{
    try {
        Foo foo;
    }
    catch(char ex)
    {
        std::cout << "within catch block (char)" << std::endl;
        throw ex;
    }
    catch(int ex)
    {
        std::cout << "within catch block (int)" << std::endl;
    }
}
