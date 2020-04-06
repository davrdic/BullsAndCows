#include<random>

using std::uniform_int_distribution;
using std::default_random_engine;

default_random_engine& get_rand()
{
	static default_random_engine ran;
	return ran;
};

void seed_randint(int s) { get_rand().seed(s); }

inline int randint(int min, int max) { return uniform_int_distribution<>{min, max}(get_rand()); }

inline int randint(int max) { return randint(0, max); }