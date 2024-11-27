#include <iostream>
#include <cassert>
#include <system_error>

enum class HttpCode
{
    OK = 200,
    NOT_FOUND = 404,
    INTERNAL_SERVER_ERROR = 500
};

class HttpCategory : public std::error_category
{
    const char* name() const noexcept override
    {
        return "http";
    }

    std::string message(int code) const noexcept override
    {
        switch(code) {
            case 200:
                return "ok";
            case 404:
                return "not found";
            case 500:
                return "internal server error";
        }
        assert(!"unknown http code");
    }
};

std::error_code make_error_code(HttpCode code)
{
    static const HttpCategory instance;
    return std::error_code(static_cast<int>(code), instance);
}

[[nodiscard]]
std::error_code download(const std::string& url)
{
    if (url == "https://vk.com")
    {
        return make_error_code(HttpCode::OK); // ok
    }

    if (url == "https://youtube.com")
    {
        return make_error_code(HttpCode::NOT_FOUND); // not found
    }

    if (url == "https://google.com")
    {
        return make_error_code(HttpCode::INTERNAL_SERVER_ERROR); // internal server error
    }

    return make_error_code(HttpCode::NOT_FOUND);
}

int main()
{
    auto vk_status = download("https://vk.com");
    if (vk_status) {
        std::cout << vk_status << std::endl;
        std::cout << vk_status.message() << std::endl;
    }
    auto ytb_status = download("https://youtube.com");
    if (ytb_status) {
        std::cout << ytb_status << std::endl;
        std::cout << ytb_status.message() << std::endl;
    }
    // ...
}
