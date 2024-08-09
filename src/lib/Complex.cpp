#include <iostream>
#include "Complex.h"

void Complex::setComplex(int a, int b)
{
    R = a;
    I = b;
}

void Complex::showComplex()
{
    if (I>=0) std::cout << R << " + " << I << "i" << std::endl;
    else std::cout << R << " - " << -I << "i" << std::endl;
}

Complex Complex::addComplex(Complex &C1, Complex &C2)
{
    Complex temp;
    temp.R = C1.R + C2.R;
    temp.I = C1.I + C2.I;
    return temp;
}

Complex Complex::conjugate(Complex &C)  
{
    Complex temp;
    temp.setComplex(C.R, -C.I);  
    return temp;
}

// Complex Complex::operator +(Complex &C)
// {
//     Complex temp;
//     temp.R = R + C.R;
//     temp.I = I + C.I;
//     return temp;
// }

Complex Complex::operator -(Complex &C)
{
    Complex temp;
    temp.R = R - C.R;
    temp.I = I - C.I;
    return temp;
}

Complex Complex::operator *(const Complex &C)
{
    Complex temp;
    temp.R = R*C.R - I*C.I;
    temp.I = R*C.I + I*C.R;
    return temp;
}

Complex Complex::operator /(Complex &C)
{
    Complex temp;
    Complex denom = C * conjugate(C); 
    Complex num = *this * conjugate(C); 

    if (denom.R == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        return temp;
    }

    temp.R = num.R / denom.R;
    temp.I = num.I / denom.R;
    return temp;
}

// Complex Complex::operator -()
// {
//     Complex temp;
//     temp.R = -R;
//     temp.I = -I;
//     return temp;
// }

Complex operator +(Complex &C1, Complex &C2)
{
    Complex temp;
    temp.R = C1.R + C2.R;
    temp.I = C1.I + C2.I;
    return temp;
}

Complex operator -(Complex &C)
{
    Complex temp;
    temp.R = -C.R;
    temp.I = -C.I;
    return temp;
}


std::ostream& operator <<(std::ostream &dout,Complex &C)
{
    if (C.I>=0) std::cout << C.R << " + " << C.I << "i" ;
    else std::cout << C.R << " - " << -C.I << "i";
    return dout;
}

std::istream& operator >>(std::istream &din,Complex &C)
{
    std::cout<<"real: ";
    std::cin>>C.R;
    std::cout <<"img: ";
    std::cin>>C.I;
    return din;
}