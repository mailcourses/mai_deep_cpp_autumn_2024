#include <cstdint> // uint16_t
#include <iostream>

struct Server
{
    Server(uint16_t port)
    {
        std::cout << "Server(uint16_t)" << std::endl;
    }

    Server(const Server& rhs)
    {
        std::cout << "Server(const Server&)" << std::endl;
    }

    Server(Server&& rhs)
    {
        std::cout << "Server(Server&&)" << std::endl;
    }

    Server& operator=(const Server& rhs)
    {
        std::cout << "operator=(const Server&)" << std::endl;
        return *this;
    }

    Server& operator=(Server&& rhs)
    {
        std::cout << "operator=(Server&&)" << std::endl;
        return *this;
    }

    void setup() {}
};

Server makeServer(uint16_t port)
{
    Server server(port);
    server.setup();
    return server;
}

int main()
{
    Server s = makeServer(8080);
}
