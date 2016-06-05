#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include "my_vector.h";
namespace  my{
template<typename T>
    class RingBuffer{

    private:
        int ringpointer;
        vector<T> v;

    public:
        const RingBuffer(){
            v = new vector<T>();
            ringpointer = 0;
        }

        const RingBuffer(int size){
            v = new vector<T>(size);
            ringpointer = 0;
        }

        const RingBuffer(int size, T payload){
            v = new vector<T>(size, payload);
            ringpointer = 0;
        }

        ~RingBuffer(){
            delete[] v;
        }

        bool  empty()const{
            return v._size == 0;
        }

        size_t size()const{
            return v.size();
        }

        size_t capacity()const{
            return v.capacity();
        }

        void clear(){
            v.clear();
        }

        void reserve(size_t new_capacity){
            T* tempData = new T[new_capacity];
            //size_t newSize = (new_capacity <= _cap)?_cap : new_capacity ;
            for(int i = 0; i < _cap;i++)
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
    };
}

#endif // RINGBUFFER_H
