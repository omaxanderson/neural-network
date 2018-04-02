#include "Matrix.h"
#include <stdexcept>
#include <iostream>


// Main constructor -- requires matrix size in number of rows and columns
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
	initialize();
}

// Destructor
Matrix::~Matrix() {
	for (int i = 0; i < rows; i++) {
		delete[] data[i];
	}
	delete[] data;
};

// Copy constructor
Matrix::Matrix(const Matrix& other) {
	rows = other.rows;
	cols = other.cols;
	initialize();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] = other.data[i][j];
		}
	}
}

// Static method for matrix multiplication
// This is not technically a dot product, but uses the dot function
// instead of elementwise multiplication
// TODO - probably swap this and the current multiplication function
// Matrices must be NxM and MxK, respectively
Matrix Matrix::dot(Matrix& m1, Matrix& m2) {
	Matrix temp(m1.rows, m2.cols);
	for (int i = 0; i < temp.rows; i++) {
		for (int j = 0; j < temp.cols; j++) {
			for (int k = 0; k < m1.cols; k++) {
				temp(i, j) += m1(i, k) * m2(k, j);
			}
		}
	}
	return temp;
}

// Returns the transpose of the matrix
// If the matrix is an MxN, the transpose is NxM
Matrix Matrix::transpose() {
	Matrix temp(cols, rows);
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			temp(i, j) = data[j][i];
		}
	}
	return temp;
}

// Fills the matrix with a specified value
void Matrix::fill(double d) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] = d;
		}
	}
}

/****************** Private class functions  **************************/

// Creates an appropriately sized matrix using given rows and cols
void Matrix::initialize() {
	data = new double*[rows];
	for (int i = 0; i < rows; i++) {
		data[i] = new double[cols];
		for (int j = 0; j < cols; j++) {
			data[i][j] = 0;
		}
	}
}
/****************  Member operator functions  *******************/

// ELEMENT-WISE matrix multiplication
// Multiplies each element of the matrix to the respective element in 
// other matrix
// Matrices must be same size
Matrix& Matrix::operator*=(const Matrix& other) {
	if (rows != other.rows || cols != other.cols) {
		throw std::invalid_argument("matrices are not the same size");
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] *= other.data[i][j];
		}
	}
	return *this;
}

// Scalar element-wise multiplication
Matrix& Matrix::operator*=(double d) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] *= d;
		}
	}
	return *this;
}

// Element-wise matrix division
Matrix& Matrix::operator/=(const Matrix& other) {
	if (rows != other.rows && cols != other.cols) {
		throw std::invalid_argument("matrices are not the same size");
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] /= other.data[i][j];
		}
	}
	return *this;
}

// Element-wise scalar division
Matrix& Matrix::operator/=(double d) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] /= d;
		}
	}
	return *this;
}

// Element-wise matrix addition
Matrix& Matrix::operator+=(const Matrix& other) {
	if (rows != other.rows && cols != other.cols) {
		throw std::invalid_argument("matrices are not the same size");
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] += other.data[i][j];
		}
	}
	return *this;

}

// Element-wise matrix subtraction
Matrix& Matrix::operator-=(const Matrix& other) {
	if (rows != other.rows && cols != other.cols) {
		throw std::invalid_argument("matrices are not the same size");
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] -= other.data[i][j];
		}
	}
	return *this;
}

// Outstream operator function
std::ostream& operator<<(std::ostream& os, const Matrix& m) {
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			os << m.data[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}

/****************  Non-member operator functions  **************************/

// Performs an element-wise multiplication on the matrices
Matrix operator*(const Matrix& m1, const Matrix& m2) {
	Matrix temp(m1);
	return (temp *= m2); 
}
Matrix operator*(double d, const Matrix& m) {
	return (m * d); 
}

Matrix operator*(const Matrix& m, double d) {
	Matrix temp(m);
	return (temp *= d); 
}

Matrix operator/(const Matrix& m1, const Matrix& m2) {
	Matrix temp(m1);
	return (temp /= m2); 
}
Matrix operator/(double d, const Matrix& m) {
	return (m * d); 
}

Matrix operator/(const Matrix& m, double d) {
	Matrix temp(m);
	return (temp /= d); 
}
Matrix operator+(const Matrix& m1, const Matrix& m2) {
	Matrix temp(m1);
	return (temp += m2); 
}
Matrix operator-(const Matrix& m1, const Matrix& m2) {
	Matrix temp(m1);
	return (temp -= m2); 
}
