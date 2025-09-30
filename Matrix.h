#ifndef MATRIX_H
#define MATRIX_H
//feature/mul_div

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Matrix {
	vector<vector<int>> matrix;

	int det(vector<vector<int>>& mat);
	class HelperString {
		vector<int>* string;
	public:
		HelperString(vector<int>* str) : string(str) {}
		int& operator[](int j) {
			return (*string)[j];
		}
	};
public:

	Matrix(){}

	~Matrix(){}

	Matrix(const vector<vector<int>>& mat);

	Matrix(vector<vector<int>>&& mat) noexcept;

	Matrix(const Matrix& mat);

	Matrix(Matrix&& mat) noexcept;

	void operator =(const Matrix& right);

	void operator =(Matrix&& right) noexcept;

	Matrix operator +(Matrix& right);

	Matrix operator -(Matrix& right);

	void operator +=(Matrix& right);

	void operator -=(Matrix& right);

	HelperString& operator [](int i) {
		HelperString h = HelperString(&matrix[i]);
		return h;
	}

	Matrix input_matrix();

	void print_matrix();

	int det();

	pair<int, int> size();

};




#endif