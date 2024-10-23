#include <iostream>

struct ConfigA
{
public:
    ConfigA() {
        std::cout << "ConfigA ctor" << std::endl;
        parse_config();
        ptr = new int(100500);
    }

    void parse_config() {
        std::cout << "A::parse_config, a=" << a << ", b = " << b << " c = " << c << std::endl;
    }

    ~ConfigA() {
        std::cout << "ConfigA dtor" << std::endl;
    }
public:
    int a = 10;
    int* ptr = nullptr;
protected:
    int b = 20;
private:
    int c = 30;
};

struct ConfigB : private ConfigA
{
public:
    ConfigB(/*ConfigB* this*/) {
        std::cout << "ConfigB ctor" << std::endl;
        std::cout << "ptr = " << *ptr << std::endl;
        this->a;
        this->b;
        // this->c; <-- c is private member.
    }
    ~ConfigB() {
        std::cout << "ConfigB dtor" << std::endl;
    }
};

int main()
{
    {
        ConfigA config_a;
        config_a.a;
        //config_a.b;
        //config_a.c;
    }

    {
        ConfigB config_b;
        //config_b.a;
        //config_b.b;
        //config_b.c;
    }
}

