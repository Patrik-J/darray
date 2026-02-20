#include "exceptions.h"

void throw_error(const std::string& msg) {
    throw std::invalid_argument(msg);
};