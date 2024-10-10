#include <iostream>

enum class ErrorCode {
    OK,
    NOT_FOUND,
    NO_CONTENT
};

//[[nodiscard("You must not to ignore return value of get_content")]]
ErrorCode get_content(const std::string &url)
{
    // ...
    return ErrorCode::OK;
}

int main()
{
    get_content("https://vk.com/");

    const double d1 = 0.0;
    double const d2 = 1.0;

    const int * a1 = new int(1);
    int const * a2 = new int(2);
    a1 = a2;
    a2 = a1;
    // *a1 += 1; //error: assignment of read-only location ‘* a1’
    // *a2 += 1; //error: assignment of read-only location ‘* a2’
    int * const a3 = new int(3);
    *a3 += 1;
    // a3 = a1; //error: assignment of read-only variable ‘a3’
    const int * const a4 = new int(4);
    //a4 = a1; // error: assignment of read-only variable ‘a4’
    //*a4 += 1; // error: assignment of read-only location ‘*(const int*)a4’
}

