#include "../include/Ratio.hpp"
#include <iostream>
//#include "Ratio.hpp"

template<typename T>
void  Ratio<T>::display() {
    std::cout << num << " / " << denom << std::endl;
}

/*
template<typename T>
Ratio Ratio::operator=(const Ratio &ratio){
    if(this != &ratio){
        num=ratio.num;
        denom=ratio.denom;
    }
    return *this;
}

template<typename T>
Ratio Ratio::operator+(const Ratio &ratio){
    Ratio res;
    if(denom != ratio.denom){
        denomTmp = denom;
        denom = denom * ratio.denom;
        num = num * ratio.denom;
        ratio.denom = ratio.denom * denomTmp;
        ratio.num = ratio.num * denomTmp;
    }
    res.num=ratio.num + num;
    res.denom=ratio.denol+denom;
    return res;
}

template<typename T>
Ratio Ratio::operator-(const Ratio &ratio){
    Ratio res;
    if(denom != ratio.denom){
        denomTmp = denom;
        denom = denom * ratio.denom;
        num = num * ratio.denom;
        ratio.denom = ratio.denom * denomTmp;
        ratio.num = ratio.num * denomTmp;
    }
    res.num=num-ratio.num;
    res.denom=denom-ratio.denom;
    return res;
}

template<typename T>
Ratio Ratio::operator*(const Ratio &ratio){
    Ratio res;
    res.num=num*ratio.num;
    res.denom=denom*ratio.denom;
    return res;
}

template<typename T>
Ratio Ratio::operator/(const Ratio &ratio){
    Ratio res;
    res.num=num*ratio.denom;
    res.denom=denom*ratio.nom;
    return res;
}

template<typename T>
std::ostream& operator<< (std::ostream& stream, const Ratio &ratio){
        std::cout<< ratio.num << "/" << ratio.denom;
        return std::cout<<std::endl;
    }

*/