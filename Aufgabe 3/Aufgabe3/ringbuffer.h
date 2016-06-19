#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include "my_vector.h"

using my::vector;
namespace  my{
template<typename T>
    class RingBuffer{

    private:
        int ringpointer;
        vector<T> v;

    public:
        const RingBuffer(){
            v = vector<T>();
            ringpointer = 0;

        }

        const RingBuffer(int size){
            v = vector<T>(size);
            ringpointer = 0;
        }

//        const RingBuffer(int size, T payload){
//            v = new vector<T>(size, payload);
//            ringpointer = 0;
//        }

//        ~RingBuffer(){
//            delete v;
//        }

//        RingBuffer(const RingBuffer& rhs){
//            v = vector<T>(rhs.v);
//            ringpointer = rhs.ringpointer;
//        }
//        RingBuffer(RingBuffer&& rhs){
//            v = rhs.v;
//            rhs.data = nullptr;
//        }
        //Copy assingment
//        RingBuffer& operator=(const RingBuffer& rhs){
//            if(this != &rhs){
//                delete v;
//                v = new Vector(rhs.v);
//                ringpointer = rhs.ringpointer;
//            }
//            return *this;
//        }

        size_t size()const{
            return v.capacity();
        }

        void resize(int amount){
            if(amount > v.capacity()){
                ringpointer += v.capacity();
                reserve(amount);

            }
            else
            {
                vector<T> temp = vector<T>(amount);
                for (int i = amount; i >= 0 ; --i) {
                    temp[amount - i] = v[ringpointer - i];
                }
                ringpointer = 0;
                v = temp;
//                vector<T> temp = vector<T>();
//                int index = v.capacity() - (amount - ringpointer);
//                for (int var = index; var < index + amount; ++var) {
//                    temp.push_back( this->operator [](var));
//                }
//                ringpointer = 0;
//                cout << endl;
//                v = temp;

            }
        }

        void reserve(size_t new_capacity){
            v.reserve(new_capacity);
        }

        void shrink_to_fit(){
            v.shrink_to_fit();
        }

        void push(const T& var){
            int index = ringpointer++ % v.capacity();
            v[index] = var;
        }


        T operator[] (size_t index)const{
            size_t i = (index + ringpointer + v.capacity()) % v.capacity();
            return v[i];
        }
        T& operator[] (size_t index){
            size_t i = (index + ringpointer + v.capacity()) % v.capacity();
            return v[i];
        }
    };
}

#endif // RINGBUFFER_H
