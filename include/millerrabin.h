#ifndef MILLER_RABIN_H
#define MILLER_RABIN_H

#include <stdbool.h>
#include <stdlib.h>
#include <sodium.h>


long long mod_mul(long long a, long long b, long long mod);

long long mod_expo(long long base, long long exponent, long long mod);

bool miller_rabin(long long num, int iter);

bool is_prime(long long num);

long generate_large_prime(int keysize);

#endif
