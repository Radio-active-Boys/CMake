#include <iostream>
#include <conio.h> 
#include "ComplexTemplete.h"

int main()
{
    system("cls");

    Complex<int> C1, C2, C3, C4, C5, C6, C7, C8, D9;

    C1.setComplex(3, 4);
    C2.setComplex(5, 6);

    std::cout << "C1: ";
    C1.showComplex();
    std::cout << "C2: ";
    C2.showComplex();

    C3 = Complex<int>::addComplex(C1, C2);
    std::cout << "C3 (C1 + C2): ";
    C3.showComplex();

    C4 = Complex<int>::conjugate(C1);
    std::cout << "C4 (Conjugate of C1): ";
    C4.showComplex();

    C5 = C3 + C4;
    std::cout << "C5 (C3 + C4): ";
    C5.showComplex();

    C6 = C3 + C4 - C5;
    std::cout << "C6 (C3 + C4 - C5): ";
    C6.showComplex();

    C7 = C3 * C4;
    std::cout << "C7 (C3 * C4): ";
    C7.showComplex();

    C8 = C3 / C4;
    std::cout << "C8 (C3 / C4): ";
    C8.showComplex();

    C8 = C3 / C4 + C5;
    std::cout << "C8 (C3 / C4 + C5): ";
    C8.showComplex();

    Complex<double> D1, D2, D3, D4;

    D1.setComplex(3.5, 4.5);
    D2.setComplex(1.5, 2.5);

    std::cout << "D1: ";
    D1.showComplex();
    std::cout << "D2: ";
    D2.showComplex();

    D3 = Complex<double>::addComplex(D1, D2);
    std::cout << "D3 (D1 + D2): ";
    D3.showComplex();

    D4 = Complex<double>::conjugate(D1);
    std::cout << "D4 (Conjugate of D1): ";
    D4.showComplex();

    D3 = D3 + D4;
    std::cout << "D3 (D3 + D4): ";
    D3.showComplex();

    D4 = D3 - D4;
    std::cout << "D4 (D3 - D4): ";
    D4.showComplex();
 
    try {
        D4 = D3 / D4;
        std::cout << "D4 (D3 / D4): ";
        D4.showComplex();
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }



    _getch();

    return 0;
}
