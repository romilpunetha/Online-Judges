#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n, m, k;
list<pair<ll, ll> > *g;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    ll ans = LLONG_MAX;
    unordered_set<ll> st;
    g = new list<pair<ll, ll> >[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        g[u].push_back({ l, v });
        g[v].push_back({ l, u });
    }
    while (k--) {
        int t;
        cin >> t;
        st.insert(t);
    }
    for (auto &it : st) {
        for (auto &jt : g[it]) {
            if (jt.first < ans && st.find(jt.second) == st.end()) ans = jt.first;
        }
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
    return 0;
}
