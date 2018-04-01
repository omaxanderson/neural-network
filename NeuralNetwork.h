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

	private:
		Matrix forward(Matrix inputs);
		int inputLayerSize, numHiddenLayers, hiddenLayerSize, outputLayerSize;
		Matrix w1, w2;

		void initialize();
		Matrix dot(const Matrix& mat1, const Matrix& mat2);
		Matrix sigmoid(const Matrix& mat);
		Matrix sigmoidPrime(const Matrix& mat);
		double sigmoidPrime(double d);
		double sigmoid(double d);
		Matrix multiply(double d, Matrix m);
		Matrix transpose(Matrix m);
		Matrix elementMultiply(Matrix m1, Matrix m2);
		Matrix elementSubtract(Matrix m1, Matrix m2);

		// matrices for each step in the process
};

#endif
