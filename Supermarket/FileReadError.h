#pragma once
#include <stdexcept>
using namespace std;
class FileReadError :
    public invalid_argument
{
public:
    FileReadError(string,int);
};

