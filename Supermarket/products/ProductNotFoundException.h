#pragma once
#ifndef PRODUCT_NOT_FOUND_EXCEPTION_H
#define PRODUCT_NOT_FOUND_EXCEPTION_H
#include <stdexcept>



class ProductNotFoundException : public std::invalid_argument
{
public:
    ProductNotFoundException();

};

#endif
