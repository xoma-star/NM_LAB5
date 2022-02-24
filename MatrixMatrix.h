#pragma once
#include <vector>

std::vector<std::vector<double>> MatrixMatrix(int N, const std::vector<std::vector<double>>& matrix1, const std::vector<std::vector<double>>& matrix2) {
	std::vector<std::vector<double>> result(N);
	for (int i = 0; i < N; ++i) {
		result[i].resize(N);
		for (int j = 0; j < N; ++j) {
			double sum = 0;
			for (int k = 0; k < N; ++k) {
				sum += matrix1[i][k] * matrix2[k][j];
			}
			result[i][j] = sum;
		}
	}
	return result;
}