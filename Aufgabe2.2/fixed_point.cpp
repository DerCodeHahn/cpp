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


template<int lhb, int rhb>
fixed_Point<lhb,rhb> fixed_Point<lhb,rhb>::operator /(fixed_Point<lhb,rhb> rhs) const
{
    nextType tmp;
    nextType a = mQ;
    nextType b = rhs.getQ();
    // pre-multiply by the base (Upscale to Q16 so that the result will be in Q8 format)
    tmp = a * pow(2,rhb);
    // Rounding: mid values are rounded up (down for negative values).
    if ((tmp >= 0 && b >= 0) || (tmp < 0 && b < 0))
        tmp += b / 2;
    else
        tmp -= b / 2;
    fixed_Point<lhb,rhb> fp(type(tmp / b));
    return fp;
}

template<int lhb, int rhb>
fixed_Point<lhb,rhb>& fixed_Point<lhb,rhb>::operator +=(fixed_Point const& rhs)
{
    mQ = mQ + rhs.getQ();
    return *this;
}

template<int lhb, int rhb>
fixed_Point<lhb,rhb>& fixed_Point<lhb,rhb>::operator -=(fixed_Point const& rhs)
{
    mQ = mQ - rhs.getQ();
    return *this;
}

template<int lhb, int rhb>
fixed_Point<lhb,rhb>& fixed_Point<lhb,rhb>::operator *=(fixed_Point const& rhs)
{
    fixed_Point tmp(mQ);
    mQ =(tmp * rhs).getQ();
    return *this;
}

template<int lhb, int rhb>
fixed_Point<lhb,rhb>& fixed_Point<lhb,rhb>::operator /=(fixed_Point const& rhs)
{
    fixed_Point tmp(mQ);
    mQ =(tmp / rhs).getQ();
    return *this;
}


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
fixed_Point<lhb,rhb> fixed_Point<lhb,rhb>:: operator -() const
{
    return fixed_Point<lhb,rhb>(-mQ);
}


