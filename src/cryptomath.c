#include "../include/crypt.h"

/*
Calculates modular inverse of a with respect to m with extended Euclidean algorithm
Assuming a and m are coprime
*/
long long findModInverse(long long a, long long m) {
    long long m0 = m;
    long long y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        long long q = a / m;

        long long t = m;

        m = a % m;
        a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}
