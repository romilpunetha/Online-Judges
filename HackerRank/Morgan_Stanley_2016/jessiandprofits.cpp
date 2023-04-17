#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

pair<ll, ll> mn(pair<ll, ll> &a, pair<ll, ll> &b) {
    if (a.second - a.first < b.second - b.first)
        return a;
    else if (a.second - a.first == b.second - b.first)
        return a.first < b.first ? a : b;
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d;
    cin >> n >> d;
    map<ll, ll> mp;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (mp.find(t) == mp.end()) mp[t] = i;
    }
    for (int i = 0; i < d; i++) {
        int t;
        cin >> t;
        pair<ll, ll> ans = { LLONG_MAX, LLONG_MAX };
        for (auto &it : mp) {
            ans = mn(ans, { it.second, mp[it.first + t] });
        }
    }
    return 0;
}
