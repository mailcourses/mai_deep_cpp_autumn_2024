#include <iostream>
#include <cstring>

class Logger
{
public:
    Logger() {
        std::cout << "Logger ctor" << std::endl;
    }
    virtual ~Logger() {
        std::cout << "Logger dtor" << std::endl;
    }

    virtual void log(const std::string& str) const = 0;
    virtual void destroy() = 0;
};

class FileLogger : public Logger {
public:
    ~FileLogger() {
        std::cout << "FileLogger dtor" << std::endl;
    }
    void log(const std::string& str) const override
    {
        std::cout << "FileLogger::log" << std::endl;
    }
    void log(int num)
    {
        std::cout << "FileLogger::log(int)" << std::endl;
    }
    virtual void destroy() {}
};

class ConsoleLogger : public Logger {
public:
    ~ConsoleLogger() {
        std::cout << "ConsoleLogger dtor" << std::endl;
    }
    void log(const std::string& str) const override
    {
        std::cout << "ConsoleLogger::log" << std::endl;
    }
    virtual void destroy() {}
};

void execute(Logger* logger)
{
    std::string str("some string");
    logger->log(str);
    logger->destroy();
}

int main(int argc, char** argv)
{

    Logger* logger = nullptr;
    if (strcmp(argv[1], "file") == 0) {
        logger = new FileLogger();
    } else if (strcmp(argv[1], "console") == 0) {
        logger = new ConsoleLogger();
    }

    execute(logger);

    delete logger;

/*
    const std::string str2("some string");
    FileLogger* file_logger = new FileLogger();
    file_logger->log(str2);
    file_logger->log(100);
    delete file_logger;
*/
}
