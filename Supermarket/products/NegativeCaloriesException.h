#pragma once
#ifndef NEGATIVE_CALORIES_EXCEPTION_H
#define NEGATIVE_CALORIES_EXCEPTION_H
#include <stdexcept>



class NegativeCaloriesException : public std::invalid_argument
{
public:
    NegativeCaloriesException();

};

#endif
