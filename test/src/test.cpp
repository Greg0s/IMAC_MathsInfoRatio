#include "../../libRatio/include/Ratio.hpp"
#include <iostream>

int main(){
     //Instanciation des ratios utilisés pour les tests
    Ratio<int> r1(4, 5);
    Ratio<int> r2(9,2);
    Ratio<int> r3(-9,2);
    Ratio<int> r4(10,10);
    Ratio<int> r5(8, 10);

    Ratio<int> res(53, 10);

    
    std::cout << "Test display : ";
    r4.display();
    std::cout<<std::endl;

    std::cout <<" ----------- "<< std::endl;

    std::cout << "Test addition" << std::endl;
    if((r1 + r2) == res){
        std::cout << "c'est ok" << std::endl;
        std::cout << r1 + r2 << std::endl;
    }
    std::cout << r1 + r3 << std::endl;

    std::cout <<" ----------- "<< std::endl;
    
    Ratio<int> res1(-37, 10);
    Ratio<int> res2(37, 10);
    std::cout << "Test soustraction" << std::endl;
    if((r1 - r2) == res1 && (r2 - r1) == res2){
        std::cout << "c'est ok" << std::endl;
        std::cout << r1 - r2;
        std::cout << r2 - r1 << std::endl;
    }
   

    std::cout <<" ----------- "<< std::endl;

    Ratio<int> res3(18, 5);
    std::cout << "Test mutliplication" << std::endl;
    if((r1 * r2) == res3 && (r2 * r1) == res3){
        std::cout << "c'est ok" << std::endl;
        std::cout << r2 * r1;
        std::cout << r1 * r2 << std::endl;
    }
    

    std::cout <<" ----------- "<< std::endl;

    Ratio<int> res4(8, 45);
    Ratio<int> res5(45, 8);
    Ratio<int> res6(8, -45);
    std::cout << "Test division" << std::endl;
    if( (r1 / r2) == res4 && (r2 / r1) == res5 && (r1 / r3) == res6){
        std::cout << "c'est ok" << std::endl;
        std::cout << r1 / r2;
        std::cout << r2 / r1;
        std::cout << r1 / r3 << std::endl;
    }
    
    std::cout <<" ----------- "<< std::endl;

    Ratio<int> res7(49, 25);
    std::cout << "Test multiplication ratio * float" << std::endl;
    if((r1 * 2.45) == res7){
        std::cout << "c'est ok" << std::endl;
        std::cout << r1 * 2.45 << std::endl;
    }

    std::cout <<" ----------- "<< std::endl;

    std::cout << "Test multiplication float * ratio" << std::endl;
    if((2.45 * r1) == 1.96){
        std::cout << "c'est ok" << std::endl;
        std::cout << 2.45 * r1 << std::endl << std::endl;
    }

    std::cout <<" ----------- "<< std::endl;

    std::cout << "Test moins unaire" << std::endl;
    std::cout<< -r2;
    std::cout<< -r3<< std::endl;

    std::cout <<" ----------- "<< std::endl;

    std::cout << "Test absolute : " << r3.absolute() << std::endl;

     std::cout <<" ----------- "<< std::endl;

    std::cout << "Test floor : " << r3.floor() << std::endl;

     std::cout <<" ----------- "<< std::endl;

    std::cout << "Test operators" << std::endl;
    if(r2 == r3){
        std::cout << "== must not show" << std::endl;
    }
    if(r1 == r5){
        std::cout << "== must show" << std::endl;
    }
    if(r2 != r3){
        std::cout << "!= must show" << std::endl;
    }
    if(r1 != r5){
        std::cout << "!= must not show" << std::endl;
    }
    if(r4 > r1){
        std::cout << "> must show" << std::endl;
    }
    if(r1 > r2){
        std::cout << "> must not show" << std::endl;
    }
    if(r1 < r2){
        std::cout << "< must show" << std::endl;
    }
    if(r2 < r1){
        std::cout << "< must not show" << std::endl;
    }

    if(r1 >= r5){
        std::cout << ">= must show 1" << std::endl;
    }
    if(r1 >= r3){
        std::cout << ">= must show 2" << std::endl;
    }
    if(r3 >= r1){
        std::cout << ">= must not show" << std::endl;
    }

    if(r1 <= r2){
        std::cout << "<= must show" << std::endl;
    }

    std::cout << std::endl;

    float aFloat1 = 0.8;
    Ratio<int> aRatio1 = convert_float_to_ratio<int>(aFloat1, 3);
    std::cout << "convert float : " << aFloat1 << " to ratio : " << aRatio1 << std::endl;

    float aFloat2 = 5.8;
    Ratio<int> aRatio2 = convert_float_to_ratio<int>(aFloat2, 3);
    std::cout << "convert float : " << aFloat2 << " to ratio : " << aRatio2 << std::endl;

    float aFloat3 = -8.35;
    Ratio<int> aRatio3 = convert_float_to_ratio<int>(aFloat3, 5);
    std::cout << "convert float : " << aFloat3 << " to ratio : " << aRatio3 << std::endl;

    std::cout << std::endl << "Test ratio grand nombre" << std::endl;
    std::cout << convert_float_to_ratio<double>(64465.5456456,10);
      std::cout << std::endl << "Test ratio petit nombre" << std::endl;
    std::cout << convert_float_to_ratio<double>(0.5456456,10);
    
    return 0;

}