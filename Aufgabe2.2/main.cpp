

#include "fixed_Point.cpp"

#include <iostream>
#include <cassert>
#include <cmath>

// -----------------------------------------------------------------------------
// advanced assert
// -----------------------------------------------------------------------------

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
}                                                     \

#define EXPECT_CLOSE( X , Y , D )                     \
{                                                     \
    auto x = X;                                       \
    auto y = Y;                                       \
    auto d = D;                                       \
    if ( abs(x-y) >= d   ) {                          \
        std::cerr << std::boolalpha                   \
        << "! assertion failed in line " << __LINE__  \
        << ": expected " << (x-y)                     \
        << " to be less than " << d << std::endl;     \
    }                                                 \
}                                                     \

template <int lhb, int rhb>
std::ostream& operator<< ( std::ostream& os , fixed_Point<lhb, rhb> const& f )
{
    os << float(f);
    return os;
}



int main()
{
    const int rhb = 10;
    const int lhb = 22;

    typedef fixed_Point<rhb, lhb> fixed_Point_def;

    const fixed_Point_def fp1( 6.375f );
    const fixed_Point_def fp2( -4.0f );

    // -------------------------------------------------------------------------
    EXPECT_EQ(  6 , int(fp1) );
    EXPECT_EQ( -4 , int(fp2) );

    EXPECT_EQ(  fp1 , abs(fp1) );
    EXPECT_EQ( -fp2 , abs(fp2) );

    // -------------------------------------------------------------------------
    // comparison and ordering
    assert( fp1 == fixed_Point_def(6.375f) );
    assert( fp2 != fp1 );
    assert( fp2 <  fp1  );
    assert( fp1 >  fp2  );
    assert( fp2 <= fp1 );
    assert( fp1 >= fp2 );

    // -------------------------------------------------------------------------
    // arithmetics
    EXPECT_EQ( fixed_Point_def( 2.375f  ) , fp1 + fp2 );
    EXPECT_EQ( fixed_Point_def( 10.375f ) , fp1 - fp2 );
    EXPECT_EQ( fixed_Point_def(-25.5f   ) , fp1 * fp2 );
    EXPECT_EQ( fixed_Point_def(-1.59375f) , fp1 / fp2 );

    // -------------------------------------------------------------------------
    // arithmetics assignment
    fixed_Point_def
    fp3 = fp1;  fp3 += fp2;     EXPECT_EQ( fixed_Point_def( 2.375f  ) , fp3 );
    fp3 = fp1;  fp3 -= fp2;     EXPECT_EQ( fixed_Point_def( 10.375f ) , fp3 );
    fp3 = fp1;  fp3 *= fp2;     EXPECT_EQ( fixed_Point_def(-25.5f   ) , fp3 );
    fp3 = fp1;  fp3 /= fp2;     EXPECT_EQ( fixed_Point_def(-1.59375f) , fp3 );

    // -------------------------------------------------------------------------
    // pre/post - increment/decrement
    fp3 = fp1;  EXPECT_EQ( fixed_Point_def(7.375f) , ++fp3 );
    fp3 = fp1;  EXPECT_EQ( fixed_Point_def(5.375f) , --fp3 );
    fp3 = fp1;  EXPECT_EQ( fixed_Point_def(6.375f) , fp3++ );  EXPECT_EQ( fixed_Point_def(7.375f) , fp3 );
    fp3 = fp1;  EXPECT_EQ( fixed_Point_def(6.375f) , fp3-- );  EXPECT_EQ( fixed_Point_def(5.375f) , fp3 );

    // -------------------------------------------------------------------------
    // trigonometric functions
    EXPECT_CLOSE( fixed_Point_def(std::sin(0.5f)) , sin(fixed_Point_def(0.5f)) , fixed_Point_def(0.01f) );
    EXPECT_CLOSE( fixed_Point_def(std::cos(0.5f)) , cos(fixed_Point_def(0.5f)) , fixed_Point_def(0.01f) );
    return 0;
}


