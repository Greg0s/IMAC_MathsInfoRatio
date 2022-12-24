#include "../../libRatio/include/Ratio.hpp"
#include <iostream>

int main(){
    Ratio<int> r1(4, 5);
    Ratio<int> r2(9,2);
    Ratio<int> r3(-9,2);
    Ratio<int> r4(8,10);
    
    r1.display();

    std::cout << "Test addition" << std::endl;
    std::cout << r1 + r2 << std::endl;

    std::cout << "Test soustraction" << std::endl;
    std::cout << r1 - r2 << std::endl;
    std::cout << r2 - r1 << std::endl;

    std::cout << "Test mutliplication" << std::endl;
    std::cout << r2 * r1 << std::endl;
    std::cout << r1 * r2 << std::endl;

    std::cout << "Test division" << std::endl;
    std::cout << r1 / r2 << std::endl;
    std::cout << r2 / r1 << std::endl;

    std::cout << "Test moins unaire" << std::endl;
    std::cout<< -r2<< std::endl;
    //std::cout<< -r3<< std::endl;

    std::cout << "Test absolute : " << r3.absolute() << std::endl;

    std::cout << "Test floor : " << r3.floor() << std::endl;

    if(r2 == r3){
        std::cout << "==1" << std::endl;
    }
    if(r1 == r4){
        std::cout << "==2" << std::endl;
    }
    if(r2 != r3){
        std::cout << "!=1" << std::endl;
    }
    if(r1 != r4){
        std::cout << "!=2" << std::endl;
    }
    
    return 0;
}