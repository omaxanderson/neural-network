#ifndef _NEURAL_NETWORK_H_
#define _NEURAL_NETWORK_H_


#include <vector>

typedef std::vector< std::vector<double> > Matrix;

class NeuralNetwork {
	public: 
		NeuralNetwork();
		NeuralNetwork(int inputLayerSize, int numHiddenLayers, 
				int hiddenLayerSize, int outputLayerSize);
		Matrix predict(Matrix inputs);
		void train(Matrix inputs, Matrix targets);
		double sigmoidPrime(double d);

	private:
		int inputLayerSize, numHiddenLayers, hiddenLayerSize, outputLayerSize;
		Matrix synapseWeights, w2;

		void initialize();
		Matrix dot(const Matrix& mat1, const Matrix& mat2);
		Matrix sigmoid(const Matrix& mat);
		double sigmoid(double d);
};

#endif
