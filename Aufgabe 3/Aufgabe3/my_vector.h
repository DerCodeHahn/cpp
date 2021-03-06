#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <cstddef>
#include <stdexcept>
#include <string.h>

using namespace std;

namespace  my{

template<typename T>
class vector{
public :
    vector(){
        this->_size = 0;
        this->_cap = 0;
        this->data = new T[0];
    }

    vector(int size){
        this->_size = 0;
        this->_cap = size;
        this->data = new T[size];
    }
    vector(int size, T payload){
        this->_size = size;
        this->_cap = _size;
        this->data = new T[_cap];
        for(int i = 0; i = 0; i++)
        {
            this->data[i] = payload;
        }
    }
    //Copy Constr
    vector(const vector& rhs){
        this->_size = rhs.size();
        this->_cap = rhs.capacity();
        this->data = new T[_cap];
        for(int i=0; i<_cap; i++){
            this->data[i] = rhs.data[i];
        }
    }
    vector(vector&& rhs){
        this->_size = rhs.size();
        rhs._size = 0;
        this->_cap = rhs.capacity();
        rhs._cap = 0;
        this->data = rhs.data;
        rhs.data = nullptr;
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
        _size = 0;
    }

    void reserve(size_t new_capacity){
        T* tempData = new T[new_capacity];
        //size_t newSize = (new_capacity <= _cap)?_cap : new_capacity ;
        for(int i = 0; i < new_capacity;i++)
        {
            tempData[i] = data[i];
        }
        _cap = new_capacity;
        delete[] data;
        data = tempData;

    }

    void shrink_to_fit(){
        //if(_size <= )
        T* tempData = new T[_size];
        for(int i = 0; i < _size;i++)
        {
            tempData[i] = data[i];
        }
        _cap = _size;
        delete[] data;
        data = tempData;
    }

    void push_back(const T& var){
        if(_size >= _cap)
            reserve(_size + 1);
        data[_size++] = var;
    }

    T pop_back(){
        return data[--_size];
    }

    T operator[] (size_t index)const{
        return data[index];
    }
    T& operator[] (size_t index){
        return data[index];
    }
    T at(size_t index)const{
        return data[index];
    }
    T& at(size_t index){
        if(index >= _size)
            throw std::out_of_range("bla");
        return data[index];
    }

    vector& operator=(const vector& rhs){
        if(this != &rhs){
            delete[] data;
            this->_size = rhs.size();
            this->_cap = rhs.capacity();
            this->data = new T[_cap];
            for(int i=0; i<_cap; i++){
                this->data[i] = rhs.data[i];
            }
        }
        return *this;
    }

//    vector& operator =(vector&& rhs){
//        if(this != &rhs){
//            this->_size = rhs.size();
//            rhs._size = 0;
//            this->_cap = rhs.capacity();
//            rhs._cap = 0;
//            this->data = rhs.data;
//            rhs.data = nullptr;
//        }
//        return *this;
//    }

        T* data;
        size_t _size;
        size_t _cap;
    };
}
#endif // MY_VECTOR_H
