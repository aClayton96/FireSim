#include "Random.h"

int RandomNum::Random(int min, int max)
{
	//A random number generation method slightly more effective than rand();

		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dist(min, max); //random numbers between 1 and 10
		int n = dist(gen);
		return n;
};
