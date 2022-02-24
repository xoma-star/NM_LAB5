#pragma once
#include <vector>

std::vector<std::vector<double>> MatrixTranspose(int N, const std::vector<std::vector<double>>& matrix) {
	std::vector<std::vector<double>> transposed(N);
	for (int i = 0; i < N; ++i) {
		transposed[i].resize(N);
		for (int j = i; j < N; ++j) {
			transposed[i][j] = matrix[j][i];
		}
	}
	return transposed;
}