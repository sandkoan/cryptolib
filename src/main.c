#include <stdio.h>
#include "../include/cryptomath.h"

int main(int argc, char **argv) {
    printf("hello world\n");

    printf("GCD of 4 and 4 is %d\n", gcd(4, 4));
    printf("Mod Inverse of a=3 and m=11 is %d\n", findModInverse(3, 11));

    return 0;
}
