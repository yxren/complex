#include <iostream>
#include <complex>
#include "r_complex.h"

using namespace std;

int main() {

    u_complex<float> v1(1.1, 2.2);
    u_complex<float> v2(2.2, 3.3);
    print(std::cout, v1);
    v2.show();

    auto v3 = v1 + v2;
    v3.show();
    auto v4 = v1 - v2;
    v4.show();
    auto v5 = v1 * v2;
    v5.show();
    auto v6 = v1 / v2;
    v6.show();
    auto v7 = v1.conj();
    v7.show();
    v1 += v2;
    v1.show();
    u_complex<float> v8;
    v8.show();
    print(cout, -v8);
    auto v1_abs = v1.abs();
    cout << v1_abs << endl;

/*    complex<int> v1(1, 2);
    cout << v1 << endl;*/

    return 0;
}