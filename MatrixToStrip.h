#pragma once
#include <vector>

std::vector<std::vector<double>> MatrixToStrip(int N, int l, const std::vector<std::vector<double>>& matrix, std::vector<std::vector<double>> strip_matrix) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (matrix[i][j] != 0) {
				strip_matrix[i][j - i + l] = matrix[i][j];
			}
		}
	}
	return strip_matrix;
}