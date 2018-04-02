#include "Matrix.h"
#include <iostream>

int main(int argc, char* argv[]) {

	Matrix m(4, 6);
	int num = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			m(i, j) = (double)num;
			num++;
		}
	}

	Matrix m2(4, 4);
	m2.fill(2.0);

	Matrix product = m / m2;
//	std::cout << m << std::endl;
/*	std::cout << m2 << std::endl;
	std::cout << product << std::endl;
*/
//	std::cout << m.transpose() << std::endl;
//
	num = 0;
	Matrix dot1(2, 3);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			dot1[i][j] += num++;
		}
	}
	num = 0;
	Matrix dot2(3, 4);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			dot2[i][j] += num++;
		}
	}
	std::cout << dot1 << std::endl;
	std::cout << dot1 / 2 << std::endl;
	std::cout << dot2 << std::endl;
	std::cout << Matrix::dot(dot1, dot2) << std::endl;

	return 0;
}
