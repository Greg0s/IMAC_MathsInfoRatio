#include "../include/Ratio.hpp"

void  Ratio::display() const {
    std::cout << num << " / " << denom << std::endl;
}


template<typename T>
 Ratio<T>::operator=(const Ratio &vector){
    if(this != &vector){
        m_data=vector.m_data;
    }
    return *this;
}

template<typename T>
 Ratio<T> Ratio<T>::operator+(const Ratio<T> &vector){
    Ratio res(vector.size());
    for(uint i=0; i<vector.size();i++){
            res[i]= vector.m_data[i]+m_data[i];
    }
        return res;

    }
template<typename T>
    Ratio<T> Ratio<T>::operator-(const Ratio<T> &vector){
    Ratio res(vector.size());
    for(uint i=0; i<vector.size();i++){
            res[i]= m_data[i]-vector.m_data[i];
    }
        return res;
    }
template<typename T>
    Ratio<T> Ratio<T>::operator*(const Ratio<T> &vector){
    Ratio res(vector.size());
    for(uint i=0; i<vector.size();i++){
            res[i]= m_data[i]*vector.m_data[i];
    }
        return res;
    }
template<typename T>
    Ratio<T> Ratio<T>::operator-()const{
    Ratio<T> res(this-> size());
    for(uint i=0; i<this->size();i++){
            res[i]= -m_data[i];
    }
        return res;
    }

template<typename T>
 std::ostream& operator<< (std::ostream& stream, const VectorD<T>& v){
        for(unsigned int i=0; i<v.size();i++){
            std::cout<<v[i]<<" ";
        }
    return std::cout<<std::endl;
    }
   