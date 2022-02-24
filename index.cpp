#include <vector>
#include <string>
#include <map>
#include <time.h>
#include <iostream>
#include "Common.h"
#include "GetRandomDouble.h"
#include "MatrixVector.h"
#include "MatrixTranspose.h"
#include "MatrixMatrix.h"
#include "MatrixToStrip.h"
#include "PrintMatrix.h"
#include "Jacobi.h"
#include "FindNorm.h"
#include "SOR.h"
#include "CGM.h"

int main() {
	//Задание 1
	std::map<std::string, std::vector<std::vector<double>>> matrix;
	srand(time(0));
	std::vector<std::vector<double>> A1(N, std::vector<double>(N, 0));
	std::vector<std::vector<double>> A2(N, std::vector<double>(N, 0));
	std::vector<std::vector<double>> A3(N, std::vector<double>(N, 0));
	std::vector<std::vector<double>> AT1(N, std::vector<double>(N, 0));
	std::vector<std::vector<double>> AT2(N, std::vector<double>(N, 0));
	std::vector<std::vector<double>> AT3(N, std::vector<double>(N, 0));
	std::vector<std::vector<double>> M1(N, std::vector<double>(N, 0));
	std::vector<std::vector<double>> M2(N, std::vector<double>(N, 0));
	std::vector<std::vector<double>> M3(N, std::vector<double>(N, 0));
	double q1 = 1.1;
	double q2 = 2;
	double q3 = 10;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if ((l + 1) - abs(i - j) > 0) {
				A1[i][j] = GetRandomDouble(-1, 1);
			}
			A2[i][j] = A1[i][j];
			A3[i][j] = A1[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			A1[i][i] += abs(A1[i][j]);
			A2[i][i] += abs(A2[i][j]);
			A3[i][i] += abs(A3[i][j]);
		}
		A1[i][i] *= q1;
		A2[i][i] *= q2;
		A3[i][i] *= q3;
	}
	std::vector<double> x(N, 0);
	for (int i = 0; i < N; ++i) {
		x[i] = GetRandomDouble(-1, 1);
	}
	std::vector<double> b1 = MatrixVector(N, A1, x);
	std::vector<double> b2 = MatrixVector(N, A2, x);
	std::vector<double> b3 = MatrixVector(N, A3, x);
	AT1 = MatrixTranspose(N, A1);
	AT2 = MatrixTranspose(N, A2);
	AT3 = MatrixTranspose(N, A3);
	M1 = MatrixMatrix(N, AT1, A1);
	M2 = MatrixMatrix(N, AT2, A2);
	M3 = MatrixMatrix(N, AT3, A3);
	b1 = MatrixVector(N, AT1, b1);
	b2 = MatrixVector(N, AT2, b2);
	b3 = MatrixVector(N, AT3, b3);
	std::vector<double> x1(N, 0);
	std::vector<double> x2(N, 0);
	std::vector<double> x3(N, 0);
	std::vector<std::vector<double>> Strip1(N, std::vector<double>(4 * l + 1, 0));
	std::vector<std::vector<double>> Strip2(N, std::vector<double>(4 * l + 1, 0));
	std::vector<std::vector<double>> Strip3(N, std::vector<double>(4 * l + 1, 0));
	Strip1 = MatrixToStrip(N, 2 * l, M1, Strip1);
	Strip2 = MatrixToStrip(N, 2 * l, M2, Strip2);
	Strip3 = MatrixToStrip(N, 2 * l, M3, Strip3);
	std::cout << "Generated" << std::endl;

	//Задание 2
	x1 = Jacobi(N, 2 * l, delta, Strip1, b1);
	std::cout << "  q1 = " << q1 << " Norm = " << FindNorm(N, x1, x) << std::endl;
	x2 = Jacobi(N, 2 * l, delta, Strip2, b2);
	std::cout << "  q2 = " << q2 << " Norm = " << FindNorm(N, x2, x) << std::endl;
	x3 = Jacobi(N, 2 * l, delta, Strip3, b3);
	std::cout << "  q3 = " << q3 << " Norm = " << FindNorm(N, x3, x) << std::endl;

	//Задание 3
	for (double i = 0; i < 2; i += 0.1) {
		if (abs(i - 1) < 0.01) {
			i = 1;
		}
		std::cout << "  Relax = " << i << std::endl;
		x1 = SOR(N, 2 * l, delta, i, Strip1, b1);
		std::cout << "    q1 = " << q1 << " Norm = " << FindNorm(N, x1, x) << std::endl;
		x2 = SOR(N, 2 * l, delta, i, Strip2, b2);
		std::cout << "    q2 = " << q2 << " Norm = " << FindNorm(N, x2, x) << std::endl;
		x3 = SOR(N, 2 * l, delta, i, Strip2, b3);
		std::cout << "    q3 = " << q3 << " Norm = " << FindNorm(N, x3, x) << std::endl;
	}

	//Задание 4
	x1 = CGM(N, 2 * l, delta, Strip1, b1);
	std::cout << "  q1 = " << q1 << " Norm = " << FindNorm(N, x1, x) << std::endl;
	x2 = CGM(N, 2 * l, delta, Strip2, b2);
	std::cout << "  q2 = " << q2 << " Norm = " << FindNorm(N, x2, x) << std::endl;
	x3 = CGM(N, 2 * l, delta, Strip3, b3);
	std::cout << "  q3 = " << q3 << " Norm = " << FindNorm(N, x3, x) << std::endl;
	return 0;
}