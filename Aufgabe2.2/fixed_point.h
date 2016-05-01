#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <string>
#include <stdint.h>

using type = int;
using nextType = int64_t;
template<int bitsize > struct smalestType { using type = int;
                                          using nextType = int64_t;};
template<> struct smalestType<8> { using type = int8_t;
                                   using nextType = int16_t;};
template<> struct smalestType<16> { using type = int16_t;
                                    using nextType = int32_t;};
template<> struct smalestType<32> { using type = int32_t;
                                    using nextType = int64_t;};
template<> struct smalestType<64> { using type = int64_t; };


template<int lhb, int rhb>
class Fixed_Point{
public:
    //Fixed_Point(int number);
    Fixed_Point(float n);
    Fixed_Point(type n);
    Fixed_Point& operator=(Fixed_Point const& rhs);
    Fixed_Point operator+(Fixed_Point rhs) const;
    Fixed_Point operator-(Fixed_Point rhs) const;
    Fixed_Point operator*(Fixed_Point rhs) const;
//    Fixed_Point operator/(Fixed_Point rhs) const;
//    bool operator<(Fixed_Point rhs) const;
//    bool operator>(Fixed_Point rhs) const;
//    bool operator==(Fixed_Point rhs) const;
//    bool operator<=(Fixed_Point rhs) const;
//    bool operator>=(Fixed_Point rhs) const;
    std::ostream& operator<< ( std::ostream& os )const;
    explicit operator float();
//    operator int();
//    Fixed_Point operator++();
//    Fixed_Point& operator++(int rhs);
//    Fixed_Point operator--();
//    Fixed_Point& operator--(int rhs);
//    friend Fixed_Point abs(Fixed_Point fp);
    std::string toString() const;
    type getQ() const;
private:
    type mQ;
};

#endif // FIXED_POINT_H
