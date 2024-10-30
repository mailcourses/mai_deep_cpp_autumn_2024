module;


//#include <string>

export module mexample;

int unexported_square(int num)
{
    return num * num;
}

export int square(int num)
{
    return num * num;
}

export
{
    void foo() {}
    void boo() {}
};

export namespace vk
{
    void search(const char*) {}
}
