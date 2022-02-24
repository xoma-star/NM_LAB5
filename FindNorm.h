#pragma once
#include <vector>

double FindNorm(int N, const std::vector<double>& exact, const std::vector<double>& approximate) {
	double max = abs(approximate[0] - exact[0]);
	for (int i = 0; i < N; ++i) {
		if (abs(approximate[i] - exact[i]) > max) {
			max = abs(approximate[i] - exact[i]);
		}
	}
	return max;
}