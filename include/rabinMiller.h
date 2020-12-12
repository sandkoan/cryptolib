#ifndef RABIN_MILLER_H
#define RABIN_MILLER_H

int modExpo(int base, int exponent);

bool rabinMiller(int num);

bool isPrime(int num);

long generateLargePrime(int keysize);

#endif