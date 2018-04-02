#ifndef _NEURAL_NETWORK_H_
#define _NEURAL_NETWORK_H_

#include "Matrix.h"
#include <unordered_map>
#include <string>

class NeuralNetwork {
	public: 
		NeuralNetwork(int inputLayerSize, int numHiddenLayers, 
				int hiddenLayerSize, int outputLayerSize);
		Matrix predict(Matrix& inputs);
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
		std::unordered_map<std::string, Matrix> matrices;
};

#endif
