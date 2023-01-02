#pragma once

#ifndef Ratio_H
#define Ratio_H

#include <iostream> 
#include <numeric> //for gcd
#include <cmath> //for floor
//#include <math.h> //for pow

template<class T>
class Ratio{
    private:
        T num;
        T denom;
    public:
        Ratio(T n = 0., T d = 1.): num(n), denom(d){this->irreducible();};
        ~Ratio() = default;
    
        void display() const;
        
        inline T getNum() const { return num; };
        inline T getDenom() const { return denom; };

        inline void setNum(T n){ num = n; };
        inline void setDenom(T d){ denom = d; };

        Ratio operator=(Ratio &ratio);
        Ratio operator+(const Ratio &ratio) const; 
        Ratio operator-(const Ratio &ratio); 
        Ratio operator*(const Ratio &ratio); 
        Ratio operator/(Ratio &ratio); 
        Ratio operator-() const;

        bool operator==(Ratio &ratio);
        bool operator!=(Ratio &ratio);
        bool operator>(Ratio &ratio);
        bool operator<(Ratio &ratio);
        bool operator>=(Ratio &ratio);
        bool operator<=(Ratio &ratio);

        void irreducible();
        Ratio toRatio() const;
        Ratio absolute();
        T floor() const;
        void commonDenom(Ratio * ratio);
        Ratio invert();

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
    int gcd = std::gcd((int) denom, (int) num);
    if(gcd > 1){
        denom = denom/gcd;
        num = num/gcd;
    }
}

// template<typename T>
// Ratio<T> Ratio<T>::toRatio() const{
//     Ratio<T> res = *this;

//     while(num / std::floor(num) != 1 && denom / std::floor(denom) != 1){
//         res.num *= 10;
//         res.denom *= 10;
//     }
//     res.irreducible();
//     return res;
// }

template<typename T>
void Ratio<T>::commonDenom(Ratio * ratio)
{//met au même dénominateur
    if(denom != ratio->denom){
        num = num * ratio->denom;
        ratio->num = ratio->num * denom;
        denom = denom * ratio->denom;
        ratio->denom = denom;
    }
}

template<typename T>
void Ratio<T>::display() const{
    std::cout << num << "/" << denom << std::endl;
}

template<typename T>
Ratio<T> Ratio<T>::operator=(Ratio &ratio){
    if(this != &ratio){
        ratio.setNum(ratio.num);
        ratio.setDenom(ratio.denom);
    }
    return *this;
}

template<typename T>
Ratio<T> Ratio<T>::operator+(const Ratio &ratio) const{
    Ratio res(num, denom);
    Ratio ratioTmp = ratio;

    res.commonDenom(&ratioTmp);
    res.num = ratioTmp.num + res.num;
    res.irreducible();
    return res;
}

template<typename T>
Ratio<T> Ratio<T>::operator-(const Ratio &ratio){
    Ratio res(num, denom);
    Ratio ratioTmp = ratio;

    res.commonDenom(&ratioTmp);
    res.num = res.num - ratioTmp.num;
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
T Ratio<T>::floor() const{
    return std::floor((double)num/denom);
}

template<typename T>
bool Ratio<T>::operator==(Ratio &ratio){
    ratio.irreducible();
    this->irreducible();
    if(num == ratio.num && denom == ratio.denom){
        return true;
    }
    return false;
}

template<typename T>
bool Ratio<T>::operator!=(Ratio &ratio){
    ratio.irreducible();
    this->irreducible();
    if(num != ratio.num || denom != ratio.denom){
        return true;
    }
    return false;
}

template<typename T>
bool Ratio<T>::operator>(Ratio &ratio){
    this->commonDenom(&ratio);

    if(num > ratio.num){
        return true;
    }
    return false;
}

template<typename T>
bool Ratio<T>::operator<(Ratio &ratio){
    this->commonDenom(&ratio);

    if(num < ratio.num){
        return true;
    }
    return false;
}

template<typename T>
bool Ratio<T>::operator<=(Ratio &ratio){
    this->commonDenom(&ratio);

    if(num <= ratio.num){
        return true;
    }
    return false;   
}

template<typename T>
bool Ratio<T>::operator>= (Ratio &ratio){
    this->commonDenom(&ratio);

    if(num >= ratio.num){
        return true;
    }
    return false;
}

template<typename T>
Ratio<T> Ratio<T>::invert(){
    Ratio res(denom, num);
    return res;
}

template<typename T>
std::ostream& operator<< (std::ostream& stream, const Ratio<T> &ratio){
        std::cout<< ratio.getNum() << "/" << ratio.getDenom();
        return std::cout<<std::endl;
}


/*
------------Pseudo code--------------
Function convert_float_to_ratio
Input: x ∈ R+ : un nombre réel à convertir en rationnel
nb_iter ∈ N : le nombre d’appels r ́ecursifs restant

 // première condition d’arrêt
 if x == 0 then return 0/1

 // seconde condition d’arrêt
 if nb iter == 0 then return 0/1

 // appel récursif si x < 1
 if x < 1 then
 return (convert_float_to_ratio(1/x, nb_iter))^-1

 // appel récursif si x > 1
 if x > 1 then
    q = [x] // partie entière
    return (q/1 + convert_float_to_ratio(x − q, nb iter − 1))

*/

template<typename T>
Ratio<T> convert_float_to_ratio(const float x, const uint nb_iter){

    if(x == 0 || nb_iter == 0){
        return 0/1;
    }

    if(x==1){
        return 1/1;
    }

    if(x < 1 && x > 0){
        Ratio<T> res = convert_float_to_ratio<T>(1/x, nb_iter);
        return res.invert();
    }

    if(x > 1 || x < 0){
        int q=floor(x); //partie entière
        //std::cout << "x : " << x << " et q : " << q << std::endl;
        Ratio<T> qRatio(q, 1);
        Ratio<T> res = convert_float_to_ratio<T>(x-q, nb_iter-1);
        //std::cout << "qRatio : " << qRatio << " et res : " << res << std::endl;
        return qRatio + res; 
    }

}

#endif