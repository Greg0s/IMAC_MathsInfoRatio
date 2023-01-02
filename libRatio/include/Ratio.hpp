#pragma once

#ifndef Ratio_H
#define Ratio_H

#include <iostream> 
#include <numeric> //for gcd
#include <cmath> //for floor

// Doxygen menu
/// \version 0.1
/// \mainpage
/// \tableofcontents
/// \section introduction_sec What for?
/// Library to use rationnals instead of floats.
/// \section install_bigsec How to install
/// \subsection dependencies_sec Dependecies
/// \li Cmake (>=3.13)
/// \li Doxygen (if you want the documentation)
/// \subsection install_sec Install with cmake (Linux / Mac)
/// \li go to main dir
/// \li mkdir build
/// \li cd build
/// \li cmake ..
/// \li make
/// \li ./bin/testRatio
/// \subsection doc_sec Create and read doc (Doxygen)
/// \li if Doxygen installed: make html
/// \li make html
/// \li The documentation is located in : 
/// /build/libRatio/doc/doc-doxygen/html/index.html


/// \class Ratio
/// \brief Class that define rationnal with linear operations
template<class T>
class Ratio{
    private:
        T num; //numerator
        T denom; //denominator
    public:
        /// \brief Constructor, can be set at use or, by default, is 0/1. Rationnal is changed to be irreducible.
        /// \param n : numerator
        /// \param d : denominator
        /// @return Ratio
        Ratio(T n = 0, T d = 1): num(n), denom(d){this->irreducible();};
        /// \brief Destructor, default
        ~Ratio() = default;
    
        /// \brief Display rationnal as n/d
        void display() const;
        
        /// \brief Get numerator
        /// @return numerator
        inline T getNum() const { return num; };
        /// \brief Get denominator
        /// @return denominator
        inline T getDenom() const { return denom; };

        /// \brief Set numerator
        /// \param n : numerator
        inline void setNum(T n){ num = n; };
        /// \brief Set denominator
        /// \param d : denominator
        inline void setDenom(T d){ denom = d; };

        /// \brief Affectation operator as ratio1 = ratio2
        /// \param ratio : rationnel
        Ratio operator=(Ratio &ratio) const;
        /// \brief Affectation operator as ratio1 = ratio2
        /// \param ratio : rationnel
        Ratio operator+(const Ratio &ratio) const; 
        Ratio operator-(const Ratio &ratio) const; 
        Ratio operator*(const Ratio &ratio); 
        Ratio operator/(Ratio &ratio) const; 
        Ratio operator-() const;

        bool operator==(Ratio &ratio);
        bool operator!=(Ratio &ratio);
        bool operator>(Ratio &ratio);
        bool operator<(Ratio &ratio);
        bool operator>=(Ratio &ratio);
        bool operator<=(Ratio &ratio);

        Ratio operator*(float &x);//ratio * float

        void irreducible();
        Ratio absolute() const;
        T floor() const;
        void commonDenom(Ratio * ratio);
        Ratio invert();

};

template<typename T>
void Ratio<T>::irreducible(){
    int gcd = std::gcd((int) denom, (int) num);
    if(gcd > 1){
        denom = denom/gcd;
        num = num/gcd;
    }
}


//met au même dénominateur
template<typename T>
void Ratio<T>::commonDenom(Ratio * ratio){
    if(denom != ratio->denom){
        num = num * ratio->denom;
        ratio->num = ratio->num * denom;
        denom = denom * ratio->denom;
        ratio->denom = denom;
    }
}

//affichage des ratios
template<typename T>
void Ratio<T>::display() const{
    std::cout << num << "/" << denom << std::endl;
}

//Surchage de l'opérateur =
template<typename T>
Ratio<T> Ratio<T>::operator=(Ratio &ratio) const{
    if(this != &ratio){
        ratio.setNum(ratio.num);
        ratio.setDenom(ratio.denom);
    }
    return *this;
}

//Surchage de l'opérateur +
template<typename T>
Ratio<T> Ratio<T>::operator+(const Ratio &ratio) const{
    Ratio res(num, denom);
    Ratio ratioTmp = ratio;

    res.commonDenom(&ratioTmp);
    res.num = ratioTmp.num + res.num;
    res.irreducible();
    return res;
}

//Surchage de l'opérateur -
template<typename T>
Ratio<T> Ratio<T>::operator-(const Ratio &ratio) const{
    Ratio res(num, denom);
    Ratio ratioTmp = ratio;

    res.commonDenom(&ratioTmp);
    res.num = res.num - ratioTmp.num;
    res.irreducible();
    return res;
}

//Surchage de l'opérateur *
template<typename T>
Ratio<T> Ratio<T>::operator*(const Ratio &ratio){
    Ratio res;
    res.num = num*ratio.num;
    res.denom = denom*ratio.denom;
    res.irreducible();
    return res;
}

//Surchage de l'opérateur /
template<typename T>
Ratio<T> Ratio<T>::operator/( Ratio &ratio) const{
    Ratio res;
    res.num=num*ratio.denom;
    res.denom=denom*ratio.num;
    res.irreducible();
    return res;
}

//surchage du moins unaire
template<typename T>
Ratio<T> Ratio<T>::operator-()const{
    Ratio<T> res;
    res.denom = denom;
    res.num = -num;
    return res;
}

//Absolu
template<typename T>
Ratio<T> Ratio<T>::absolute() const{
    Ratio<T> res;
    if(num < 0){
        res.num = -num;

    }else{
        res.num = num;
    }
    res.denom = denom;
    return res;
}

//Partie entière
template<typename T>
T Ratio<T>::floor() const{
    return std::floor((double)num/denom);
}

//Opérateurs de comparaisons
//Comparaison ==
template<typename T>
bool Ratio<T>::operator==(Ratio &ratio){
    ratio.irreducible();
    this->irreducible();
    if(num == ratio.num && denom == ratio.denom){
        return true;
    }
    return false;
}

//Comparaison !=
template<typename T>
bool Ratio<T>::operator!=(Ratio &ratio){
    ratio.irreducible();
    this->irreducible();
    if(num != ratio.num || denom != ratio.denom){
        return true;
    }
    return false;
}

//Comparaison >
template<typename T>
bool Ratio<T>::operator>(Ratio &ratio){
    this->commonDenom(&ratio);

    if(num > ratio.num){
        return true;
    }
    return false;
}

//Comparaison <
template<typename T>
bool Ratio<T>::operator<(Ratio &ratio){
    this->commonDenom(&ratio);

    if(num < ratio.num){
        return true;
    }
    return false;
}

//Comparaison <=
template<typename T>
bool Ratio<T>::operator<=(Ratio &ratio){
    this->commonDenom(&ratio);

    if(num <= ratio.num){
        return true;
    }
    return false;   
}

//Comparaison >=
template<typename T>
bool Ratio<T>::operator>= (Ratio &ratio){
    this->commonDenom(&ratio);

    if(num >= ratio.num){
        return true;
    }
    return false;
}

//Inverse du ratio
template<typename T>
Ratio<T> Ratio<T>::invert(){
    Ratio res(denom, num);
    return res;
}

//Surcharge * : float * ratio
template<typename T>
float operator*(const float &x, Ratio<T> ratio){
    float res = x * ratio.getNum() / ratio.getDenom();
    return res;    
}

//Surchage <<
template<typename T>
std::ostream& operator<< (std::ostream& stream, const Ratio<T> &ratio){
        std::cout<< ratio.getNum() << "/" << ratio.getDenom();
        return std::cout<<std::endl;
}

//Fonction convert_float_to_ratio
template<typename T>
Ratio<T> convert_float_to_ratio(const T x, const uint nb_iter){

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
        Ratio<T> qRatio(q, 1);
        Ratio<T> res = convert_float_to_ratio<T>(x-q, nb_iter-1);
        return qRatio + res; 
    }

    return 0/1;
}

//Surcharge * : ratio * float
template<typename T>
Ratio<T> operator*(Ratio<T> ratio, const float &x){
    Ratio<T> xRatio = convert_float_to_ratio<int>(x, 5);
    return ratio * xRatio;    
}


#endif