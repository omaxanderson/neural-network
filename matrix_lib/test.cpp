#include "Matrix.h"
#include <iostream>

int main(int argc, char* argv[]) {

	Matrix m(4, 4);
	int num = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m(i, j) = num;
			num++;
		}
	}

	Matrix m2(4, 5);
	m2(0, 1) = 2.0;

	Matrix product = m * m2;
	std::cout << m << std::endl;

	return 0;
}
