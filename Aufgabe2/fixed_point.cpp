#include <string>
#include <sstream>
#include <stdint.h>
#include <cmath>
#include "fixed_point.h"

fixed_point::fixed_point(float n):mQ((int32_t)(n*0x10000))
{
}


fixed_point::fixed_point(int32_t n):mQ(n )
{
}

fixed_point fixed_point::operator -() const{
    return fixed_point(-mQ);
}

fixed_point& fixed_point::operator =(fixed_point const& rhs)
{
    if(this!= &rhs){
        mQ = rhs.getQ();
    }
    return *this;
}

fixed_point fixed_point::operator +(fixed_point const rhs) const
{
    int32_t tmp = mQ + rhs.getQ();
    fixed_point fp(tmp);
    return fp;
}

fixed_point fixed_point::operator -(fixed_point rhs) const
{
    int32_t tmp = mQ - rhs.getQ();
    fixed_point fp(tmp);
    return fp;
}

fixed_point fixed_point::operator *(fixed_point rhs) const
{
    int64_t tmp = (int64_t)mQ * (int64_t)rhs.getQ();
    fixed_point fp((int32_t)(tmp/0x10000));
    return fp;
}

fixed_point fixed_point::operator /(fixed_point rhs) const
{
    int64_t tmp;
    int32_t a = mQ;
    int32_t b = rhs.getQ();
    // pre-multiply by the base (Upscale to Q16 so that the result will be in Q8 format)
    tmp = (int64_t)a * 0x10000;
    // Rounding: mid values are rounded up (down for negative values).
    if ((tmp >= 0 && b >= 0) || (tmp < 0 && b < 0))
        tmp += b / 2;
    else
        tmp -= b / 2;
    fixed_point fp((int32_t)(tmp / b));
    return fp;
}

fixed_point& fixed_point::operator+=(fixed_point const& rhs){
    mQ = mQ + rhs.getQ();
    return  *this;
}

fixed_point& fixed_point::operator-=(fixed_point const& rhs){
    mQ =  mQ - rhs.getQ();
    return  *this;
}

fixed_point& fixed_point::operator*=(fixed_point const& rhs){
    fixed_point i(mQ);
    mQ = (i*rhs).getQ();
    return  *this;
}

fixed_point& fixed_point::operator/=(fixed_point const& rhs){
    fixed_point i(mQ);
    mQ = (i/rhs).getQ();
    return  *this;
}

bool fixed_point::operator<(fixed_point rhs) const
{
    return mQ < rhs.getQ();
}
bool fixed_point::operator>(fixed_point rhs) const
{
    return mQ > rhs.getQ();
}
bool fixed_point::operator==(fixed_point rhs) const
{
    return mQ == rhs.getQ();
}
bool fixed_point::operator!=(fixed_point rhs) const
{
    return mQ != rhs.getQ();
}
bool fixed_point::operator<=(fixed_point rhs) const
{
    return mQ <= rhs.getQ();
}
bool fixed_point::operator>=(fixed_point rhs) const
{
    return mQ >= rhs.getQ();
}

fixed_point fixed_point:: operator ++(int rhs)
{
    fixed_point temp = *this;
    mQ += 0x10000;
    return temp;
}

fixed_point& fixed_point:: operator ++()
{
    mQ += 0x10000;
    return *this;
}
fixed_point fixed_point:: operator --(int rhs)
{
    fixed_point temp = *this;
    mQ -= 0x10000;
    return temp;
}

fixed_point& fixed_point:: operator --()
{
    mQ -= 0x10000;
    return *this;
}

std::string fixed_point::toString() const
{
    float ret = (float) mQ;
    ret /= 0x10000;
    std::ostringstream os ;
    os << ret;
    return os.str();
}

int32_t fixed_point::getQ() const
{
    return mQ;
}

fixed_point::operator float() const{
    return (float)mQ /0x10000;
}

fixed_point::operator int() const{
    return (int)mQ /0x10000;
}

std::ostream& fixed_point::operator<< ( std::ostream& os )const
{
    os << float(mQ);
    return os;
}

fixed_point abs(fixed_point fp){
    if(fp.mQ < 0 )
        fp.mQ =( fp.mQ^0xFFFFFFFF ) + 1;
    return fp;
}

fixed_point pow(fixed_point b, int16_t e)
{
    if(e == 0){
        fixed_point fp(0x10000);
        return fp;
    }
    fixed_point tmp = b;
    for(unsigned i = 2; i <= abs(e); i++){
        tmp = tmp * b;
    }
    if(e < 0){
        fixed_point fp(0x10000);
        return fp / tmp;
    }
    return tmp;
}

int factorial(int n)
{
    if (n == 0)
       return 1;
    return n * factorial(n - 1);
}


fixed_point sin(fixed_point fp)
{
    fixed_point tmp(0);
    for( int i = 0; i <= 3; i++){
        int32_t tmpSi = (std::pow(-1,i)*0x10000);
        fixed_point si(tmpSi);
        fixed_point divend = pow(fp, (2*i +1));
        int32_t fac = factorial(2*i+1);
        fixed_point divsor(fac*0x10000);
        tmp = tmp + si * (divend/divsor);
    }
    return tmp;
}

fixed_point cos(fixed_point fp){
    fixed_point tmp(0);
    for( int i = 0; i <= 3; i++){
        int32_t tmpSi = (std::pow(-1,i)*0x10000);
        fixed_point si(tmpSi);
        fixed_point divend = pow(fp, (2*i));
        int32_t fac = factorial(2*i);
        fixed_point divsor(fac*0x10000);
        tmp = tmp + si * (divend/divsor);
    }
    return tmp;
}




