#include "NeuralNetwork.h"
#include <cmath>
#include <vector>
#include <cstdlib>
#include <iostream>

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
	std::cout << "initializing" << std::endl;
	
	srand(time(NULL));
	for (int layer = 0; layer < inputLayerSize; layer++) {
		std::vector<double> temp;
		for (int node = 0; node < hiddenLayerSize; node++) {
			temp.push_back(rand() / RAND_MAX);
		}
		synapseWeights.push_back(temp);
	}

	for (int i = 0; i < hiddenLayerSize; i++) {
		w2.push_back(std::vector<double>());
		w2[i].push_back(rand() / RAND_MAX);
	}

}

Matrix NeuralNetwork::dot(const Matrix& mat1, const Matrix& mat2) {
	if (mat1[0].size() != mat2.size()) {
		return Matrix();
	}
	// DEBUGGING
//	std::cout << "mat1 = " << mat1.size() << "x" << mat1[0].size() << std::endl;
//	std::cout << "mat2 = " << mat2.size() << "x" << mat2[0].size() << std::endl;
	int rows = mat1.size();
	int cols = mat2[0].size();
	Matrix result;
	for (int i = 0; i < rows; i++) {
		result.push_back(std::vector<double>());
		for (int j = 0; j < cols; j++) {
			double sum = 0;
			for (int k = 0; k < mat2.size(); k++) {
				sum += mat1[i][k] * mat2[k][j];
			}
			result[i].push_back(sum);
		}
	}
	return result;
}

// Calls the activation function specified upon every 
// item in Matrix mat
Matrix NeuralNetwork::sigmoid(const Matrix& mat) {
	Matrix result;
	for (const std::vector<double> vec : mat) {
		std::vector<double> temp;
		for (const double num : vec) {
			temp.push_back(sigmoid(num));
		}
		result.push_back(temp);
	}
	return result;
}

// Sigmoid activation function
double NeuralNetwork::sigmoid(double d) {
	double e = 2.71828;
	return 1 / (1 + std::pow(e, -d));
}

// Takes the input matrix, multiplies it with the weights, performs an
// activation function on it, then multiplies it by the second layer of 
// weights
double NeuralNetwork::forward(Matrix inputs) {
	Matrix h1 = dot(inputs, synapseWeights);
	Matrix a1 = sigmoid(h1);
	Matrix out = dot(a1, w2);
	double sum = 0;
	for (int i = 0; i < out.size(); i++) {
		sum += out[i][0];
	}
	return sigmoid(sum);


}

