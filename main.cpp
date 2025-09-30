#include "Matrix.hpp"

int main()
{
    Matrix<float> m;
    m.input_matrix();
    m = m / 2.f;
    m.print_matrix();
    return 0;
}