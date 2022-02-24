#pragma once
#include <vector>
#include <iostream>

void PrintMatrix(const std::vector<std::vector<double>>& matrix) {
	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[i].size(); ++j) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}