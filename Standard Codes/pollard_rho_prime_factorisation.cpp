ll mulmod(ll a, ll b, ll c) {
    ll x = 0, a = a % c;
    while (b) {
        if (b & 1) x = (x + y) % c;
        a = (a << 1) % c;
        b >>= 1;
    }
    return x % c;
}

ll fpow(ll x, ll n, ll mod) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = mulmod(ret, x, mod);
        x = mulmod(x, x, mod);
        n >>= 1;
    }
    return ret;
}

ll pollardrho(ll n) {
    srand(time(NULL));
    if (n == 1) return n;
    if (n % 2 == 0) return 2;
    ll x = (rand() % (n - 2)) + 2;
    ll y = x;
    ll c = (rand() % (n - 1)) + 1;
    ll d = 1;
    while (d == 1) {
        x = (fpow(x, 2, n) + c + n) % n;
        y = (fpow(y, 2, n) + c + n) % n;
        y = (fpow(y, 2, n) + c + n) % n;
        d = __gcd(abs(x - y), n);
        if (d == n) return pollardrho(n);
    }
    return d;
}
