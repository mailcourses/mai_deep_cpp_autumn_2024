#include <cstddef> // size_t
#include <utility> // std::move

class MyString
{
public:
    MyString() : size_(0), capacity_(10)
    {
        data_ = new char[capacity_];
    }

    MyString(MyString&& rhs) {
        data_ = rhs.data_;
        size_ = rhs.size_;
        capacity_ = rhs.capacity_;

        rhs.data_ = nullptr;
        rhs.size_ = 0;
        rhs.capacity_ = 0;
    }

    void clear() {}

    MyString& operator=(const MyString& rhs);// = default;

    MyString& operator=(MyString&& rhs);

    ~MyString()
    {
        delete[] data_;
    }

private:
    char* data_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;
};
//obj1 -> [|||||||] <- obj2
MyString&
MyString::operator=(const MyString& rhs)
{
    char* tmp = new char[rhs.capacity_];
    for (size_t i = 0; i < rhs.size_; ++i) {
        tmp[i] = rhs.data_[i];
    }
    delete[] data_;
    data_ = tmp;
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;
    return *this;
}

MyString&
MyString::operator=(MyString&& rhs)
{
    if (this == &rhs) {
        return *this;
    }

    delete[] data_;
    data_ = rhs.data_;
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;

    rhs.data_ = nullptr;
    rhs.size_ = 0;
    rhs.capacity_ = 0;
    return *this;
}

void dummy(MyString&& str)
{
    str.clear();
}

void dummy(const MyString& str)
{

}

int main()
{
    MyString obj1;
    {
        MyString obj2;
        obj2 = obj1;
    }

    MyString obj3 = std::move(obj1);
    obj1 = std::move(obj3);
    obj1 = std::move(obj1);
    dummy(std::move(obj1));
    dummy(MyString());
}
