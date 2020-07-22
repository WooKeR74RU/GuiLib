#pragma once

#include <random>
#include <ctime>

class Random
{
public:
	static Random& get();

	int getInt();
	int getIntInRange(int low, int high);
	float getFloat();
	float getFloatInRange(float low, float high);

private:
	Random();

	std::mt19937 generator;
};