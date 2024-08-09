#pragma once
#include<iostream>

class Complex
{
private:
    int R {0}, I {0};
public:
    void setComplex(int a, int b);
    void showComplex();

    // Static class member function
    static Complex addComplex( Complex &C1,  Complex &C2);
    static Complex conjugate( Complex &C);

    // Binary Operator Overloading as member function Note Here we can pass at least one argument 
    Complex operator -(Complex &C);
    // Complex operator +(Complex &C);
    Complex operator *(const Complex &C);
    Complex operator /(Complex &C);

    // Binary Operator Overloading as friend function Note Here we have to pass one more extra arg then the member function
    friend Complex operator +(Complex &C1, Complex &C2);

    // uninary Operator overloading as member function Note Here we can pass no argument 
    // Complex operator -();  Negative of number
    // Complex operator ++();
    // Complex operator --();
    // Complex operator -();

    // uninary Operator overloading as friend function Note Here we have to pass one more extra arg then the member function
    friend Complex operator -(Complex &C);


    // using stream to use cout and cin functionality 
    friend std::ostream& operator<<(std::ostream &,Complex &);
    friend std::istream& operator>>(std::istream &,Complex &);
    
};
