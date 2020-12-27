#ifndef RABIN_MILLER_H
#define RABIN_MILLER_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


int modExpo(int base, int exponent, int mod);

bool rabinMiller(int num);

bool isPrime(int num);

long generateLargePrime(int keysize);

#endif