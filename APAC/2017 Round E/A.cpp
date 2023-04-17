
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

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll test;
    cin >> test;
    for (int tt = 1; tt <= test; tt++) {
        ll n = 0, ans = 0;
        ll i, j;
        string s;
        cin >> s >> i >> j;
        n = s.size();
        ll cb = 0, cr = 0;
        for (int ii = 0; ii < n; ii++) {
            cb += s[ii] == 'B';
            cr += s[ii] == 'R';
        }
        i--;
        j--;
        ll blocki = i / n;
        ll blockj = j / n;
        if (blocki == blockj) {
            i = i % n;
            j = j % n;
            for (int k = i; k <= j; k++) ans += (s[k] == 'B');
        } else {
            ll total = (blockj - blocki - 1) * cb;
            ans += total;
            i = i % n;
            for (int k = i; k <= n - 1; k++) ans += (s[k] == 'B');
            j = j % n;
            for (int k = 0; k <= j; k++) ans += (s[k] == 'B');
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }
    return 0;
}
