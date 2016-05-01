#include <string>
#include <sstream>
#include <stdint.h>
#include "fixed_point.h"


template<int lhb, int rhb>
Fixed_Point<lhb,rhb>::Fixed_Point(type number):mQ(number){

}

template<int lhb, int rhb>
Fixed_Point<lhb,rhb>::Fixed_Point(float n):mQ((type)(n*rhb))
{

}

template<int lhb, int rhb>
Fixed_Point<lhb,rhb>& Fixed_Point<lhb,rhb>::operator =(Fixed_Point const& rhs)
{
    if(this!= &rhs){
        mQ = rhs.getQ();
    }
    return *this;
}

template<int lhb, int rhb>
Fixed_Point<lhb,rhb> Fixed_Point<lhb,rhb>::operator +(Fixed_Point<lhb,rhb> const rhs) const
{
    type tmp = mQ + rhs.getQ()*rhb;
    Fixed_Point<lhb,rhb> fp(tmp);
    return fp;
}

template<int lhb, int rhb>
Fixed_Point<lhb,rhb> Fixed_Point<lhb,rhb>::operator -(Fixed_Point<lhb,rhb>const rhs) const
{
    type tmp = mQ - rhs.getQ()*rhb;
    Fixed_Point<lhb,rhb> fp(tmp);
    return fp;
}
template<int lhb, int rhb>
Fixed_Point<lhb,rhb> Fixed_Point<lhb,rhb>::operator *(Fixed_Point<lhb,rhb>rhs) const
{
    nextType tmp = ((nextType)mQ) * ((nextType)rhs.getQ())*rhb;
    Fixed_Point<lhb,rhb> fp((type)(tmp/rhb));
    return fp;
}

//Fixed_Point Fixed_Point::operator /(Fixed_Point rhs) const
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
//    Fixed_Point fp((int32_t)(tmp / b));
//    return fp;
//}

//bool Fixed_Point::operator<(Fixed_Point rhs) const
//{
//    return mQ < rhs.getQ();
//}
//bool Fixed_Point::operator>(Fixed_Point rhs) const
//{
//    return mQ > rhs.getQ();
//}
//bool Fixed_Point::operator==(Fixed_Point rhs) const
//{
//    return mQ == rhs.getQ();
//}
//bool Fixed_Point::operator<=(Fixed_Point rhs) const
//{
//    return mQ <= rhs.getQ();
//}
//bool Fixed_Point::operator>=(Fixed_Point rhs) const
//{
//    return mQ >= rhs.getQ();
//}

//Fixed_Point Fixed_Point:: operator ++()
//{
//    Fixed_Point temp = *this;
//    mQ += 0x10000;
//    return temp;
//}

//Fixed_Point& Fixed_Point:: operator ++(int rhs)
//{
//    mQ += 0x10000;
//    return *this;
//}
//Fixed_Point Fixed_Point:: operator --()
//{
//    Fixed_Point temp = *this;
//    mQ -= 0x10000;
//    return temp;
//}

//Fixed_Point& Fixed_Point:: operator --(int rhs)
//{
//    mQ -= 0x10000;
//    return *this;
//}

template<int lhb, int rhb>
std::string Fixed_Point<lhb,rhb>::toString() const
{
    float ret = (float) mQ;
    ret /= rhb;
    std::ostringstream os ;
    os << ret;
    return os.str();
}
template<int lhb, int rhb>
type Fixed_Point<lhb,rhb>::getQ() const
{
    return mQ;
}

template<int lhb, int rhb>
Fixed_Point<lhb,rhb>::operator float(){
    return ((float)mQ) /rhb;
}

//Fixed_Point::operator int(){
//    return (int)mQ /0x10000;
//}

template<int lhb, int rhb>
std::ostream& Fixed_Point<lhb,rhb>::operator<< ( std::ostream& os )const
{
    os << float(mQ);
    return os;
}

//Fixed_Point abs(Fixed_Point fp){
//    if(fp.mQ < 0 )
//        fp.mQ =( fp.mQ^0xFFFFFFFF ) + 1;
//    return fp;
//}
