#ifndef MATRIX_H
#define MATRIX_H
//feature/mul_div

#include <iostream>
#include <vector>
#include <map>
#include <concepts>
using namespace std;

template<typename MatT>
concept T = integral<MatT> || floating_point<MatT>;

template<typename T>
class Matrix {
	vector<vector<T>> matrix;

	class HelperString {
		vector<T>* string;
	public:
		HelperString(vector<T>* str) : string(str) {}
		T& operator[](T j) {
			return (*string)[j];
		}
	};

    T det(vector<vector<T>>& mat) {
        if (mat.size() == 1) return mat[0][0];

        T sum = 0;
        for (size_t i = 0; i < mat.size(); i++) {
            vector<vector<T>> minor;
            for (size_t sr = 1; sr < mat.size(); sr++) {
                vector<T> str_minor;
                for (size_t st = 0; st < mat.size(); st++) {
                    if (st != i) {
                        str_minor.push_back(mat[sr][st]);
                    }
                }
                minor.push_back(str_minor);
            }
            if (i % 2) sum -= mat[0][i] * det(minor);
            else sum += mat[0][i] * det(minor);
        }
        return sum;
    }

public:
    Matrix(){}

    ~Matrix(){}

    Matrix(const vector<vector<T>>& mat) {
        matrix = mat;
    }

    Matrix(vector<vector<T>>&& mat) noexcept {
        matrix = mat;
    }

    Matrix(const Matrix& mat) {
        matrix = mat.matrix;
    }

    Matrix(Matrix&& mat) noexcept {
        matrix = move(mat.matrix);
        mat.matrix = vector<vector<T>>(0);
    }

    void operator=(const Matrix& mat) {
        matrix = mat.matrix;
    }

    void operator=(Matrix&& mat) noexcept {
        matrix = move(mat.matrix);
        mat.matrix = vector<vector<T>>(0);
    }

    pair<size_t, size_t> size() {
        if (matrix.size() == 0) return make_pair(0, 0);
        return make_pair(matrix.size(), matrix[0].size());
    }

    Matrix operator+(Matrix& right) {
        Matrix mat = matrix;
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[0].size(); j++) {
                mat[i][j] += right[i][j];
            }
        }
        return mat;
    }

    void operator+=(Matrix& right) {
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[0].size(); j++) {
                matrix[i][j] += right[i][j];
            }
        }
    }

    Matrix operator-(Matrix& right) {
        Matrix mat = matrix;
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[0].size(); j++) {
                mat[i][j] -= right[i][j];
            }
        }
        return mat;
    }

    void operator-=(Matrix& right) {
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[0].size(); j++) {
                matrix[i][j] -= right[i][j];
            }
        }
    }

    Matrix operator*(T num) {
        Matrix mat = *this;
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix.size(); j++) {
                mat[i][j] = num * mat[i][j];
            }
        }
        return mat;
    }

    Matrix operator/(T num) {
        try {
            T one = 1;
            if (num == 0) throw "Division by 0!";
            num = one / num;
            return this->operator*(num);
        }
        catch (const char* er) {
            cout << er << endl;
        }
    }

    HelperString& operator [](int i) {
        HelperString h = HelperString(&matrix[i]);
        return h;
    }

    Matrix input_matrix() {

        size_t l, c;

        cout << "Input your Matrix.\n";
        cout << "Number of lines: ";
        cin >> l;
        cout << "Number of colums: ";
        cin >> c;

        cout << "Your Matrix:\n";

        vector<vector<T>> mat(l);

        for (size_t i = 0; i < l; ++i) {
            vector<T> line(c);
            for (size_t j = 0; j < c; ++j) {
                cin >> line[j];
            }
            mat[i] = move(line);
        }
        matrix = move(mat);

        return matrix;
    }

    void print_matrix() {
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[0].size(); j++) {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
    }

    T det() {
        if (matrix.size() == 1) return matrix[0][0];

        T sum = 0;
        for (size_t i = 0; i < matrix.size(); i++) {
            vector<vector<T>> minor;
            for (size_t sr = 1; sr < matrix.size(); sr++) {
                vector<T> str_minor;
                for (size_t st = 0; st < matrix.size(); st++) {
                    if (st != i) {
                        str_minor.push_back(matrix[sr][st]);
                    }
                }
                minor.push_back(str_minor);
            }
            if (i % 2) sum -= matrix[0][i] * det(minor);
            else sum += matrix[0][i] * det(minor);
        }
        return sum;
    }

};

#endif