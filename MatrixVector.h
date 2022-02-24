#pragma once
#include <vector>

std::vector<double> MatrixVector(int N, const std::vector<std::vector<double>>& matrix, const std::vector<double>& vector) {
	std::vector<double> b(N);
	for (int i = 0; i < N; ++i) {
		double sum = 0;
		for (int j = 0; j < N; ++j) {
			sum += matrix[i][j] * vector[j];
		}
		b[i] = sum;
	}
	return b;
}