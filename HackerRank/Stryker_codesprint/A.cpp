#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, key = INT_MAX, val = INT_MAX;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        mp[t] = i;
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (abs(i - mp[t]) <= val) key = abs(i - mp[t]) < val ? t : min(key, t), val = abs(i - mp[t]);
    }
    cout << key << endl;
    return 0;
}
