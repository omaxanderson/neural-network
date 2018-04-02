#include "Matrix.h"
#include <stdexcept>
#include <iostream>
Matrix::Matrix() {

}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
	initialize();
}

Matrix::~Matrix() {

};

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

// Returns the dot product of the matrices.
// Matrices must be NxM and MxK, respectively
Matrix Matrix::dot(Matrix& m1, Matrix& m2) {
	Matrix temp(

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

void Matrix::initialize() {
	data = new double*[rows];
	for (int i = 0; i < rows; i++) {
		data[i] = new double[cols];
		for (int j = 0; j < cols; j++) {
			data[i][j] = 0;
		}
	}
}

void Matrix::fill(double d) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] = d;
		}
	}
}

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

Matrix& Matrix::operator*=(double d) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			data[i][j] *= d;
		}
	}
	return *this;
}

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

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			os << m.data[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}

// Performs an element-wise multiplication on the matrices
Matrix operator*(const Matrix& m1, const Matrix& m2) {
	Matrix temp(m1);
	return (temp *= m2); 
}
Matrix operator*(double d, const Matrix& m) {
	Matrix temp(m);
	return (temp *= d); 
}

Matrix operator*(const Matrix& m, double d) {
	return (m * d); 
}

Matrix operator/(const Matrix& m1, const Matrix& m2) {
	Matrix temp(m1);
	return (temp /= m2); 
}
Matrix operator+(const Matrix& m1, const Matrix& m2) {
	Matrix temp(m1);
	return (temp += m2); 
}
Matrix operator-(const Matrix& m1, const Matrix& m2) {
	Matrix temp(m1);
	return (temp -= m2); 
}
