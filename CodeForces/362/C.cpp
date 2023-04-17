#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

map<pair<ll, ll>, ll> mp;

ll lca(ll a, ll b) {
    while (a != b) {
        if (a < b) swap(a, b);
        a /= 2;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--) {
        int type;
        cin >> type;
        if (type == 1) {
            ll u, v, w;
            cin >> u >> v >> w;
            ll common = lca(u, v);
            while (u != common) {
                mp[{ u >> 1, u }] += w;
                u >>= 1;
            }
            while (v != common) {
                mp[{ v >> 1, v }] += w;
                v >>= 1;
            }
        } else {
            ll cost = 0, u, v, common;
            cin >> u >> v;
            common = lca(u, v);
            while (u != common) {
                cost += mp[{ u >> 1, u }];
                u >>= 1;
            }
            while (v != common) {
                cost += mp[{ v >> 1, v }];
                v >>= 1;
            }
            cout << cost << endl;
        }
    }
    return 0;
}
