#include "Matrix.h"

Matrix::Matrix(const vector<vector<int>>& mat) {
	matrix = mat;
}

Matrix::Matrix(vector<vector<int>>&& mat) noexcept {
	matrix = mat;
}

Matrix::Matrix(const Matrix& mat) {
    matrix = mat.matrix;
}

Matrix::Matrix(Matrix&& mat) noexcept {
    matrix = move(mat.matrix);
    mat.matrix = vector<vector<int>>(0);
}

void Matrix::operator=(const Matrix& mat) {
    matrix = mat.matrix;
}

void Matrix::operator=(Matrix&& mat) noexcept {
    matrix = move(mat.matrix);
    mat.matrix = vector<vector<int>>(0);
}

pair<int, int> Matrix::size() {
	if (matrix.size() == 0) return make_pair(0, 0);
	return make_pair(matrix.size(), matrix[0].size());
}

Matrix Matrix::operator+(Matrix& right) {
    Matrix mat = matrix;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			mat[i][j] += right[i][j];
		}
	}
    return mat;
}

Matrix Matrix::input_matrix() {

    int l, c;

    cout << "Input your Matrix.\n";
    cout << "Number of lines: ";
    cin >> l;
    cout << "Number of colums: ";
    cin >> c;

    cout << "Your Matrix:\n";

    vector<vector<int>> mat(l);

    for (int i = 0; i < l; ++i) {
        vector<int> line(c);
        for (int j = 0; j < c; ++j) {
            cin >> line[j];
        }
        mat[i] = move(line);
    }
    matrix = move(mat);

    return matrix;
}

void Matrix::print_matrix() {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

int Matrix::det() {
    if (matrix.size() == 1) return matrix[0][0];
     
    int sum = 0;
    for (int i = 0; i < matrix.size(); i++) {
        vector<vector<int>> minor;
        for (int sr = 1; sr < matrix.size(); sr++) {
            vector<int> str_minor;
            for (int st = 0; st < matrix.size(); st++) {
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

int Matrix::det(vector<vector<int>>& mat) {
    if (mat.size() == 1) return mat[0][0];

    int sum = 0;
    for (int i = 0; i < mat.size(); i++) {
        vector<vector<int>> minor;
        for (int sr = 1; sr < mat.size(); sr++) {
            vector<int> str_minor;
            for (int st = 0; st < mat.size(); st++) {
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