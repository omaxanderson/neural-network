#include "NeuralNetwork.h"
#include "Matrix.h"
#include <vector>
#include <iostream>

int main(int argc, char* argv[]) {

	NeuralNetwork nn(2, 1, 3, 1);

	std::vector< std::vector<double> > inputs= 
		{ {0, 0},
		{ 0, 1 },
		{ 1, 0 },
		{ 1, 1 }};
	Matrix in(inputs);
	std::vector< std::vector<double> > t = 
		{ {0},
		{ 1 },
		{ 1 },
		{ 0 }};
	Matrix targets(t);

	Matrix out = nn.predict(in);
	std::cout << out << std::endl;
	nn.setLearningRate(0.5);

	for (int i = 0; i < 100000; i++) {
		nn.train(in, targets);
	}

	Matrix out2 = nn.predict(in);
	std::cout << out2 << std::endl;

		
//	Matrix result = nn.predict(m);
//	nn.train(m, targets);
/*	std::cout << nn.sigmoidPrime(1) << std::endl;
	std::cout << nn.sigmoidPrime(0.5) << std::endl;
	std::cout << nn.sigmoidPrime(0.1) << std::endl;
	std::cout << nn.sigmoidPrime(0) << std::endl;
	std::cout << "====================\n";
	for (std::vector<double> v : result) {
		for (double d : v) {
			std::cout << d << std::endl;
		} 
	}
*/
	return 0; 
}
