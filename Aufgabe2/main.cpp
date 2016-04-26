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
    cout << fp <<" "<<fp2 <<endl;

    cout << res << " " << res2 << " "
         << res3 << " "  << res4<< endl<<endl;

    Fixed_Point dd(-5.5f);
    cout << "Abs "<< dd << " to "<< abs(dd) << endl;


    Fixed_Point increment(2.5f);
    cout <<"Start "<< increment<<endl;
    cout <<"pre "<< (++increment)<< " post "<< (increment++) << endl;
    cout <<"erg "<< increment<<endl<<endl;

    Fixed_Point decrement(2.5f);
    cout <<"Start "<< decrement <<endl;
    cout <<"pre "<< (--decrement)<< " post "<< (decrement--) << endl;
    cout <<"erg "<< decrement<<endl;

    Fixed_Point floater(2.34f);
    float fout = (float)floater;

    cout<< floater <<" to float "<< fout << " to int "<< (int)floater <<endl;
    return 0;
}
