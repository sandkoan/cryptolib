#include "../include/rabinMiller.h"

int modExpo(int base, int exponent, int mod) {
    int res = 1;

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

bool rabinMiller(int num) {
    int s = num - 1;
    int t = 0;

    while (s % 2 == 0) {
        s = (int)(s / 2);
        t++;
    }
    for (int i = 0; i < 5; i++) {
        int a = (rand() % (num - 2)) + 2;
        int v = modExpo(a, s, num);

        if (v != 1) {
            int i = 0;
            while (v != (num - 1)) {
                if (i == t - 1)
                    return false;
                else {
                    i++;
                    v = (v * v) % num;
                }
            }
        }
    }
    return true;
}

// bool isPrime(int num) {}

// long generateLargePrime(int keysize) {}