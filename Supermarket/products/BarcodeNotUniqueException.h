#pragma once
#ifndef BARECODE_NOT_UNIQUE_EXCEPTION_H
#define BARECODE_NOT_UNIQUE_EXCEPTION_H
#include <stdexcept>



class BarcodeNotUniqueException : public std::invalid_argument
{
public:
    BarcodeNotUniqueException();

};

#endif
