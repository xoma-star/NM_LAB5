#pragma once
#include <vector>

std::vector<double> StripMatrixVector(int N, int l, const std::vector<std::vector<double>>& strip_matrix, const std::vector<double>& vector) {
	std::vector<double> answer(N, 0);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int index = j - i + l;
			if (index >= 0 && index < 2 * l + 1) {
				answer[i] += strip_matrix[i][index] * vector[j];
			}
		}
	}
	return answer;
}