#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <vector>

class Matrix {
	public:
		// Constructors and destructor
		Matrix(); 
		Matrix(int rows, int cols); 
		Matrix(std::vector< std::vector<double> >);
		Matrix(const Matrix&);
		~Matrix();

		// Static member functions
		static Matrix dot(const Matrix&, const Matrix&);
		static Matrix pow(const Matrix&, double);

		// Public member functions
		Matrix transpose() const;
		void fill(double d);
		int rows() const;
		int cols() const;
		void setSize(int rows, int cols);

		// Public member operators
		friend std::ostream& operator<<(std::ostream&, const Matrix&);
		Matrix& operator=(const Matrix&);
		Matrix& operator*=(const Matrix&);
		Matrix& operator*=(double);
		Matrix& operator/=(const Matrix&);
		Matrix& operator/=(double d);
		Matrix& operator+=(const Matrix&);
		Matrix& operator-=(const Matrix&);
		inline double& operator()(int x, int y) const { return data[x][y]; }
		inline double* operator[](int idx) { return data[idx]; }
//		friend std::istream& operator>>(std::istream, const Matrix&);

	private:
		// Private member functions
		void initialize();

		// Private instance variables
		double** data;
		int _rows, _cols;
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
