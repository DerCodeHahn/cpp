#include <string>
#include <sstream>
#include <stdint.h>
#include "fixed_point.h"


template<int lhb, int rhb>
Fixed_Point<lhb,rhb>::Fixed_Point(int number):mQ((type)(number*0x1 * rhb)){

}

template<int lhb, int rhb>
Fixed_Point<lhb,rhb>::Fixed_Point(float n):mQ((type)(n*0x1*rhb))
{

}


//Fixed_Point::Fixed_Point(int32_t n):mQ(n )
//{
//}

//Fixed_Point& Fixed_Point::operator =(Fixed_Point const& rhs)
//{
//    if(this!= &rhs){
//        mQ = rhs.getQ();
//    }
//    return *this;
//}

//Fixed_Point Fixed_Point::operator +(Fixed_Point const rhs) const
//{
//    int32_t tmp = mQ + rhs.getQ();
//    Fixed_Point fp(tmp);
//    return fp;
//}

//Fixed_Point Fixed_Point::operator -(Fixed_Point rhs) const
//{
//    int32_t tmp = mQ - rhs.getQ();
//    Fixed_Point fp(tmp);
//    return fp;
//}

//Fixed_Point Fixed_Point::operator *(Fixed_Point rhs) const
//{
//    int64_t tmp = (int64_t)mQ * (int64_t)rhs.getQ();
//    Fixed_Point fp((int32_t)(tmp/0x10000));
//    return fp;
//}

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
    ret /= 0x1*rhb;
    std::ostringstream os ;
    os << ret;
    return os.str();
}

//int32_t Fixed_Point::getQ() const
//{
//    return mQ;
//}

//Fixed_Point::operator float(){
//    return (float)mQ /0x10000;
//}

////Fixed_Point::operator int(){
////    return (int)mQ /0x10000;
////}

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
