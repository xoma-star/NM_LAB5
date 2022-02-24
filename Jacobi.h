#pragma once
#include <vector>
#include <iostream>

std::vector<double> Jacobi(int N, int l, const double& delta, std::vector<std::vector<double>> A, std::vector<double> b) {
	std::vector<double> x(N, 0);
	std::vector<double> x_next(N, 0);
	double difference;
	int iterations = 0;
	do {
		iterations++;
		for (int i = 0; i < N; ++i) {
			x_next[i] = b[i];
			for (int j = 0; j < N; ++j) {
				int index = j - i + l;
				if (j != i && index >= 0 && index < 2 * l + 1) {
					x_next[i] -= A[i][index] * x[j];
				}
			}
			x_next[i] /= A[i][l];
		}
		difference = abs(x_next[0] - x[0]);
		for (int i = 0; i < N; ++i) {
			if (abs(x_next[i] - x[i]) > difference) {
				difference = abs(x_next[i] - x[i]);
			}
			x[i] = x_next[i];
		}
	} while (difference > delta);
	std::cout << "Iterations: " << iterations << std::endl;
	return x_next;
}