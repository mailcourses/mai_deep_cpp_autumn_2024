#include <iostream>
#include <chrono>
#include <source_location>

class Profiler
{
public:
    Profiler(const std::source_location& location = std::source_location::current()) : location2_(location), start_ts_(std::chrono::system_clock::now())
    {
        start_ts_ = std::chrono::system_clock::now();
        location_ = location;
        //location2_ = location; <-- compile error
    }

    ~Profiler() {
        auto end_ts_ = std::chrono::system_clock::now();
        uint64_t duration = std::chrono::duration_cast<std::chrono::microseconds>(end_ts_ - start_ts_).count();
        std::cout << "Duration of " << location_.function_name() << " file " << location_.file_name() << " function is " << duration << " microseconds" << std::endl;
    }
private:
    std::chrono::system_clock::time_point start_ts_;
    std::source_location location_;
    const std::source_location &location2_;
};

void foo()
{
    Profiler prof;
    for (size_t i = 0; i < 1000000; ++i);
}

void boo()
{
    Profiler prof;
    for (size_t i = 0; i < 2000000; ++i);
}

int main()
{
    foo();
    boo();
    foo();
}
