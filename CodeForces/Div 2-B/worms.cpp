#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, t;
    cin >> n;
    vector<int> arr(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i) arr[i] += arr[i - 1];
        mp[arr[i]] = i + 1;
    }
    for (cin >> m; m--;) {
        cin >> t;
        auto it = mp.lower_bound(t);
        cout << it->second << endl;
    }
    return 0;
}
