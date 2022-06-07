#include <iostream>
#include <map>
#include "Supermarket.h"
#include <sstream>


using namespace std;
int main(int argc, char* argv[])
{
    if (argc != 5)
    {
        throw exception("invaild number of arguments");
    }
    string products_path, names_path, addresses_path;
    int iterations;
    stringstream stream;

    stream << argv[1];
    stream >> products_path;
    stream.clear();

    stream << argv[2];
    stream >> names_path;
    stream.clear();

    stream << argv[3];
    stream >> addresses_path;
    stream.clear();

    stream << argv[4];
    stream >> iterations;
    stream.clear();

    Supermarket sprm(products_path, names_path, addresses_path);
    sprm.load_registers();
    sprm.simulation(iterations);



}

