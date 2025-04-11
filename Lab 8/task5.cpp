#include <iostream>
using namespace std;

class Matrix2x2
{
private:
    int a1, a2, a3, a4;

    friend int calculateDeterminant(Matrix2x2 &m);
    friend class MatrixHelper;
    friend ostream &operator<<(ostream &os, const Matrix2x2 &m);

public:
    Matrix2x2() : a1(0), a2(0), a3(0), a4(0) {}

    Matrix2x2(int a1, int a2, int a3, int a4) : a1(a1), a2(a2), a3(a3), a4(a4) {}

    Matrix2x2 operator+(Matrix2x2 &matrix)
    {
        return Matrix2x2(a1 + matrix.a1, a2 + matrix.a2, a3 + matrix.a3, a4 + matrix.a4);
    }

    Matrix2x2 operator-(Matrix2x2 &matrix)
    {
        return Matrix2x2(a1 - matrix.a1, a2 - matrix.a2, a3 - matrix.a3, a4 - matrix.a4);
    }
    Matrix2x2 operator*(Matrix2x2 &matrix)
    {
        return Matrix2x2(a1 * matrix.a1, a2 * matrix.a2, a3 * matrix.a3, a4 * matrix.a4);
    }
};

class MatrixHelper
{

public:
    void updateMatrix(Matrix2x2 &m)
    {
        string old;
        int neww;
        cout << "Enter the element you want to update: ";
        cin >> old;
        cout << "Enter new value: ";
        cin >> neww;
        if (old == "a1")
        {
            m.a1 = neww;
        }
        else if (old == "a2")
        {
            m.a2 = neww;
        }
        else if (old == "a3")
        {
            m.a3 = neww;
        }
        else if (old == "a4")
        {
            m.a4 = neww;
        }
        else
        {
            cout << "Invalid Old Element!" << endl;
        }
    }
};

int calculateDeterminant(Matrix2x2 &m)
{
    return (m.a1 * m.a4 - m.a2 * m.a3);
}

ostream &operator<<(ostream &os, const Matrix2x2 &m)
{
    os << "| " << m.a1 << "  " << m.a2 << " |" << endl;
    os << "| " << m.a3 << "  " << m.a4 << " |" << endl;
    return os;
}

int main()
{

    Matrix2x2 mat1(1,1,1,1);
    Matrix2x2 mat2(1,1,1,1);
    MatrixHelper update;

    cout << "Addition" << endl;
    Matrix2x2 add = mat1 + mat2;
    cout << add;

    cout << "Subtraction" << endl;
    Matrix2x2 sub = mat1 - mat2;
    cout << sub;

    cout << "Multiplication" << endl;
    Matrix2x2 multiply = mat1 * mat2;
    cout << multiply;

    cout << "Determinant of Matrix A" << endl;
    cout << " Determinant is: " << calculateDeterminant(mat1) << " " << endl;

    cout << "eterminant of Matrix B" << endl;
    cout << " Determinant is: " << calculateDeterminant(mat2) << " " << endl;

    cout << "Updating Matrix A" << endl;
    update.updateMatrix(mat1);
    cout << mat1;
    
    cout << "Updating Matrix B" << endl;
    update.updateMatrix(mat2);
    cout << mat2;

    return 0;
}
