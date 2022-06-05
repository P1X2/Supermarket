#include "RNG.h"

int RNG::generate_random_number(int min_l, int max_l)
{

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<> dist(min_l, max_l);

    return dist(generator);
}

string RNG::random_string_vector_element(vector<string> vec)
{
    return vec[generate_random_number(0, vec.size() - 1)];
}

vector<int> RNG::random_numbers_vector(int min, int max,int n)
{
    vector<int> random_numbers;
    for (int i = 1; i <= n; i++)
    {
        random_numbers.push_back(n);
    }
    return random_numbers;
}