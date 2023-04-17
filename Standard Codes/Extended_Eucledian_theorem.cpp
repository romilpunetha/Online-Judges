ll g, x, y;
void extendedEuclid(ll A, ll B) {
    if (B == 0) {
        g = A;
        x = 1;
        y = 0;
    } else {
        extendedEuclid(B, A % B);
        ll temp = x;
        x = y;
        y = temp - (A / B) * y;
    }
}

ll modInverse(ll A, ll M) {
    extendedEuclid(A, M);
    return (x % M + M) % M;
}
