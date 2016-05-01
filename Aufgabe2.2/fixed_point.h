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
    fixed_Point operator -() const;
    fixed_Point& operator=(fixed_Point const& rhs);
    fixed_Point operator+(fixed_Point rhs) const;
    fixed_Point operator-(fixed_Point rhs) const;
    fixed_Point operator*(fixed_Point rhs) const;
    fixed_Point operator/(fixed_Point rhs) const;
    fixed_Point& operator+=(fixed_Point const& rhs);
    fixed_Point& operator-=(fixed_Point const& rhs);
    fixed_Point& operator*=(fixed_Point const& rhs);
    fixed_Point& operator/=(fixed_Point const& rhs);
    bool operator<(fixed_Point rhs) const;
    bool operator>(fixed_Point rhs) const;
    bool operator==(fixed_Point rhs) const;
    bool operator!=(fixed_Point rhs) const;
    bool operator<=(fixed_Point rhs) const;
    bool operator>=(fixed_Point rhs) const;
    std::ostream& operator<< (const std::ostream& os )const;
    explicit operator float() const;
    explicit operator int() const;
    fixed_Point operator++();
    fixed_Point& operator++(int rhs);
    fixed_Point operator--();
    fixed_Point& operator--(int rhs);
    std::string toString() const;
    type getQ() const;
    friend fixed_Point abs(fixed_Point<lhb,rhb> fp){
        if(fp.mQ < 0 )
            fp.mQ =( fp.mQ^(type)(pow(2, lhb+rhb+1)-1) ) + 1;
        return fp;
    };
    friend fixed_Point sin(fixed_Point<lhb,rhb> fp)
    {
        fixed_Point<lhb,rhb> tmp(0);
        for( int i = 0; i <= 3; i++){
            type tmpSi = (std::pow(-1,i)*pow(2,rhb));
            fixed_Point<lhb,rhb> si(tmpSi);
            fixed_Point<lhb,rhb> divend = pow(fp, (2*i +1));
            type fac = factorial(2*i+1);
            fixed_Point<lhb,rhb> divsor(fac*(type)pow(2,rhb));
            tmp = tmp + si * (divend/divsor);
        }
        return tmp;
    }
    friend fixed_Point cos(fixed_Point<lhb,rhb> fp){
        fixed_Point<lhb,rhb> tmp(0);
        for( int i = 0; i <= 3; i++){
            type tmpSi = (std::pow(-1,i)*pow(2,rhb));
            fixed_Point<lhb,rhb> si(tmpSi);
            fixed_Point<lhb,rhb> divend = pow(fp, (2*i));
            type fac = factorial(2*i);
            fixed_Point<lhb,rhb> divsor(fac*(type)pow(2,rhb));
            tmp = tmp + si * (divend/divsor);
        }
        return tmp;
    }
    friend fixed_Point pow(fixed_Point<lhb,rhb> b, int16_t e)
    {
        if(e == 0){
            fixed_Point<lhb,rhb> fp((float)pow(2,rhb));
            return fp;
        }
        fixed_Point<lhb,rhb> tmp = b;
        for(unsigned i = 2; i <= abs(e); i++){
            tmp = tmp * b;
        }
        if(e < 0){
            fixed_Point<lhb,rhb> fp((float)pow(2,rhb));
            return fp / tmp;
        }
        return tmp;
    }
;
    friend int factorial(int n);
private:
    type mQ;
};

#endif // fixed_Point_H
