#include "RNG.h"

int RNG::generate_random_number(int max_l)
{

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<> dist(0, max_l);

    return dist(generator);
}