#pragma once

#ifndef Ratio_H
#define Ratio_H

#include <iostream> 
#include <numeric> //for gcd
#include <cmath> //for floor

template<class T>
class Ratio{
    private:
        T num;
        T denom;
    public:
        Ratio(T n = 0, T d = 1): num(n), denom(d){};
        ~Ratio() = default;
    
        void display() const;
        
        inline T getNum() const { return num; };
        inline T getDenom() const { return denom; };

        inline void setNum(T n){ num = n; };
        inline void setDenom(T d){ denom = d; };

        Ratio operator=(Ratio &ratio);
        Ratio operator+(const Ratio &ratio); 
        Ratio operator-(const Ratio &ratio); 
        Ratio operator*(const Ratio &ratio); 
        Ratio operator/( Ratio &ratio); 
        Ratio operator-()const;

        void irreducible();
        Ratio absolute();
        T floor();

};

// template <class T>
// Ratio::ratio(T n, T d)
// : n(0.f), d(0.f) //mettre quel type de base ?
// {
//     num = n;
//     denom = d; 
// }

template<typename T>
void Ratio<T>::irreducible(){
    int gcd = std::gcd(denom, num);
    if(gcd > 1){
        denom = denom/gcd;
        num = num/gcd;
    }
}



template<typename T>
void Ratio<T>::display() const{
    std::cout << num << " / " << denom << std::endl;
}

template<typename T>
Ratio<T> Ratio<T>::operator=(Ratio &ratio){
    if(this != &ratio){
        ratio.setNum(ratio.num);
        ratio.setDenom(ratio.denom);
    }
    return *this;
}

/*
template<typename T>
bool Ratio<T>::operator==(Ratio &ratio){
    if(num == ratio.num && denom==ratio.denom){
        return true;
    }
    else{
        return false;
    }
}*/

template<typename T>
Ratio<T> Ratio<T>::operator+(const Ratio &ratio){
    Ratio res;
    T num2=ratio.num;
    T num1 = num;
    if(denom != ratio.denom){
        num1 = num1 * ratio.denom;
        num2 = num2 * denom;
    }
    res.num = num2 + num1;
    res.denom = denom * ratio.denom;
    res.irreducible();
    return res;
}

template<typename T>
Ratio<T> Ratio<T>::operator-(const Ratio &ratio){
    Ratio res;
    T num2=ratio.num;
    T num1=num;
    if(denom != ratio.denom){
        num1 = num1 * ratio.denom;
        num2 = ratio.num * denom;
    }
    res.num = num1 - num2;
    std::cout << "Num : " << num1 << std::endl;
    std::cout << "ratio.num : " << num2 << std::endl;
    res.denom = denom * ratio.denom;
    res.irreducible();
    return res;
}

template<typename T>
Ratio<T> Ratio<T>::operator*(const Ratio &ratio){
    Ratio res;
    res.num = num*ratio.num;
    res.denom = denom*ratio.denom;
    res.irreducible();
    return res;
}

template<typename T>
Ratio<T> Ratio<T>::operator/( Ratio &ratio){
    Ratio res;
    res.num=num*ratio.denom;
    res.denom=denom*ratio.num;
    res.irreducible();
    return res;
}

template<typename T>
Ratio<T> Ratio<T>::operator-()const{
    Ratio<T> res;
    res.denom = denom;
    res.num = -num;
    return res;
}

template<typename T>
Ratio<T> Ratio<T>::absolute(){
    Ratio<T> res;
    if(num < 0){
        res.num = -num;

    }else{
        res.num = num;
    }
    res.denom = denom;
    return res;
}

template<typename T>
T Ratio<T>::floor(){
    return std::floor(num/denom);
    //PB : floor devrait retourner -5 
    //quand res = -4,1 mais return -4
}

template<typename T>
std::ostream& operator<< (std::ostream& stream, const Ratio<T> &ratio){
        std::cout<< ratio.getNum() << "/" << ratio.getDenom();
        return std::cout<<std::endl;
}

#endif