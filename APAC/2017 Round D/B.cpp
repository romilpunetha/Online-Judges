
#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
vector<vector<ll> > st(105, vector<ll>(105, 0));
ll row, col, ans;
ll solve() {
    if (row <= 2 || col <= 2) {
        ll a = max(row, col);
        ll b = min(row, col);
        ans += (a / 3) * 2 * b;
        if (a % 3 == 1) ans += b;
        if (a % 3 == 2) ans += 2 * b;
        return ans;
    }
    ll rch = row / 3;
    ll cch = col / 3;
    ans += (rch * cch) * 6;
    if (row % 3 == 1)
        ans += cch * 2;
    else if (row % 3 == 2)
        ans += cch * 4;
    if (col % 3 == 1)
        ans += rch * 2;
    else if (col % 3 == 2)
        ans += rch * 4;
    if ((row % 3) && (col % 3)) {
        if ((row % 3) + (col % 3) == 2)
            ans += 1;
        else if ((row % 3) + (col % 3) == 3)
            ans += 2;
        else if ((row % 3) + (col % 3) == 4)
            ans += 3;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    for (int tt = 1; tt <= test; tt++) {
        ans = 0;
        cin >> row >> col;
        for (auto &it : st)
            for (auto &jt : it) jt = 0;
        cout << "Case #" << tt << ": " << solve() << endl;
    }
    return 0;
}
