#include "NeuralNetwork.h"
#include "Matrix.h"
#include "IOHelper.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {

	NeuralNetwork nn(8, 4, 10, 1);

	Matrix trainMatrix = readFile("Concrete_Data.txt", 8);
	Matrix targetMatrix = readFileColumn("Concrete_Data.txt", 8);

//	std::cout << trainMatrix << std::endl;
	trainMatrix.normalize();
	targetMatrix.normalize();
//	std::cout << trainMatrix << std::endl;

	// we have normalized training data

	// let the nn train
	nn.train(trainMatrix, targetMatrix, 1000);

	// test it out using a single entry from the trainMatrix and its respective output from the targetMatrix
	std::vector< std::vector<double> > test;
	std::vector<double> t1;
	for (int i = 0; i < trainMatrix.cols(); i++) {
		t1.push_back(trainMatrix(std::stoi(argv[1]), i));
	}
	test.push_back(t1);

	Matrix result = nn.predict(test);
	std::cout << result << std::endl;
	std::cout << targetMatrix(std::stoi(argv[1]), 0) << std::endl;

/*	std::string temp;
	std::istringstream iss(temp);

	iss << file;
	std::cout << temp << std::endl;
	*/

	/*
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
	*/

		
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
