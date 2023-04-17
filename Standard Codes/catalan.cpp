void generate_CATALAN() {
    catalan[1] = 1;
    for (int i = 2; i <= 4000; i++) {
        for (int j = 1; j <= i - 1; j++) {
            catalan[i] = (catalan[i] + ((catalan[j]) * catalan[i - j]) % mod) % mod;
        }
        catalan[i] = catalan[i] % mod;
    }
}

ull n_choose_r(ull n, ull r) {
    if (n < r)
        return 0;

    if (r > n / 2) {
        r = n - r;
    }

    ull result = 1;
    ull common_divisor;
    for (int i = 1; i <= r; ++i) {
        common_divisor = gcd(result, i);
        result /= common_divisor;
        result *= (n - i + 1) / (i / common_divisor);
    }
    return result;
}
