#include "exceptions.h"

void throw_error(char* msg) {
    throw std::invalid_argument(msg);
};