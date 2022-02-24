#pragma once
#include <vector>

double VectorVector(int N, const std::vector<double>& vector1, const std::vector<double>& vector2) {
	double result = 0;
	for (int i = 0; i < N; ++i) {
		result += vector1[i] * vector2[i];
	}
	return result;
}