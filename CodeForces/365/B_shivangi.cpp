#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll int n, sum = 0, k, x;
    cin >> n >> k;
    vector<ll int> a(n, 0);
    for (ll int i = 0; i < n; i++) cin >> a[i];
    unordered_map<ll int, int> mp;
    for (ll int i = 0; i < k; i++) {
        cin >> x;
        mp[x]++;
        ll int s = 0;
        for (ll int j = 0; j < n; j++) {
            if ((x - 1) != j && mp.find(j + 1) == mp.end()) s += a[j];
        }
        sum += s * a[x - 1];
    }
    for (ll int i = 0; i < n; i++) {
        if (mp.find(i + 1) == mp.end() && mp.find((i + 2) % n) == mp.end()) {
            sum += a[i] * a[(i + 1) % n];
        }
    }
    cout << sum << endl;
    return 0;
}
