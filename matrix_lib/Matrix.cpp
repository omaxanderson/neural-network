#include "Matrix.h"
#include <iostream>
Matrix::Matrix() {

}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
	initialize();
}

Matrix::~Matrix() {

};

Matrix::Matrix(const Matrix& other) {
	data = other.data;
	rows = other.rows;
	cols = other.cols;
}

Matrix Matrix::dot(Matrix, Matrix) {

}

Matrix Matrix::transpose() {

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

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			os << m.data[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}

Matrix operator*(const Matrix&, const Matrix&) {

}
Matrix operator*(double, const Matrix&) {
}

Matrix operator*(const Matrix&, double) {
}

Matrix operator/(const Matrix&, const Matrix&) {
}
Matrix operator+(const Matrix&, const Matrix&) {
}
Matrix operator-(const Matrix&, const Matrix&) {
}
