#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include "my_vector.h";

using my::vector;
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
            vector<T> v1 (size);
            v = v1;
            ringpointer = 0;
        }

//        const RingBuffer(int size, T payload){
//            v = new vector<T>(size, payload);
//            ringpointer = 0;
//        }

        ~RingBuffer(){
            v.~vector();
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

        void resize(int amount){

        }

        void reserve(size_t new_capacity){
            v.reserve(new_capacity);
        }

        void shrink_to_fit(){
            v.shrink_to_fit();
        }

        void push(const T& var){
            int index = ringpointer++ % v.size();
            v[index] = var;
        }


        T operator[] (size_t index)const{
            int i = (index + ringpointer) % v.size();
            return v[i];
        }
        T& operator[] (size_t index){
            int i = (index + ringpointer) % v.size();
            return v[i];
        }
    };
}

#endif // RINGBUFFER_H
