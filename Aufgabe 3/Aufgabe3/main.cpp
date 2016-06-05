// Testtreiber für Aufgabe 3
// Autor: Hartmut Schirmacher

#include <iostream>
#include <cassert>
#include "my_vector.h"
#include "ringbuffer.h"
#include <cmath>

using namespace std;
using my::vector;

class Payload {

public:
    // data
    float x, y, z;

    // constructors
    Payload(float xx=0, float yy=0, float zz=0) : x(xx), y(yy), z(zz) { count_++; }
    Payload(const Payload& rhs) : x(rhs.x), y(rhs.y), z(rhs.z) { count_++; }

    // destructor
    ~Payload()  { count_--; }

    // assignment
    Payload& operator=(const Payload& rhs) { x=rhs.x; y=rhs.y; z=rhs.z; return *this; }

    // comparison
    bool operator==(const Payload& rhs) const { return x==rhs.x && y==rhs.y && z==rhs.z; }

    // tell count
    static size_t count() { return count_; }

private:
    static size_t count_;

};

// instantiate the payload's static count
size_t Payload::count_ = 0;

#define EXPECT_EQ( X , Y )                            \
{                                                     \
    auto x = X;                                       \
    auto y = Y;                                       \
    if ( !(x == y) ) {                                \
        std::cerr << std::boolalpha                   \
        << "! assertion failed in line " << __LINE__  \
        << ": expected " << x                         \
        << ", got " << y << std::endl;                \
    }                                                 \
    else                                              \
        std::cout << "test passed:  "                 \
                  << #X " == " << #Y << std::endl;    \
}

int main()
{
    cout << "Starting tests --------------------" << endl;

    {

    {
        cout << "construction/destruction, capacity(), size() ... ";
        vector<Payload> v0;

        assert(v0.size() == 0);

        // in case the vector reserves memory, number of Payload instances it should match
        assert(Payload::count() == v0.capacity());

        {
            // are the elements created?
            vector<Payload> v1(3, Payload(-1,-1,-1));
            assert(v1.size() == 3);

            assert(v1.capacity() == 3);
            assert(Payload::count() == v0.capacity() + v1.capacity());
        }
        // are the elements destroyed?
        assert(Payload::count() == 0);
        cout << " done." << endl;
    }

    {
        cout << "push_back(), pop_back(), size(), empty() ... ";
        {

            vector<Payload> v;
            assert(v.size() == 0);
            assert(v.empty());

            v.push_back(Payload(0,0,0));
            v.push_back(Payload(1,1,1));
            v.push_back(Payload(2,2,2));
            cout << "unicorn";
            assert(v.size() >= 3);
            assert(!v.empty());
            cout << Payload::count();
            assert(Payload::count() >= 3);

            assert(v.pop_back() == Payload(2,2,2));
            assert(v.size() == 2);
            assert(Payload::count() >= 3); // should not shrink when popping

            assert(v.pop_back() == Payload(1,1,1));
            assert(v.size() == 1);
            assert(Payload::count() >= 3); // should not shrink when popping

            assert(v.pop_back() == Payload(0,0,0));
            assert(v.size() == 0);
            assert(v.empty());
            assert(Payload::count() >= 3); // should not shrink when popping

        }
        assert(Payload::count() == 0);
        cout << " done." << endl;
    }

    {
        cout << "reserve() ... ";
        {
            vector<Payload> v;
            assert(Payload::count() == 0);
            v.reserve(100);
            assert(v.capacity()==100);
            assert(Payload::count() == 100);

            v.reserve(201);
            assert(v.capacity()==201);
            assert(Payload::count() == 201); // have the 100 been freed?
        }
        cout << " done." << endl;
    }

    {
        cout << "shrink_to_fit() ... ";
        {
            // reserve 100
            vector<Payload> v;
            v.reserve(100);
            assert(v.size()==0);
            assert(v.capacity()==100);

            // push 2, still reserved for 100
            v.push_back(Payload(7,7,7));
            v.push_back(Payload(7,7,7));
            assert(v.size()==2);
            assert(Payload::count() == 100);

            // shrink from 100 to 2
            v.shrink_to_fit();

            assert(v.size()==2);
            assert(v.capacity()==2);
            assert(Payload::count() == 2);

            // border case: shrink to the same size?
            v.shrink_to_fit();
            //cout << "unicorn";
            assert(v.size()==2);
            assert(v.capacity()==2);
            assert(Payload::count() == 2);
        }
        cout << " done." << endl;
    }

    {
        cout << "operator[] ... ";
        {
            vector<Payload> v;
            v.push_back(Payload(1,2,3));
            v.push_back(Payload(7,8,9));
            assert(v.size() == 2);

            // check reading
            assert(v[0] == Payload(1,2,3));
            assert(v[1] == Payload(7,8,9));

            // check writing
            v[1] = Payload(-1,-1,-1);
            assert(v[1] == Payload(-1,-1,-1));
        }
        cout << " done." << endl;
    }

    {
        cout << "at() ... ";
        {
            vector<Payload> v;
            v.push_back(Payload(1,2,3));
            v.push_back(Payload(7,8,9));
            assert(v.size() == 2);

            // check reading
            assert(v.at(0) == Payload(1,2,3));
            assert(v.at(1) == Payload(7,8,9));

            // check writing
            v.at(1) = Payload(-1,-1,-1);
            assert(v.at(1) == Payload(-1,-1,-1));

            // check exception
            try {
                v.at(2) = Payload(0,0,0);
                assert(!"should have thrown exception");
            } catch(std::out_of_range ex) {
                cout << "exception: " << ex.what();
            }
        }
        cout << " done." << endl;
    }

    {
        cout << "constness... ";
        {
            vector<Payload> v;
            v.push_back(Payload(1,2,3));
            v.push_back(Payload(7,8,9));

            // const ref (read-only ref)
            const vector<Payload> &vconst = v;

            // all this must compile without problems, else you are missing const :-)
            assert(!vconst.empty());
            assert(vconst.size() == 2);
            assert(vconst.capacity() >= 2);
            assert(vconst[0] == Payload(1,2,3));
            assert(vconst.at(0) == Payload(1,2,3));
        }
        cout << " done." << endl;
    }

#if 0
    {
        // mal ausprobieren - soll vorerst nicht (!) kompilieren
        vector<Payload> v1;
        vector<Payload> v2 = v2;
    }
#endif
    }
    cout << "RingBuffer tests --------------------" << endl;
    {
        RingBuffer<int> ring(5);

        EXPECT_EQ( 5 , ring.size() );

        ring.push(1337);
        ring.push(  42);
        ring.push( 042);
        ring.push(9876);
        ring.push(1234);

        EXPECT_EQ( 5 , ring.size() );

        EXPECT_EQ( 1337 , ring[0]  );
        EXPECT_EQ(   42 , ring[1]  );
        EXPECT_EQ(  042 , ring[2]  );
        EXPECT_EQ(  042 , ring[-3] );
        EXPECT_EQ( 9876 , ring[-2] );
        EXPECT_EQ( 1234 , ring[-1] );


        auto ring2 = ring;

        ring2.push(10101);

        EXPECT_EQ( 1337 , ring[0]  );
        EXPECT_EQ(   42 , ring[1]  );
        EXPECT_EQ(  042 , ring[2]  );

        auto const & cring2 = ring2;

        EXPECT_EQ(   42 , cring2[0]  );
        EXPECT_EQ(  042 , cring2[1]  );
        EXPECT_EQ( 9876 , cring2[2]  );
        EXPECT_EQ( 9876 , cring2[-3] );
        EXPECT_EQ( 1234 , cring2[-2] );
        EXPECT_EQ(10101 , cring2[-1] );

        std::cout << " ---- " << std::endl;

        ring.resize(3);
        EXPECT_EQ( 3 , ring.size() );

        EXPECT_EQ(  042 , ring[0]  );
        EXPECT_EQ( 9876 , ring[1]  );
        EXPECT_EQ( 1234 , ring[2]  );
        EXPECT_EQ(  042 , ring[-3] );
        EXPECT_EQ( 9876 , ring[-2] );
        EXPECT_EQ( 1234 , ring[-1] );

        ring.resize(17);
        EXPECT_EQ( 17 , ring.size() );

        EXPECT_EQ(  042 , ring[-3] );
        EXPECT_EQ( 9876 , ring[-2] );
        EXPECT_EQ( 1234 , ring[-1] );
    }
    cout << "End of tests --------------------" << endl;

    return 0;
}
