#include "NeuralNetwork.h"
#include "Matrix.h"
#include <cstdlib>
#include <iostream>

#define EULER_E 2.71828

/* TODO
 * - dynamically create weight matrices so that we can have additional hidden layers
 */

NeuralNetwork::NeuralNetwork(int inputLayerSize, int numHiddenLayers, 
		int hiddenLayerSize, int outputLayerSize) :
		inputLayerSize(inputLayerSize), numHiddenLayers(numHiddenLayers), 
		hiddenLayerSize(hiddenLayerSize), outputLayerSize(outputLayerSize) {
	initialize();
}

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

// Forward propegation through the neural network
Matrix NeuralNetwork::predict(Matrix& inputs) {
	Matrix a2(Matrix::dot(inputs, w1)); 

	return a2;
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

}
double NeuralNetwork::sigmoidPrime(double d) {

}

double NeuralNetwork::sigmoid(double d) {

}
