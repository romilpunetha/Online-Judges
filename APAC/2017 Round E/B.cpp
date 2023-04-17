#include <bits/stdc++.h>
#define tr1(x) cerr << #x << " : " << x << endl
#define tr2(x, y) cerr << #x << " : " << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z) cerr << #x << " : " << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d) cerr << #a << " : " << a << " | " << #b << " : " << b << " | " << #c << " : " << c << "  | " << #d << " : " << d << endl
#define tr5(a, b, c, d, e) cerr << #a << " : " << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << " : " << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define ff first
#define ss second
using namespace std;
typedef unsigned long long ll;
ll n;

int check(ll base, int len) {
    ll res = 1;
    ll b = base;
    for (int i = 1; i <= len; i++) {
        res += base;
        if (res == n) return 1;
        if (base > (n - res) / b && i < len) return 0;
        base *= b;
    }
    return 2;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    for (int tt = 1; tt <= test; tt++) {
        cin >> n;
        ll ans = 0;
        for (int i = 60; i > 0; i--) {
            ll lo = 2, hi = n - 1;
            while (lo < hi) {
                ll mid = lo + ((hi - lo) >> 1);
                int res = check(mid, i);
                if (res == 1) {
                    ans = mid;
                    break;
                } else if (res == 0)
                    hi = mid;
                else
                    lo = mid + 1;
            }
            if (ans) break;
            if (check(lo, i) == 1) ans = lo;
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }
    return 0;
}
