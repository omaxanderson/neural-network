#include "NeuralNetwork.h"
#include <vector>
#include <iostream>

typedef std::vector< std::vector<double> > Matrix;
int main(int argc, char* argv[]) {
	NeuralNetwork nn(2, 1, 3, 1);
//	NeuralNetwork nn();
	/*
	Matrix m1 = { {1.0,1.0, 1.0},
					{2.0, 2.0, 2.0},
					{3.0, 3.0, 3.0} };
	Matrix m2 = { {4.0, 3.0, 2.0, 4.2},
					{7.0, 3.0, 9.0, 9.2},
					{2.0, 1.0, 5.0, 1.2} };
	Matrix result = nn.matrixMultiply(m1, m2);
	std::cout << m2.size() << "x" << m2[0].size() << std::endl;
	for (std::vector<double> vec : result) {
		for (double d : vec) {
			std::cout << d << ", ";
		}
		std::cout << std::endl;
	}
	*/
	
	Matrix m = { {23, 54} };
	std::cout << nn.forward(m) << std::endl;

	return 0; 
}
