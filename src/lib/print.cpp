#include <iostream>
#include "print.h"  

void PRINT::printMe()
{
    # ifdef DEBUG
    std::cout<<"Hello Cmake from Debug";
    # endif 

    # ifdef RELEASE
    std::cout<<"Hello Cmake from RELEASE";
    # endif 
}
