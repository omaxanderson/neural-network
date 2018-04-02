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
	std::cout << m << std::endl;
/*	std::cout << m2 << std::endl;
	std::cout << product << std::endl;
*/
	std::cout << m.transpose() << std::endl;

	return 0;
}
