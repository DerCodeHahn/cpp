#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <cstddef>;


namespace  my{

template<typename T>
class vector{
public :
    vector(){
        this->size = 0;
        this->cap = 1;
        malloc (_size * sizeof(T));
    }

    vector(int size){
        this->size = _size;
        this->cap = _size+2;
        malloc (size * sizeof(T));
    }
    vector(int size, T first){
        this->size = _size;
        this->cap = _size+2;
        malloc (size * sizeof(T));
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
        return _capacity;
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

    void at(size_t){

    }

private:
    T* data;
    size_t _size;
    size_t _cap;

};
}
#endif // MY_VECTOR_H
