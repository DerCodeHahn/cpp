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
    cout << fp.toString()<<" "<<fp2.toString() <<endl;

    cout << res.toString() << " " << res2.toString() << " "
         << res3.toString() << " "  << res4.toString()<< endl<<endl;

    Fixed_Point dd(-5.5f);
    cout << "Abs "<< dd.toString() << " to "<< abs(dd).toString() << endl;


    Fixed_Point increment(2.5f);
    cout <<"Start "<< increment.toString()<<endl;
    cout <<"pre "<< (++increment).toString()<< " post "<< (increment++).toString() << endl;
    cout <<"erg "<< increment.toString()<<endl<<endl;

    Fixed_Point decrement(2.5f);
    cout <<"Start "<< decrement.toString()<<endl;
    cout <<"pre "<< (--decrement).toString()<< " post "<< (decrement--).toString() << endl;
    cout <<"erg "<< decrement.toString()<<endl;

    return 0;
}

