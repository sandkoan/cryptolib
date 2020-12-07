int gcd(int a, int b) {
    while (a != 0) {
        a = b % a;
        b = a;
    }
    return b;
}


int findModInverse(int a, int m) {
    if (gcd(a, m) != 1)
        return -1;

    int u1 = 1, u2 = 0, u3 = a;
    int v1 = 0, v2 = 1, v3 = m;

    while (v3 != 0) {
        int q = (int) (u3 / v3);
        v1 = (u1 - q * v1);
        v2 = (u2 - q * v2);
        v3 = (u3 - q * v3);
        u1 = v1;
        u2 = v2;
        u3 = v3;
    }

    return u1 % m;
}
