#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>      

void throw_error(const std::string& msg);

// throw std::invalid_argument("Vectors have different dimensions of " + std::to_string(v1.dimension()) + " and " + std::to_string(v2.dimension()));


#endif