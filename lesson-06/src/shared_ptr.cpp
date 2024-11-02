#include <iostream>

class shared_ptr
{
private:
    struct wrapper_
    {
        wrapper_(char* ptr) : counter(1), data(ptr)
        {
        }
        size_t counter = 0;
        char* data = nullptr;
    };

public:
    shared_ptr() : wrap_(nullptr) {}
    shared_ptr(char* ptr)
    {
        wrap_ = new wrapper_(ptr);
    }

    // shared_ptr ptr1(ptr2);
    shared_ptr(const shared_ptr& rhs)
    {
        std::cout << "ctr &" << std::endl;
        wrap_ = rhs.wrap_;
        if (wrap_) {
            wrap_->counter += 1;
        }
    }

    shared_ptr(shared_ptr&& rhs)
    {
        std::cout << "ctr &&" << std::endl;
        wrap_ = rhs.wrap_;
        rhs.wrap_ = nullptr;
    }

    // shared_ptr ptr1;
    // shared_ptr ptr2;
    // ptr1 = ptr2;
    shared_ptr& operator=(const shared_ptr& rhs)
    {
        std::cout << "operator=&" << std::endl;
        if (this == &rhs) {
            return *this;
        }

        destroy();
        wrap_ = rhs.wrap_;
        if (wrap_) {
            wrap_->counter += 1;
        }
        return *this;
    }

    shared_ptr& operator=(shared_ptr&& rhs)
    {
        std::cout << "operator=&&" << std::endl;
        if (this == &rhs) {
            return *this;
        }

        destroy();
        wrap_ = rhs.wrap_;
        rhs.wrap_ = nullptr;
        return *this;
    }

    ~shared_ptr()
    {
        destroy();
    }
private:
    void destroy()
    {
        std::cout << "~shared_ptr, counter = " << (wrap_ ? wrap_->counter : 0) << std::endl;
        if (wrap_ == nullptr)
        {
            return;
        }
        wrap_->counter -= 1;
        if (wrap_->counter == 0)
        {
            std::cout << "~shared_ptr::destroy" << std::endl;
            delete wrap_->data;
            delete wrap_;
        }
    }
private:
    wrapper_* wrap_;

};

int main()
{
    shared_ptr ptr1(new char('A'));
    {
        shared_ptr ptr2 = ptr1;
    }
    {
         shared_ptr ptr2;
         shared_ptr ptr3 = ptr2;
    }
    shared_ptr ptr3(new char('b'));
    ptr3 = ptr1;
    ptr3 = ptr3;

    shared_ptr ptr4 = std::move(ptr3);
    ptr4 = std::move(ptr4);
    {
        shared_ptr ptr5;
        ptr5 = std::move(ptr5);
    }
}
