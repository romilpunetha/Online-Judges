#include <bits/stdc++.h>
#define tr1(x) cerr << #x << ":\t" << x << endl
#define tr2(x, y) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
using namespace std;
typedef long long ll;
ll mn = 0;
map<pair<ll, ll>, ll> dp;
ll dfs(ll n, ll prev) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (dp.find({ n, prev }) != dp.end() && prev - mn <= 2) return dp[{ n, prev }];
    ll ans = 0;
    for (int i = 0; i < 3; i++) {
        if (prev + i - mn <= 2) {
            ans += dfs(n - prev - i, prev + i);
        }
    }
    return dp[{ n, prev }] = ans;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    for (int tt = 1; tt <= test; tt++) {
        ll n, d;
        cin >> n >> d;
        ans = 0;
        dp.clear();
        for (int i = n; i > 0; i--) {
            if (i % d == 0) mn = i, ans += dfs(n - i, i);
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }
    return 0;
}
