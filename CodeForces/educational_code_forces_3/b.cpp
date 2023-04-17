#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    unordered_map<ll, ll> mp;
    mp.reserve(n);
    ll total = 0, res = 0;
    while (n--) {
        ll t;
        cin >> t;
        res += total - mp[t];
        mp[t]++;
        total++;
    }
    cout << res << endl;
    return 0;
}
