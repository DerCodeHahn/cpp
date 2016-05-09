#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <cstddef>;


template<typename T>
class my{
public :
    my vector(T idata):
        data(idata){

    }

    ~my(T idata):
        data(idata){

    }

    bool empty(){
        ;
    }
    size_t size(){
        return size;
    }

    size_t capacity(){
        return capapcity;
    }

    void clear(){

    }

    void reserve(size_t new_capacity){

    }

    void shrink_to_fit(){

    }

    void push_back(const T&){

    }

    void popback(){

    }

    void operator[] (size_t){

    }

    void at(size_t){

    }

private:
    T* data;
    size_t size;
    size_t capapcity;

};

#endif // MY_VECTOR_H
