#include "NeuralNetwork.h"
#include <cmath>
#include <vector>
#include <cstdlib>
#include <iostream>

/*
NeuralNetwork::NeuralNetwork() {
	inputLayerSize = 2;
	numHiddenLayers = 1;
	hiddenLayerSize = 2;
	outputLayerSize = 1;
	initialize();
}

NeuralNetwork::NeuralNetwork(int inputLayerSize, int numHiddenLayers, 
		int hiddenLayerSize, int outputLayerSize) : inputLayerSize(inputLayerSize), 
		numHiddenLayers(numHiddenLayers), hiddenLayerSize(hiddenLayerSize), 
		outputLayerSize(outputLayerSize) {
	initialize();
	
}
void NeuralNetwork::initialize() {
//	std::cout << "initializing" << std::endl;
	
	srand(time(NULL));
/*
	for (int layer = 0; layer < inputLayerSize; layer++) {
		std::vector<double> temp;
		for (int node = 0; node < hiddenLayerSize; node++) {
			temp.push_back((double)rand() / RAND_MAX);
		}
		w1.push_back(temp);
	}

	for (int i = 0; i < hiddenLayerSize; i++) {
		w2.push_back(std::vector<double>());
		w2[i].push_back((double)rand() / RAND_MAX);
	}

	//DEBUGGING - print out weight matrices
	for (std::vector<double> vec : w1) {
		for (double d : vec) {
			std::cout << d << " ";
		}
		std::cout << std::endl;
	}
	for (std::vector<double> vec : w2) {
		for (double d : vec) {
			std::cout << d << " ";
		}
		std::cout << std::endl;
	}
}

// Calls the activation function specified upon every 
// item in Matrix mat
Matrix NeuralNetwork::sigmoid(const Matrix& mat) {
	//Matrix result(mat);
	/*
	for (const std::vector<double> vec : mat) {
		std::vector<double> temp;
		for (const double num : vec) {
			temp.push_back(sigmoid(num));
		}
		result.push_back(temp);
	}
	*/
	return Matrix(3,3);
}

// Sigmoid activation function
double NeuralNetwork::sigmoid(double d) {
	double e = 2.71828;
	return 1 / (1 + std::pow(e, -d));
}
//
// Calls the activation function specified upon every 
// item in Matrix mat
Matrix NeuralNetwork::sigmoidPrime(const Matrix& mat) {
	Matrix result;
	/*
	for (const std::vector<double> vec : mat) {
		std::vector<double> temp;
		for (const double num : vec) {
			temp.push_back(sigmoidPrime(num));
		}
		result.push_back(temp);
	}
	*/
	return result;
}

double NeuralNetwork::sigmoidPrime(double d) {
	double e = 2.71828;
	return std::pow(e, -d) / std::pow(1 + std::pow(e, d), 2);
}

// Takes the input matrix, multiplies it with the weights, performs an
// activation function on it, then multiplies it by the second layer of 
// weights
Matrix NeuralNetwork::predict(const Matrix& inputs) {
//	Matrix h1 = dot(inputs, w1);
//	Matrix a1 = sigmoid(h1);
	/*
	for (std::vector<double> vec : a1) {
		for (double d : vec) {
			std::cout << d << " ";
		}
		std::cout << std::endl;
	}
	*/
	// out is the a Nx1 matrix where N is the number of input examples
	// rn thats going to be 4
//	Matrix out = dot(a1, w2);

	Matrix out = forward(inputs);
//	std::cout << "out = " << out.size() << "x" << out[0].size() << std::endl;
/*	for (int i = 0; i < out.size(); i++) {
		out[i][0] = sigmoid(out[i][0]);
	}
	*/


	return out;
}

Matrix NeuralNetwork::forward(const Matrix& inputs) {
	return dot(sigmoid(dot(inputs, w1)), w2);
}


void NeuralNetwork::train(const Matrix& inputs,const  Matrix& targets) {
	// first we need to forward propegate to get the predictions
	/*
	Matrix output = predict(inputs);

	Matrix delta3 = elementMultiply(elementSubtract(output, targets), sigmoidPrime(forward(inputs)));
	Matrix dJdW2 = dot(transpose(dot(inputs, w1)), delta3);

	Matrix delta2 = elementMultiply(dot(delta3, transpose(w2)), sigmoid(dot(inputs, w1)));
	Matrix dJdW1 = dot(transpose(inputs), delta2);

	std::cout << "printing matrices" << std::endl;
	for (std::vector<double> v : dJdW2) {
		for (double d : v) {
			std::cout << d << " ";
		} 
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (std::vector<double> v : dJdW1) {
		for (double d : v) {
			std::cout << d << " ";
		} 
		std::cout << std::endl;
	}
	
	// next lets calculate the error for each output neuron
	// output matrix will be NxM, where N is the number of input 
	// examples and M is the number of output neurons
	Matrix error;
	for (int i = 0; i < output.size(); i++) {
		double sum = 0;
		for (int j = 0; j < output[0].size(); j++) {
			sum += std::pow(0.5 * (targets[i][j] - output[i][j]), 2);
		}
		std::vector<double> temp;
		temp.push_back(sum);
		error.push_back(temp);
	}

	std::cout << "test" << std::endl;

	std::cout << error.size() << std::endl;
	std::cout << error[0].size() << std::endl;
	for (int i = 0; i < error.size(); i++) {
		std::cout << error[i][0] << std::endl;
	}
*/

}
