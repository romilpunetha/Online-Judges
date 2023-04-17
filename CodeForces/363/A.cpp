#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> n;
    cin >> s;
    set<int> st1, st2;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        s[i] == 'R' ? st1.insert(t) : st2.insert(t);
    }
    if (st1.empty() || st2.empty() || *st1.begin() > *st2.rbegin()) {
        cout << -1 << endl;
        return 0;
    }
    int ans = INT_MAX;
    for (auto &it : st1) {
        auto i = st2.upper_bound(it);
        if (i != st2.end()) ans = min(ans, abs(*i - it) / 2);
    }
    cout << ans << endl;
    return 0;
}
