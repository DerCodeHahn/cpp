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

    std::size_T empty(){
        ;
    }
    std::size_T size(){
        ;
    }
    std::size_T capacity(){
        ;
    }

    void clear(){

    }

    void reserve(size_T new_capacity){

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
    T data;
};

#endif // MY_VECTOR_H
