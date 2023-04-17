#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n, x, y;
vector<ll> rows, cols;
ll ldig = 0, rdig = 0, b1, b2;

bool check() {
    ll base = rows[0];
    if (ldig != base || rdig != base) return 0;
    for (int i = 0; i < n; i++) {
        if (rows[i] != base || cols[i] != base) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    if (n == 1) return cout << 1 << endl, 0;
    rows.resize(n, 0);
    cols.resize(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll t;
            cin >> t;
            if (!t) x = i, y = j;
            if (i == j) ldig += t;
            if (j == n - i - 1) rdig += t;
            rows[i] += t;
            cols[j] += t;
        }
    }
    ll ans = rows[(x + 1) % n] - rows[x];
    if (ans <= 0) return cout << -1 << endl, 0;
    if (x == y) ldig += ans;
    if (y == n - x - 1) rdig += ans;
    cols[y] += ans;
    rows[x] += ans;
    if (check())
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
