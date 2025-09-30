#include "Matrix.hpp"

int main()
{
    Matrix<float> m1, m2, c;
    m1.input_matrix();
    m2.input_matrix();
    
    c = move(m1 * m2);
    c.print_matrix();

    return 0;
}