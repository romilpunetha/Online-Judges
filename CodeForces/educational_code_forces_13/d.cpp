#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll a, b, n, x, mod = 1e9 + 7;

ll pows(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> n >> x;
    ll t = pows(a, n);
    ll ans = 0;
    if (a == 1)
        ans = (x + (b * (n % mod)) % mod) % mod;
    else
        ans = ((t * x) % mod + (b * ((t - 1) * pows(a - 1, mod - 2) % mod) % mod) % mod) % mod;
    cout << ans << endl;
    return 0;
}
