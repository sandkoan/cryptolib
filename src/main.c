#include <stdio.h>
#include "../include/cryptomath.h"

int main(int argc, char **argv) {
    printf("hello world\n");

    printf("Mod Inverse of a=3 and m=11 is %lld\n", find_mod_inverse(3, 11));

    return 0;
}
