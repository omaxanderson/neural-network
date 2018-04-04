#include "Matrix.h"
#include <stdexcept>
#include <cmath>
#include <iostream>

Matrix::Matrix() {
	_rows = -1;
	_cols = -1;
}

// Main constructor -- requires matrix size in number of rows and columns
Matrix::Matrix(int rows, int cols) : _rows(rows), _cols(cols) {
	initialize();
}

// Allows for a 2d vector to initialize it, makes it 
// easier to create the mat with an initializer list
Matrix::Matrix(std::vector< std::vector<double> > mat) {
	_rows = mat.size();
	_cols = mat[0].size();
	initialize();
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			data[i][j] = mat[i][j];
		}
	}
}

// Destructor
// not sure why but this makes causes all sorts of issues when run
Matrix::~Matrix() {
/*	for (int i = 0; i < _rows; i++) {
		delete[] data[i];
	}
	delete[] data;
	*/
};

// Copy constructor
Matrix::Matrix(const Matrix& other) {
	_rows = other._rows;
	_cols = other._cols;
	initialize();

	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			data[i][j] = other.data[i][j];
		}
	}
}

// Static method for matrix multiplication
// This is not technically a dot product, but uses the dot function
// instead of elementwise multiplication
// TODO - probably swap this and the current multiplication function
// Matrices must be NxM and MxK, respectively
Matrix Matrix::dot(const Matrix& m1, const Matrix& m2) {
	Matrix temp(m1._rows, m2._cols);
	for (int i = 0; i < temp._rows; i++) {
		for (int j = 0; j < temp._cols; j++) {
			for (int k = 0; k < m1._cols; k++) {
				temp(i, j) += m1(i, k) * m2(k, j);
			}
		}
	}
	return temp;
}

// Returns the transpose of the matrix
// If the matrix is an MxN, the transpose is NxM
Matrix Matrix::transpose() const {
	Matrix temp(_cols, _rows);
	for (int i = 0; i < _cols; i++) {
		for (int j = 0; j < _rows; j++) {
			temp(i, j) = data[j][i];
		}
	}
	return temp;
}

// Fills the matrix with a specified value
void Matrix::fill(double d) {
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			data[i][j] = d;
		}
	}
}

// Allows for matrices to be declared but not immediately initialized
// Need to add the functionality to change the size of a preexisting matrix
void Matrix::setSize(int rows, int cols) {
	if (_rows < 0 && _cols < 0) {
		_rows = rows;
		_cols = cols;
		initialize();
	}
}

int Matrix::rows() const {
	return _rows;
}
int Matrix::cols() const {
	return _cols;
}

Matrix Matrix::pow(const Matrix& m, double d) {
	Matrix temp(m);
	for (int i = 0; i < temp.rows(); i++) {
		for (int j = 0; j < temp.cols(); j++) {
			temp(i, j) = std::pow(temp(i, j), d);
		}
	}
	return temp;
}

void Matrix::normalize() {
	// lets do this column by column
	for (int col = 0; col < _cols; col++) {
		double min = data[0][col];
		double max = data[0][col];
		for (int row = 0; row < _rows; row++) {
			if (data[row][col] < min) {
				min = data[row][col];
			}
			if (data[row][col] > max) {
				max = data[row][col];
			}
		}

		for (int i = 0; i < _rows; i++) {
			data[i][col] = (data[i][col] - min) / (max - min);
		}
	}
}

/****************** Private class functions  **************************/

// Creates an appropriately sized matrix using given rows and _cols
void Matrix::initialize() {
	data = new double*[_rows];
	for (int i = 0; i < _rows; i++) {
		data[i] = new double[_cols];
		for (int j = 0; j < _cols; j++) {
			data[i][j] = 0;
		}
	}
}
/****************  Member operator functions  *******************/

Matrix& Matrix::operator=(const Matrix& other) {
	_rows = other._rows;
	_cols = other._cols;
	initialize();
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _rows; j++) {
			data[i][j] = other.data[i][j];
		}
	}
	return *this;
}


// ELEMENT-WISE matrix multiplication
// Multiplies each element of the matrix to the respective element in 
// other matrix
// Matrices must be same size
Matrix& Matrix::operator*=(const Matrix& other) {
	if (_rows != other._rows || _cols != other._cols) {
		throw std::invalid_argument("matrices are not the same size");
	}
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			data[i][j] *= other.data[i][j];
		}
	}
	return *this;
}

// Scalar element-wise multiplication
Matrix& Matrix::operator*=(double d) {
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			data[i][j] *= d;
		}
	}
	return *this;
}

// Element-wise matrix division
Matrix& Matrix::operator/=(const Matrix& other) {
	if (_rows != other._rows && _cols != other._cols) {
		throw std::invalid_argument("matrices are not the same size");
	}
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			data[i][j] /= other.data[i][j];
		}
	}
	return *this;
}

// Element-wise scalar division
Matrix& Matrix::operator/=(double d) {
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			data[i][j] /= d;
		}
	}
	return *this;
}

// Element-wise matrix addition
Matrix& Matrix::operator+=(const Matrix& other) {
	if (_rows != other._rows && _cols != other._cols) {
		throw std::invalid_argument("matrices are not the same size");
	}
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			data[i][j] += other.data[i][j];
		}
	}
	return *this;

}

// Element-wise matrix subtraction
Matrix& Matrix::operator-=(const Matrix& other) {
	if (_rows != other._rows && _cols != other._cols) {
		throw std::invalid_argument("matrices are not the same size");
	}
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			data[i][j] -= other.data[i][j];
		}
	}
	return *this;
}

// Outstream operator function
std::ostream& operator<<(std::ostream& os, const Matrix& m) {
	for (int i = 0; i < m._rows; i++) {
		for (int j = 0; j < m._cols; j++) {
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
