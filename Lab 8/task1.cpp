#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
private:
    double realPart;
    double imaginaryPart;

    friend double magnitude(Complex *c);

public:
    Complex() : realPart(0), imaginaryPart(0) {}

    Complex(int realPart, int imaginaryPart) : realPart(realPart), imaginaryPart(imaginaryPart) {}

    Complex operator+(const Complex &o)
    {
        return Complex(realPart + o.realPart, imaginaryPart + o.imaginaryPart);
    }

    Complex operator-(const Complex &o)
    {
        return Complex(realPart - o.realPart, imaginaryPart - o.imaginaryPart);
    }

    Complex operator*(const Complex &o)
    {
        Complex c;
        c.realPart = realPart * o.realPart - imaginaryPart * o.imaginaryPart;
        c.imaginaryPart = realPart * o.imaginaryPart + imaginaryPart * o.realPart;
        return c;
    }

    Complex operator/(const Complex &o)
    {
        Complex c;
        double denominator = pow(o.realPart, 2) + pow(o.imaginaryPart, 2);
        c.realPart = (realPart * o.realPart + imaginaryPart * o.imaginaryPart) / denominator;
        c.imaginaryPart = (imaginaryPart * o.realPart + realPart * o.imaginaryPart) / denominator;
        return c;
    }

    friend ostream &operator<<(ostream &os, Complex &o);
};

ostream &operator<<(ostream &os, Complex &o)
{
    os << "The Complex Number is: " << o.realPart;
    if (o.imaginaryPart >= 0) {
        os << " + " << o.imaginaryPart << "i";
    } else {
        os << " - " << -o.imaginaryPart << "i";
    }
    os << endl;
    return os;
}

double magnitude(Complex *c)
{

    return sqrt(pow(c->realPart, 2) + pow(c->imaginaryPart, 2));
}

int main()
{

    Complex num1(1, 1);
    Complex num2(1, 1);
    Complex add;

    add = num1 + num2;
    cout << add;

    Complex sub = num1 - num2;
    cout << sub;

    Complex product = num1 * num2;
    cout << product;

    Complex div = num1 / num2;
    cout << div;

    cout << "The magnitude of num1 is: " << magnitude(&num1) << " " << endl;
    ;
    cout << "The magnitude of num2 is: " << magnitude(&num2) << " " << endl;
    ;

    return 0;
}
