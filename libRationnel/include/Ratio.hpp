#pragma once

#ifndef Ratio
#define Ratio 

//#include <iostream>

template<class T>
class Ratio{
private:
    T num;
    T denom;
public:
    ratio(/* args */);
    ~ratio();

    Ratio(T num, T denom): m_data(num, denom){
        
    };

    void display(const Ratio &ratio);

    Ratio operator=(const Ratio &ratio);
    Ratio operator+(const Ratio &ratio); 
    Ratio operator-(const Ratio &ratio); 
    Ratio operator*(const Ratio &ratio); 
    Ratio operator-()const;

};

Ratio::ratio()
:
{
}

Ratio::~ratio()
{
}

#endif