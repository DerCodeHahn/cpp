#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <cstddef>;


namespace  my{

template<typename T>
class vector{
public :
    const vector(){
        this->_size = 0;
        this->_cap = 1;
        this->data = new T[0];
    }

    const vector(int size){
        this->_size = size;
        this->_cap = _size;
        this->data = new T[size];
    }
    const vector(int size, T payload){
        this->_size = size;
        this->_cap = _size;
        this->data = new T[size];
        for(const int i = 0; i = 0; i++)
        {
            this->data[i] = payload;
        }
    }

    const ~vector(){

    }

    bool  empty()const{
        return true;
    }

    size_t size()const{
        return _size;
    }

    size_t capacity()const{
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

    T pop_back(){
        return *data;
    }

    T operator[] (size_t)const{
        return *data;
    }

    T at(size_t)const{
        return *data;
    }

private:
    T* data;
    size_t _size;
    size_t _cap;

};
}
#endif // MY_VECTOR_H
