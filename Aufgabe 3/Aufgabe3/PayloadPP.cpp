#include <iostream>
#include <cassert>
#include "my_vector.h"

using namespace std;
using my::vector;

namespace  test{
    class test32 {
    private:
        vector<int16_t> genVec(int size){
            vector<int16_t> v0;
            for(int i = 0; i<size; i++){
                v0.push_back(int16_t(i));
            }
            return v0;
        }
    public:
        int testCopy(){
            cout << "start test Copy ... ";
            cout << "operator = () ... ";
            {
                vector<int16_t> v0 = genVec(4);
                vector<int16_t> v1;
                {
                    vector<int16_t> v2 = genVec(5);
                    vector<int16_t> v3;
                    v3 = v0;
                    assert(v0.size() == v3.size());
                    v1 = v2;
                    assert(v1.size() == v2.size());
                }
                assert(!v0.empty());
                assert(!v1.empty());
            }
            cout << "vector() ... ";
            {
                vector<int16_t> v0 = genVec(4);
                {
                    vector<int16_t> v3(v0);
                    assert(v0.size() == v3.size());
                }
                assert(!v0.empty());
            }
            cout << "done." << endl;
            return 0;
        }
    };
}
