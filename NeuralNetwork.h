#ifndef _NEURAL_NETWORK_H_
#define _NEURAL_NETWORK_H_

#include "matrix_lib/Matrix.h"

class NeuralNetwork {
	public: 
		NeuralNetwork();
		NeuralNetwork(int inputLayerSize, int numHiddenLayers, 
				int hiddenLayerSize, int outputLayerSize);
		Matrix predict(const Matrix& inputs);
		void train(const Matrix& inputs, const Matrix& targets);

	private:
		Matrix forward(const Matrix& inputs);
		int inputLayerSize, numHiddenLayers, hiddenLayerSize, outputLayerSize;
		Matrix w1, w2;

		void initialize();
		Matrix sigmoid(const Matrix& mat);
		Matrix sigmoidPrime(const Matrix& mat);
		double sigmoidPrime(double d);
		double sigmoid(double d);
};

#endif
