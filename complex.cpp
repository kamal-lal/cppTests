#include <iostream>
#include <cmath>
#include "complex.h"

#define DEBUG 0

#if DEBUG
#define SHOW(x) std::cout<<x<<std::endl
#else
#define SHOW(x)
#endif


namespace ComplexNumber
{
// default constructor
    Complex::Complex()
        : _real(0), _imaginary(0)
    {
        SHOW("Default Constructor invoked!");
    }

// parametrised constructor
    Complex::Complex(double real)
        : _real(real), _imaginary(0)
    {
        SHOW("Parametrised Constructor-1 invoked!"); 
    }

    Complex::Complex(double real, double imaginary)
        : _real(real), _imaginary(imaginary)
    {
        SHOW("Parametrised Constructor-2 invoked!"); 
    }

// copy constructor
    Complex::Complex(const Complex& other)
        :_real(other._real), _imaginary(other._imaginary)
    {
        SHOW("Copy Constructor invoked!"); 
    }

// getters
    double Complex::getReal() const { return _real; }
    double Complex::getImaginary() const { return _imaginary; }

// complex number specific operation
    Complex Complex::conjugate() const
    {
        return Complex(_real, -_imaginary);
    }

    double Complex::magnitude() const
    {
        return sqrt(_real * _real + _imaginary * _imaginary);
    }

// operator overloading (=)
    const Complex& Complex::operator=(const Complex& other)
    {
        _real = other._real;
        _imaginary = other._imaginary;

        SHOW("Overloaded '=' used!"); 
        return *this;    
    }

// operator overloading (+)
    Complex Complex::operator+(const Complex& other)
    {
        Complex result;
        
        result._real = _real + other._real;
        result._imaginary = _imaginary + other._imaginary;

        SHOW("Overloaded '+' used!");
        return result;
    }

// operator overloading (-)
    Complex Complex::operator-(const Complex& other)
    {
        Complex result;
        
        result._real = _real - other._real;
        result._imaginary = _imaginary - other._imaginary;

        SHOW("Overloaded '-' used!");
        return result;
    }

// operator overloading (*)
    Complex Complex::operator*(const Complex& other)
    {
        Complex result;
        double a{_real}, b{_imaginary}, c{other._real}, d{other._imaginary};

        result._real = a*c - b*d;
        result._imaginary = a*d + b*c;
    
        SHOW("Overloaded '*' used!");
        return result;
    }

// operator overloading (/)
    Complex Complex::operator/(const Complex& other)
    {
        Complex result;
        double a{_real}, b{_imaginary}, c{other._real}, d{other._imaginary};

        result._real = (a*c + b*d) / (c*c + d*d);
        result._imaginary = (b*c - a*d) / (c*c + d*d);
        
        SHOW("Overloaded '/' used!");
        return result;
    }

}

// operator overloading (<<)
std::ostream& operator<<(std::ostream& out, const ComplexNumber::Complex& c)
{
    double im = c.getImaginary();
    char symbol[] = " + ";

    if (im < 0)
    {
        im = -im;
        symbol[1] = '-';
    }
    out << "(" << c.getReal() << symbol << im << "j)";

    return out;
}