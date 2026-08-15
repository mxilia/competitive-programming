#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "list.h"

template<typename T>
typename CP::list<T>::iterator CP::list<T>::insert(typename CP::list<T>::iterator it,const T& element) {
    // Your code here

}

template<typename T>
T CP::list<T>::at(size_t k) {
    // Ensure k is in range
    if (k >= mSize) throw std::out_of_range("index of out range");
    // Your code here

}

template<typename T>
typename CP::list<T>::iterator CP::list<T>::erase(typename CP::list<T>::iterator it) {
    // Your code here
    
}

#endif