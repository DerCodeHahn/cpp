#include <string>
#include <sstream>
#include <stdint.h>
#include <cmath>
#include "fixed_point.h"

int factorial(int n)
{
    if (n == 0)
       return 1;
    return n * factorial(n - 1);
}


template<int lhb, int rhb>
fixed_Point<lhb,rhb>::fixed_Point(type number):mQ(number){

}

template<int lhb, int rhb>
fixed_Point<lhb,rhb>::fixed_Point(float n):mQ((type)(n*pow(2,rhb)))
{

}

template<int lhb, int rhb>
fixed_Point<lhb,rhb>& fixed_Point<lhb,rhb>::operator =(fixed_Point const& rhs)
{
    if(this!= &rhs){
        mQ = rhs.getQ();
    }
    return *this;
}

template<int lhb, int rhb>
fixed_Point<lhb,rhb> fixed_Point<lhb,rhb>::operator+(fixed_Point<lhb,rhb> const rhs) const
{
    type tmp = mQ + rhs.getQ();
    fixed_Point<lhb,rhb> fp(tmp);
    return fp;
}

template<int lhb, int rhb>
fixed_Point<lhb,rhb> fixed_Point<lhb,rhb>::operator -(fixed_Point<lhb,rhb>const rhs) const
{
    type tmp = mQ - rhs.getQ();
    fixed_Point<lhb,rhb> fp(tmp);
    return fp;
}
template<int lhb, int rhb>
fixed_Point<lhb,rhb> fixed_Point<lhb,rhb>::operator *(fixed_Point<lhb,rhb>rhs) const
{
    nextType tmp = (nextType)mQ * ((nextType)rhs.mQ);
    fixed_Point<lhb,rhb> fp((type)(tmp /  pow(2,rhb)));
    return fp;
}

//fixed_Point fixed_Point::operator /(fixed_Point rhs) const
//{
//    int64_t tmp;
//    int32_t a = mQ;
//    int32_t b = rhs.getQ();
//    // pre-multiply by the base (Upscale to Q16 so that the result will be in Q8 format)
//    tmp = (int64_t)a * 0x10000;
//    // Rounding: mid values are rounded up (down for negative values).
//    if ((tmp >= 0 && b >= 0) || (tmp < 0 && b < 0))
//        tmp += b / 2;
//    else
//        tmp -= b / 2;
//    fixed_Point fp((int32_t)(tmp / b));
//    return fp;
//}
template<int lhb, int rhb>
bool fixed_Point<lhb,rhb>::operator<(fixed_Point<lhb,rhb> rhs) const
{
    return mQ < rhs.getQ();
}

template<int lhb, int rhb>
bool fixed_Point<lhb,rhb>::operator>(fixed_Point<lhb,rhb> rhs) const
{
    return mQ > rhs.getQ();
}

template<int lhb, int rhb>
bool fixed_Point<lhb,rhb>::operator==(fixed_Point<lhb,rhb> rhs) const
{
    return mQ == rhs.getQ();
}

template<int lhb, int rhb>
bool fixed_Point<lhb,rhb>::operator!=(fixed_Point<lhb,rhb> rhs) const
{
    return mQ != rhs.getQ();
}

template<int lhb, int rhb>
bool fixed_Point<lhb,rhb>::operator<=(fixed_Point<lhb,rhb> rhs) const
{
    return mQ <= rhs.getQ();
}

template<int lhb, int rhb>
bool fixed_Point<lhb,rhb>::operator>=(fixed_Point<lhb,rhb> rhs) const
{
    return mQ >= rhs.getQ();
}

template<int lhb, int rhb>
fixed_Point<lhb,rhb> fixed_Point<lhb,rhb>::operator++()
{
    fixed_Point temp = *this;
    mQ += pow(2,rhb);
    return temp;
}

template<int lhb, int rhb>
fixed_Point<lhb,rhb>& fixed_Point<lhb,rhb>::operator++(int rhs)
{
    mQ += pow(2,rhb);
    return *this;
}

template<int lhb, int rhb>
fixed_Point<lhb,rhb> fixed_Point<lhb,rhb>:: operator --()
{
    fixed_Point temp = *this;
    mQ -= pow(2,rhb);
    return temp;
}

template<int lhb, int rhb>
fixed_Point<lhb,rhb>& fixed_Point<lhb,rhb>:: operator --(int rhs)
{
    mQ -= pow(2,rhb);
    return *this;
}

template<int lhb, int rhb>
std::string fixed_Point<lhb,rhb>::toString() const
{
    float ret = (float) mQ;
    ret /= pow(2,rhb);
    std::ostringstream os ;
    os << ret;
    return os.str();
}
template<int lhb, int rhb>
type fixed_Point<lhb,rhb>::getQ() const
{
    return mQ;
}

template<int lhb, int rhb>
fixed_Point<lhb,rhb>::operator float() const{
    return ((float)mQ) /pow(2,rhb);
}

template<int lhb,int rhb>
fixed_Point<lhb,rhb>::operator int() const{
    return (int)mQ /pow(2,rhb);
}


template<const int lhb,const int rhb>
fixed_Point<lhb,rhb> abs(fixed_Point<lhb,rhb> fp){
    if(fp.mQ < 0 )
        fp.mQ =( fp.mQ^(pow(2, lhb+rhb+1)-1) ) + 1;
    return fp;
}

template<int lhb, int rhb>
fixed_Point<lhb,rhb> fixed_Point<lhb,rhb>:: operator -() const
{
    return fixed_Point(-mQ);
}

template<int lhb, int rhb>
fixed_Point<lhb,rhb> cos(fixed_Point<lhb,rhb> fp){
    fixed_point tmp(0);
    for( int i = 0; i <= 3; i++){
        int32_t tmpSi = (std::pow(-1,i)*pow(2,rhb));
        fixed_point si(tmpSi);
        fixed_point divend = pow(fp, (2*i));
        int32_t fac = factorial(2*i);
        fixed_point divsor(fac*pow(2,rhb));
        tmp = tmp + si * (divend/divsor);
    }
    return tmp;
}
template<int lhb, int rhb>
fixed_Point<lhb,rhb> sin(fixed_Point<lhb,rhb> fp)
{
    fixed_point tmp(0);
    for( int i = 0; i <= 3; i++){
        int32_t tmpSi = (std::pow(-1,i)*pow(2,rhb));
        fixed_point si(tmpSi);
        fixed_point divend = pow(fp, (2*i +1));
        int32_t fac = factorial(2*i+1);
        fixed_point divsor(fac*pow(2,rhb));
        tmp = tmp + si * (divend/divsor);
    }
    return tmp;
}

template<int lhb, int rhb>
fixed_Point<lhb,rhb> pow(fixed_Point<lhb,rhb> b, int16_t e)
{
    if(e == 0){
        fixed_point fp(pow(2,rhb));
        return fp;
    }
    fixed_point tmp = b;
    for(unsigned i = 2; i <= abs(e); i++){
        tmp = tmp * b;
    }
    if(e < 0){
        fixed_point fp(pow(2,rhb));
        return fp / tmp;
    }
    return tmp;
}
