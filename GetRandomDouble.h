#pragma once
#include <random>

double GetRandomDouble(const double& min, const double& max) {
	double f = (double)rand() / RAND_MAX;
	return min + f * (max - min);
}