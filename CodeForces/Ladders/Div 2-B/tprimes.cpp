#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> sieve(1000010, 1);
void init() {
    sieve[0] = 0;
    sieve[1] = 0;
    for (ll i = 2; i < 1000000; i++) {
        if (sieve[i]) {
            ll j = i;
            while (i * j <= 1000000) {
                sieve[i * j] = 0;
                j++;
            }
        }
    }
}

bool istprime(ll n) {
    ll i = sqrt(n);
    return (i * i == n && sieve[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    ll n;
    cin >> n;
    while (cin >> n) {
        istprime(n) ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}
