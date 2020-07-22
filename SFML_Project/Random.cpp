#include "Random.h"

Random& Random::get()
{
	static Random random;
	return random;
}

int Random::getInt()
{
	return std::uniform_int_distribution<int>()(generator);
}
int Random::getIntInRange(int low, int high)
{
	return std::uniform_int_distribution<int>(low, high)(generator);
}
float Random::getFloat()
{
	return std::uniform_real_distribution<float>()(generator);
}
float Random::getFloatInRange(float low, float high)
{
	return std::uniform_real_distribution<float>(low, high)(generator);
}

Random::Random() :
	generator((int)time(nullptr))
{ }