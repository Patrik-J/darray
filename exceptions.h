#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
      
void throw_error(char* msg);

// throw std::invalid_argument("Vectors have different dimensions of " + std::to_string(v1.dimension()) + " and " + std::to_string(v2.dimension()));


#endif