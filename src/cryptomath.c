#include "../include/crypt.h"

int gcd(int a, int b) {
    int temp;
    while (a != 0) {
        temp = a;
        a = b % a;
        b = temp;
    }
    return b;
}

/*
Returns modulo inverse of a with
respect to m using extended Euclid
Algorithm - Assumption: a and m are
coprimes, i.e., gcd(a, m) = 1
*/
int findModInverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        // q is quotient
        int q = a / m;

        int t = m;

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
