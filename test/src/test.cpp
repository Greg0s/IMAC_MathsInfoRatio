#include "../../libRatio/include/Ratio.hpp"
#include <iostream>

int main(){
    std::cout << "test" << std::endl;
    Ratio<int> r1(4, 5);
    Ratio<int> r2(9,2);
     Ratio<int> r3(-9,2);
    

    r1.display();
    std::cout << r1 + r2 << std::endl;
    std::cout << r1 - r2 << std::endl;

    std::cout << r2 - r1 << std::endl;

    std::cout << r2 * r1 << std::endl;
    std::cout << r1 * r2 << std::endl;

    std::cout << r1 / r2 << std::endl;
    std::cout << r2 / r1 << std::endl;

    std::cout<< -r2<< std::endl;
    std::cout<< -r3<< std::endl;
    
    
    return 0;
}