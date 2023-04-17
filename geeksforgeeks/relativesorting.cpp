#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;

bool myfun(const int &a, const int &b) {
    if (mp.find(a) == mp.end() && mp.find(b) == mp.end()) return a < b;
    if (mp.find(a) != mp.end() && mp.find(b) != mp.end()) return mp[a] < mp[b];
    if (mp.find(a) != mp.end()) return true;
    return false;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        mp.clear();
        int m, n;
        cin >> m >> n;
        vector<int> arr(m);
        for (auto &it : arr) cin >> it;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            mp[t] = i + 1;
        }
        sort(arr.begin(), arr.end(), myfun);
        for (auto &it : arr) cout << it << " ";
        cout << endl;
    }
    return 0;
}
