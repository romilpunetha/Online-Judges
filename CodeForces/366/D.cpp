#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
vector<int> x(5001), a(5001), b(5001), c(5001), d(5001), visited(5001, 0);
vector<vector<ll> > dp(5001, vector<ll>(5001, -1));

ll n, s, e, cnt = 1, ans = LLONG_MAX;

void dfs(int start, int parent, ll res) {
    whats(parent);
    whats(start);
    whats(cnt);
    if (start == e && cnt == n - 1) {
        ans = min(ans, res);
        return;
    }
    if (cnt >= n - 1 || (start == e && cnt < n - 1)) return;
    visited[start] = 1;
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        cnt++;
        dfs(i, start, res + abs(abs(x[start] - x[parent])) + min(c[parent] + b[start], d[parent] + a[start]));
        cnt--;
    }
    visited[start] = 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s >> e;
    s--, e--;
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < n; i++)
        if (i != s) dfs(i, s, abs(x[s] - x[i]) + min(c[s] + b[i], d[s] + a[i]));
    cout << ans << endl;
    return 0;
}
