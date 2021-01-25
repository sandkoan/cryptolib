#include "../include/millerrabin.h"

/*
 * Calculates (a * b) % c given a * b might overflow
 */
long long mod_mul(long long a, long long b, long long mod) {
    long long x = 0, y = a % mod;

    while (b > 0) {
        if (b & 1)
            x = (x + y) % mod;

        y = (y * 2) % mod;

        b /= 2;
    }

    return x % mod;
}

/*
 * Calculates (base ^ exponent) % mod given base ^ expnent might overflow
 */
long long mod_expo(long long base, long long exponent, long long mod) {
    long long res = 1;

    base = base % mod;

    if (base == 0)
        return 0;

    while (exponent > 0) {
        if (exponent & 1)
            res = (res * base) % mod;

        exponent = exponent >> 1;
        base = (base * base) % mod;
    }

    return res;
}

/*
 * Determines whether num is prime given number of iterations
 */
bool miller_rabin(long long num, int iter) {
    if (sodium_init() < 0) {
        /* panic! the library couldn't be initialized, it is not safe to use */
    }

    int i;
    long long s;

    if (num < 2)
        return 0;

    if (num != 2 && (num & 1) == 0)
        return 0;

    s = num - 1;
    while ((s & 1) == 0)
        s /= 2;

    for (i = 0; i < iter; i++) {

        // TODO: Replace with libsodium implementation
        long long a = rand() % (num - 1) + 1, temp = s;
        long long mod = mod_expo(a, temp, num);

        while (temp != num - 1 && mod != 1 && mod != num - 1) {
            mod = mod_mul(mod, mod, num);
            temp *= 2;
        }

        if (mod != num - 1 && (temp & 1) == 0)
            return 0;
    }
    
    return 1;
}

// bool is_prime(long long num) {}

// long generate_large_prime(int keysize) {}
