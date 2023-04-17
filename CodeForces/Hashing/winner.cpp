#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, mx = INT_MIN, timer = 0;
    cin >> n;
    map<string, int> mp;
    map<string, map<int, int> > mp2;
    while (n--) {
        timer++;
        string s;
        int t;
        cin >> s >> t;
        mp[s] += t;
        if (mp2.find(s) == mp2.end() || mp2[s].find(mp[s]) == mp2[s].end()) mp2[s][mp[s]] = timer;
    }
    string res;
    for (auto &it : mp) mx = max(mx, it.second);
    for (auto &it : mp2) {
        timer = INT_MAX;
        for (auto jt = it.second.rbegin(); jt != it.second.rend(); jt++) {
            jt->second = min(jt->second, timer);
            timer = jt->second;
        }
    }
    timer = INT_MAX;
    for (auto it : mp2) {
        auto kt = it.second.find(mx);
        if (kt != it.second.end()) {
            if (kt->second < timer) {
                timer = kt->second;
                res = it.first;
            }
        }
    }
    cout << res << endl;
    return 0;
}
