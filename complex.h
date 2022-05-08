#pragma once

namespace ComplexNumber
{
    class Complex
    {
        private:
            double _real;
            double _imaginary;
        
        public:
        // default constructor
            Complex(); 
        
        // parametrised constructor
            Complex(double real);
            Complex(double real, double imaginary); 
        
        // copy constructor
            Complex(const Complex& other); 

        // getters
            double getReal() const; 
            double getImaginary() const; 

        // complex number specific operation
            Complex conjugate() const;
            double magnitude() const;

        // operator overloading 
            const Complex& operator=(const Complex& other);
            Complex operator+(const Complex& other);
            Complex operator-(const Complex& other);
            Complex operator*(const Complex& other);
            Complex operator/(const Complex& other);
    };

}


// operator overloading (stream insertion operator)
std::ostream& operator<<(std::ostream& out, const ComplexNumber::Complex& c);
