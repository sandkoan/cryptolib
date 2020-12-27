#ifndef RABIN_MILLER_H
#define RABIN_MILLER_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


long long mod_mul(long long a, long long b, long long mod);

long long mod_expo(long long base, long long exponent, long long mod);

bool rabin_miller(long long num, int iter);

bool is_prime(long long num);

long generate_large_prime(int keysize);

#endif