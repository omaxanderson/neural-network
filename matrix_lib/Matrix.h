#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>

class Matrix {
	public:
		// Constructors and destructor
		Matrix(int rows, int cols); 
		Matrix(const Matrix&);
		~Matrix();

		// Static member functions
		static Matrix dot(Matrix&, Matrix&);

		// Public member functions
		Matrix transpose();
		void fill(double d);

		// Public member operators
		friend std::ostream& operator<<(std::ostream&, const Matrix&);
		Matrix& operator*=(const Matrix&);
		Matrix& operator*=(double);
		Matrix& operator/=(const Matrix&);
		Matrix& operator/=(double d);
		Matrix& operator+=(const Matrix&);
		Matrix& operator-=(const Matrix&);
		inline double& operator()(int x, int y) { return data[x][y]; }
		inline double* operator[](int idx) { return data[idx]; }
//		friend std::istream& operator>>(std::istream, const Matrix&);

	private:
		// Private member functions
		void initialize();

		// Private instance variables
		double** data;
		int rows, cols;
};

// Non-member operator functions
Matrix operator*(const Matrix&, const Matrix&);
Matrix operator*(double, const Matrix&);
Matrix operator*(const Matrix&, double);

Matrix operator/(const Matrix&, const Matrix&);
Matrix operator/(double, const Matrix&);
Matrix operator/(const Matrix&, double);
Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);

#endif
