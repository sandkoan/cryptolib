#include "../include/rabinmiller.h"

/*
 * Calculates (a * b) % c given a * b might overflow
 */
long long mod_mul(long long a, long long b, long long mod) {
    long long x = 0, y = a % mod;

    while (b > 0) {
        if (b % 2 == 1)
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
bool rabin_miller(long long num, int iter) {
    int i;
    long long s;

    if (num < 2)
        return 0;

    if (num != 2 && num % 2 == 0)
        return 0;

    s = num - 1;
    while (s % 2 == 0)
        s /= 2;

    for (i = 0; i < iter; i++) {
        long long a = rand() % (num - 1) + 1, temp = s;
        long long mod = mod_expo(a, temp, num);

        while (temp != num - 1 && mod != 1 && mod != num - 1) {
            mod = mod_mul(mod, mod, num);
            temp *= 2;
        }

        if (mod != num - 1 && temp % 2 == 0)
            return 0;
    }
    
    return 1;
}

// bool is_prime(long long num) {}

// long generate_large_prime(int keysize) {}