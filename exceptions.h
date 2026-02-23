#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>      

class DimensionErrorException : public std::exception {
    public:
        DimensionErrorException(const std::string& msg);

        const char* what() const noexcept override;

    private:
        std::string message;
};

#endif