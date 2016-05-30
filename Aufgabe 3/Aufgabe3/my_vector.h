#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <cstddef>;


namespace  my{

template<typename T>
class vector{
public :
    const vector(){
        this->_size = 0;
        this->_cap = 0;
        this->data = new T[0];
    }

    const vector(int size){
        this->_size = 0;
        this->_cap = _size;
        this->data = new T[size];
    }
    const vector(int size, T payload){
        this->_size = size;
        this->_cap = _size;
        this->data = new T[size];
        for(int i = 0; i = 0; i++)
        {
            this->data[i] = payload;
        }
    }

    ~vector(){
        delete[] data;
    }

    bool  empty()const{
        return _size == 0;
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
        //_size++;
        //data[_size] = ;
    }

    T pop_back(){
        _size--;
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
