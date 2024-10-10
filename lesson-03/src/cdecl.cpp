int foo1(int a, int b, int c, int d)
{
    return 1;
}

int boo1()
{
    foo1(1, 2, 3, 4);
    return 0;
}

[[gnu::fastcall]]
int foo2(int a, int b, int c, int d)
{
    return 1;
}

int boo2()
{
    foo2(1, 2, 3, 4);
    return 0;
}

int foo3(int a, int b, int c, int d, int e, int f, int g, int h)
{
    return 1;
}

int boo3()
{
    foo3(1, 2, 3, 4, 5, 6, 7, 8);
    return 0;
}

