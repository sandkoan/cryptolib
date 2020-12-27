#include "../include/crypt.h"

/*
Returns modulo inverse of a with
respect to m using extended Euclid
Algorithm - Assumption: a and m are
coprimes, i.e., gcd(a, m) = 1
*/
long long findModInverse(long long a, long long m) {
    long long m0 = m;
    long long y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        // q is quotient
        long long q = a / m;

        long long t = m;

        // m is remainder now, process same as Euclid's algo
        m = a % m;
        a = t;
        t = y;

        // Update x and y
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}
