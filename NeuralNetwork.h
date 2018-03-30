#ifndef _NEURAL_NETWORK_H_
#define _NEURAL_NETWORK_H_


#include <vector>

typedef std::vector< std::vector<double> > Matrix;

class NeuralNetwork {
	public: 
		NeuralNetwork();
		NeuralNetwork(int inputLayerSize, int numHiddenLayers, 
				int hiddenLayerSize, int outputLayerSize);
		Matrix matrixMultiply(const Matrix& mat1, const Matrix& mat2);

	private:
		int inputLayerSize, numHiddenLayers, hiddenLayerSize, outputLayerSize;
		Matrix nodeWeights;
};

#endif
