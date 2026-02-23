#include "exceptions.h"

DimensionErrorException::DimensionErrorException(const std::string& msg) : message(msg) { }

const char* DimensionErrorException::what() const noexcept {
    return this->message.c_str();
};