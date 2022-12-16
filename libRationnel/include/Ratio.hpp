#pragma once

#ifndef Ratio_H
#define Ratio_H

#include <iostream>

template<class T>
class Ratio{
    private:
        T num;
        T denom;
    public:
        Ratio(T n = 0, T d = 0): num(n), denom(d){
        
    };
        ~Ratio();
    
        void display() const;

        // Ratio operator=(const Ratio &ratio);
        // Ratio operator+(const Ratio &ratio); 
        // Ratio operator-(const Ratio &ratio); 
        // Ratio operator*(const Ratio &ratio); 
        // Ratio operator-()const;

void display();

};

// template <class T>
// Ratio::ratio(T n, T d)
// : n(0.f), d(0.f) //mettre quel type de base ?
// {
//     num = n;
//     denom = d; 
// }

#endif