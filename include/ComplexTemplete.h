#pragma once

#include <iostream>

template <typename T>
class Complex
{
private:
    T R {0}, I {0};
public:
    void setComplex(T a, T b);
    void showComplex() ;
    static Complex addComplex( Complex &C1,  Complex &C2);
    static Complex conjugate( Complex &C);
    Complex operator -( Complex &C) ;
    Complex operator +( Complex &C) ;
    Complex operator *( Complex &C) ;
    Complex operator /( Complex &C) ;
};

template <typename T>
void Complex<T>::setComplex(T a, T b)
{
    R = a;
    I = b;
}

template <typename T>
void Complex<T>::showComplex() 
{
    if (I >= 0) std::cout << R << " + " << I << "i" << std::endl;
    else std::cout << R << " - " << -I << "i" << std::endl;
}

template <typename T>
Complex<T> Complex<T>::addComplex( Complex<T> &C1,  Complex<T> &C2)
{
    Complex<T> temp;
    temp.R = C1.R + C2.R;
    temp.I = C1.I + C2.I;
    return temp;
}

template <typename T>
Complex<T> Complex<T>::conjugate( Complex<T> &C)
{
    Complex<T> temp;
    temp.setComplex(C.R, -C.I);
    return temp;
}

template <typename T>
Complex<T> Complex<T>::operator +( Complex<T> &C) 
{
    Complex<T> temp;
    temp.R = R + C.R;
    temp.I = I + C.I;
    return temp;
}

template <typename T>
Complex<T> Complex<T>::operator -( Complex<T> &C) 
{
    Complex<T> temp;
    temp.R = R - C.R;
    temp.I = I - C.I;
    return temp;
}

template <typename T>
Complex<T> Complex<T>::operator *( Complex<T> &C) 
{
    Complex<T> temp;
    temp.R = R * C.R - I * C.I;
    temp.I = R * C.I + I * C.R;
    return temp;
}

template <typename T>
Complex<T> Complex<T>::operator /( Complex<T> &C) 
{
    Complex<T> temp;
    Complex<T> denom = C * conjugate(C);
    Complex<T> num = *this * conjugate(C);

    if (denom.R == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        return temp;
    }

    temp.R = num.R / denom.R;
    temp.I = num.I / denom.R;
    return temp;
}
