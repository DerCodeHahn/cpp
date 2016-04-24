#include <iostream>
#include "fixed_point.h"

using namespace std;

int main()
{
    float m = 5.0f;
    float n = 2.0f;
    Fixed_Point fp(m);
    Fixed_Point fp2(n);
    Fixed_Point res = fp + fp2;
    Fixed_Point res2 = fp - fp2;
    Fixed_Point res3 = fp * fp2;
    Fixed_Point res4 = fp / fp2;
    cout << res.toString() << " " << res2.toString() << " "
         << res3.toString() << " "  << res4.toString()<< endl;
    return 0;
}

