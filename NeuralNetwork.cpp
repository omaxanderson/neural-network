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

void NeuralNetwork::train(const Matrix& inputs, const Matrix& targets, int iterations) {
	for (int i = 0; i < iterations; i++) {
		// perform forward propegation
		Matrix z2 = Matrix::dot(inputs, w1);
		Matrix a2 = sigmoid(z2);

		Matrix z3 = Matrix::dot(a2, w2);
		Matrix a3 = sigmoid(z3);

		Matrix delta3 = ((targets - a3) * -1) * sigmoidPrime(z3);
		Matrix dJdW2 = Matrix::dot(a2.transpose(), delta3);

		Matrix delta2 = Matrix::dot(delta3, w2.transpose()) * sigmoidPrime(z2);
		Matrix dJdW1 = Matrix::dot(inputs.transpose(), delta2);

		w1 -= learningRate * dJdW1;
		w2 -= learningRate * dJdW2;
	}
	/*
	std::cout << "delta3" << std::endl;
	std::cout << delta3 << std::endl;
	std::cout << "djdw2" << std::endl;
	std::cout << dJdW2 << std::endl;
	std::cout << "delta2" << std::endl;
	std::cout << delta2 << std::endl;
	std::cout << "djdw1" << std::endl;
	std::cout << dJdW1 << std::endl;
	*/
}

// Forward propegation through the neural network
Matrix NeuralNetwork::predict(const Matrix& inputs) {
	Matrix a2 = Matrix::dot(inputs, w1);
	Matrix z2 = sigmoid(a2);

	Matrix a3 = Matrix::dot(z2, w2);
	Matrix z3 = sigmoid(a3);
	
	return z3;
}

void NeuralNetwork::setLearningRate(double d) {
	if (d > 0) {
		learningRate = d;
	} else {
		learningRate = 0.0001;
	}
}
double NeuralNetwork::getLearningRate() {
	return learningRate;
}


/************ Private member functions  *************************/

void NeuralNetwork::initialize() {
	// create weight matrices
	srand(time(NULL));
	w1.setSize(inputLayerSize, hiddenLayerSize);
	w2.setSize(hiddenLayerSize, outputLayerSize);
	learningRate = 0.1;

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

