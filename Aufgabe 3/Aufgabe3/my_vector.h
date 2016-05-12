#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <cstddef>;


namespace  my{

template<typename T>
class vector{
public :
    vector(){
        this->_size = 0;
        this->_cap = 1;
        malloc (_size * sizeof(T));
    }

    vector(int size){
        this->_size = _size;
        this->_cap = _size+2;
        malloc (size * sizeof(T));
    }
    vector(int size, T first){
        this->_size = _size;
        this->_cap = _size+2;
        malloc (_cap * sizeof(T));
        data = &first;
    }

    ~vector(){

    }

    bool empty(){
        ;
    }
    size_t size(){
        return _size;
    }

    size_t capacity(){
        return _cap;
    }

    void clear(){

    }

    void reserve(size_t new_capacity){

    }

    void shrink_to_fit(){

    }

    void push_back(const T&){

    }

    void pop_back(){

    }

    void operator[] (size_t){

    }

    bool operator= (vector){

    }

    bool operator== (vector){

    }

    void at(size_t){

    }

private:
    T* data;
    size_t _size;
    size_t _cap;

};
}
#endif // MY_VECTOR_H
