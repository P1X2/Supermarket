#pragma once
#include <iostream>
#include <chrono>
#include <random>
#include <iostream>
#include <vector>
using namespace std;

class RNG
{
public:
	int generate_random_number(int min_l, int max_l);
	string random_string_vector_element(vector<string>);
};

