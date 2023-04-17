#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
ll n, k;

vector<bool> sieve(1e6, 1);
vector<int> primes;

void generate() {
    sieve[0] = 0;
    sieve[1] = 0;
    for (int i = 2; i * i < 1e6; i++) {
        if (sieve[i]) {
            primes.push_back(i);
            int j = i;
            while (i * j < 1e6) {
                sieve[i * j] = 0;
                j++;
            }
        }
    }
}

ll mulmod(ll a, ll b, ll c) {
    ll x = 0;
    a = a % c;
    while (b) {
        if (b & 1) x = (x + a) % c;
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

bool isPrime(ll n) {
    if (n == 2) return 1;
    if (n < 2 || n % 2 == 0) return 0;
    ll d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        s++;
        d >>= 1;
    }
    // It's guranteed that these values will work for any number smaller than 3*10**18 (3 and 18 zeros)
    int a[9] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
    for (int i = 0; i < 9; i++) {
        bool comp = fpow(a[i], d, n) != 1;
        if (comp)
            for (int j = 0; j < s; j++) {
                ll fp = fpow(a[i], (1LL << (ll)j) * d, n);
                if (fp == n - 1) {
                    comp = false;
                    break;
                }
            }
        if (comp) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    generate();
    cin >> n >> k;
    if (k >= n) return cout << 1 << endl, 0;
    ll res = n;
    while (k--) {
        n = res;
        if (isPrime(n)) {
            res--;
            continue;
        }
        for (auto &it : primes) {
            if (n % it == 0) {
                while (n % it == 0) n /= it;
                res -= res / it;
            }
        }
        while (n > 1 && !isPrime(n)) {
            ll pfact = pollardrho(n);
            n /= pfact;
            res -= res / pfact;
        }
        if (n > 1) res -= res / n;
    }
    cout << res << endl;
    return 0;
}
