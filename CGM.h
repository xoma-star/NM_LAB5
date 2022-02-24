#pragma once
#include <vector>
#include <iostream>
#include "VectorVector.h"
#include "StripMatrixVector.h"

std::vector<double> CGM(int N, int l, const double& delta, std::vector<std::vector<double>> A, std::vector<double> b) {
	std::vector<double> x(N, 0);
	std::vector<double> x_next(N, 0);
	std::vector<double> r(N, 0);
	std::vector<double> r_next(N, 0);
	std::vector<double> p(N, 0);
	std::vector<double> p_next(N, 0);
	double alpha = 0;
	double beta = 0;
	std::vector<double> Ax(N, 0);
	std::vector<double> Ap(N, 0);
	Ax = StripMatrixVector(N, l, A, x);
	for (int i = 0; i < N; ++i) {
		r[i] = b[i] - Ax[i];
		p[i] = r[i];
	}
	double difference;
	int iterations = 0;
	do {
		iterations++;
		Ap = StripMatrixVector(N, l, A, p);
		alpha = VectorVector(N, r, r) / VectorVector(N, Ap, p);
		for (int i = 0; i < N; ++i) {
			x_next[i] = x[i] + alpha * p[i];
			r_next[i] = r[i] - alpha * Ap[i];
		}
		beta = VectorVector(N, r_next, r_next) / VectorVector(N, r, r);
		for (int i = 0; i < N; ++i) {
			p_next[i] = r_next[i] + beta * p[i];
		}
		difference = abs(r_next[0] - r[0]);
		for (int i = 0; i < N; ++i) {
			if (abs(r_next[i] - r[i]) > difference) {
				difference = fabs(r_next[i] - r[i]);
			}
			x[i] = x_next[i];
		}
		for (int i = 0; i < N; ++i) {
			p[i] = p_next[i];
			x[i] = x_next[i];
			r[i] = r_next[i];
		}
	} while (difference > delta);
	std::cout << "Iterations: " << iterations << std::endl;
	return x_next;
}