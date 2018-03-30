#include "NeuralNetwork.h"
#include <vector>
#include <cstdlib>
#include <iostream>

NeuralNetwork::NeuralNetwork() {
	inputLayerSize = 2;
	numHiddenLayers = 1;
	hiddenLayerSize = 2;
	outputLayerSize = 1;
}

NeuralNetwork::NeuralNetwork(int inputLayerSize, int numHiddenLayers, 
		int hiddenLayerSize, int outputLayerSize) : inputLayerSize(inputLayerSize), 
		numHiddenLayers(numHiddenLayers), hiddenLayerSize(hiddenLayerSize), 
		outputLayerSize(outputLayerSize) {

	srand(time(NULL));
	for (int layer = 0; layer < numHiddenLayers; layer++) {
		std::vector<double> temp;
		for (int node = 0; node < hiddenLayerSize; node++) {
			temp.push_back(rand() / RAND_MAX);
		}
		nodeWeights.push_back(temp);
	}
	std::cout << "initializing" << std::endl;
	
}


Matrix NeuralNetwork::matrixMultiply(const Matrix& mat1, const Matrix& mat2) {
	int rows = mat1.size();
	int cols = mat2[0].size();
	Matrix result;
	for (int i = 0; i < rows; i++) {
		result.push_back(std::vector<double>());
		for (int j = 0; j < cols; j++) {
			int sum = 0;
			for (int k = 0; k < mat2.size(); k++) {
				sum += mat1[i][k] * mat2[k][j];
			}
			result[i].push_back(sum);
		}
	}
	return result;
}
