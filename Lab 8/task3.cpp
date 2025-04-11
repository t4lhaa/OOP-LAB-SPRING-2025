#include <iostream>
using namespace std;

class Vector2D
{
private:
    double x;
    double y;

    friend int dotProduct(Vector2D &v1, Vector2D &v2);

public:
    Vector2D() : x(0), y(0) {}

    Vector2D(double x, double y) : x(x), y(y) {}

    Vector2D operator+(Vector2D &v1)
    {
        return Vector2D(this->x + v1.x, this->y + v1.y);
    }

    Vector2D operator-(Vector2D &v1)
    {
        return Vector2D(this->x - v1.x, this->y - v1.y);
    }

    Vector2D operator*(int scalar)
    {
        return Vector2D(this->x + scalar, this->y + scalar);
    }

    friend ostream &operator<<(ostream &os, const Vector2D &v);
};

int dotProduct(Vector2D &v1, Vector2D &v2)
{

    return (v1.x * v2.x + v1.y * v2.y);
}

ostream &operator<<(ostream &os, const Vector2D &v)
{

    os << "(" << v.x << "," << v.y << ")" << endl;
    return os;
}

int main()
{

    Vector2D v1(1, 1);
    Vector2D v2(1, 1);

    cout << "Addition: ";
    Vector2D add = v1 + v2;
    cout << add;

    cout << "Subtraction: " ;
    Vector2D subt = (v1 - v2);
    cout << subt;

    cout << "Scalar Multiplication: ";
    Vector2D multiply = v1 * 4;
    cout << multiply;

    cout << "The Dot Product of the vectors is: " << dotProduct(v1, v2) << endl;

    return 0;
}
