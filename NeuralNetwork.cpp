#include "NeuralNetwork.h"
#include "Matrix.h"
#include <cstdlib>
#include <cmath>
#include <iostream>

#define EULER_E 2.71828

/* TODO
 * - dynamically create weight matrices so that we can have additional hidden layers
 */

/******************** Public member functions ********************/
NeuralNetwork::NeuralNetwork(int inputLayerSize, int numHiddenLayers, 
		int hiddenLayerSize, int outputLayerSize) :
		inputLayerSize(inputLayerSize), numHiddenLayers(numHiddenLayers), 
		hiddenLayerSize(hiddenLayerSize), outputLayerSize(outputLayerSize) {
	initialize();
}

void NeuralNetwork::train(Matrix& inputs, Matrix& targets) {
	// perform forward propegation
	Matrix a2 = Matrix::dot(inputs, w1);
	Matrix z2 = sigmoid(a2);

	Matrix a3 = Matrix::dot(z2, w2);
	Matrix z3 = sigmoid(a3);

	// perform backpropegation
	// calculate error
	Matrix error3 = targets - z3;
	std::cout << error3 << std::endl;
}

// Forward propegation through the neural network
Matrix NeuralNetwork::predict(Matrix& inputs) {
	Matrix a2 = Matrix::dot(inputs, w1);
	Matrix z2 = sigmoid(a2);

	Matrix a3 = Matrix::dot(z2, w2);
	Matrix z3 = sigmoid(a3);
	
	return z3;
}


/************ Private member functions  *************************/

void NeuralNetwork::initialize() {
	// create weight matrices
	srand(time(NULL));
	w1.setSize(inputLayerSize, hiddenLayerSize);
	w2.setSize(hiddenLayerSize, outputLayerSize);

	for (int i = 0; i < inputLayerSize; i++) {
		for (int j = 0; j < hiddenLayerSize; j++) {
			w1(i, j) = (double)rand() / RAND_MAX;
		}
	}
	for (int i = 0; i < hiddenLayerSize; i++) {
		for (int j = 0; j < outputLayerSize; j++) {
			w2(i, j) = (double)rand() / RAND_MAX;
		}
	}
}
double NeuralNetwork::sigmoid(double d) {
	return 1 / (1 + std::pow(EULER_E, -d)); 
}

// Perform the sigmoid function on every element
Matrix NeuralNetwork::sigmoid(const Matrix& mat) {
	Matrix temp(mat);
	for (int i = 0; i < mat.rows(); i++) {
		for (int j = 0; j < mat.cols(); j++) {
			temp(i, j) = sigmoid(mat(i, j));
		}
	}
	return temp;
}

Matrix NeuralNetwork::sigmoidPrime(const Matrix& mat) {
	Matrix temp(mat);
	for (int i = 0; i < mat.rows(); i++) {
		for (int j = 0; j < mat.cols(); j++) {
			temp(i, j) = sigmoidPrime(mat(i, j));
		}
	}
	return temp;
}
double NeuralNetwork::sigmoidPrime(double d) {
	return sigmoid(d) * (1 - sigmoid(d));
}

