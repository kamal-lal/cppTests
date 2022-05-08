#include <iostream>
#include "complex.h"

using namespace std;
using namespace ComplexNumber;

int main()
{
    // std::cout << "Hello, World!" << std::endl;
    // int newNum;

    Complex c1(1.2, 3.4);
    Complex c2(5.6, 7.8);
    Complex c3;

    c3 = c1 * 10;
    
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c3 = " << c3 << endl;
    
    return 0;
}