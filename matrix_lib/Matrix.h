#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>

class Matrix {
	public:
		Matrix();
		Matrix(int rows, int cols); 
		~Matrix();
		Matrix(const Matrix&);
		static Matrix dot(Matrix, Matrix);
		Matrix transpose();
		friend std::ostream& operator<<(std::ostream&, const Matrix&);
		inline double operator()(int x, int y) { return data[x][y]; }
		inline double* operator[](int idx) { return data[idx]; }
//		friend std::istream& operator>>(std::istream, const Matrix&);

	private:
		void initialize();
		double** data;
		int rows, cols;

};

Matrix operator*(const Matrix&, const Matrix&);
Matrix operator*(double, const Matrix&);
Matrix operator*(const Matrix&, double);

Matrix operator/(const Matrix&, const Matrix&);
Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);

#endif
