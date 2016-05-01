#ifndef fixed_Point_H
#define fixed_Point_H

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


template<const int lhb,const int rhb>
class fixed_Point{
public:
    //fixed_Point(int number);
    explicit fixed_Point(float n);
    explicit fixed_Point(type n);
    fixed_Point& operator=(fixed_Point const& rhs);
    fixed_Point operator+(fixed_Point rhs) const;
    fixed_Point operator-(fixed_Point rhs) const;
    fixed_Point operator*(fixed_Point rhs) const;
    fixed_Point operator/(fixed_Point rhs) const;
    bool operator<(fixed_Point rhs) const;
    bool operator>(fixed_Point rhs) const;
    bool operator==(fixed_Point rhs) const;
    bool operator<=(fixed_Point rhs) const;
    bool operator>=(fixed_Point rhs) const;
    std::ostream& operator<< (const std::ostream& os )const;
    explicit operator float();
    explicit operator int() const;
//    explicit operator int() const
//    {
//        return (float)mQ /pow(2.f,rhb);
//    }
    fixed_Point operator++();
    fixed_Point& operator++(int rhs);
    fixed_Point operator--();
    fixed_Point& operator--(int rhs);
    std::string toString() const;
    type getQ() const;
    friend fixed_Point abs(fixed_Point fp);

private:
    type mQ;
};

#endif // fixed_Point_H
