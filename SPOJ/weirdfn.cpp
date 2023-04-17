#include <bits/stdc++.h>
#define tr1(x) cerr << #x << ":\t" << x << endl
#define tr2(x, y) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    while (test--) {
        ll a, b, c, n, m = 1, ans = 1, f;
        cin >> a >> b >> c >> n;
        a %= mod, b %= mod, c %= mod;
        priority_queue<ll, vector<ll> > l;
        priority_queue<ll, vector<ll>, greater<ll> > r;
        r.push(1);
        for (int i = 2; i <= n; i++) {
            f = (((a * m) % mod + (b * i) % mod) % mod + c);
            if (f >= mod) f %= mod;
            int p = l.size(), q = r.size();
            if (p > q) {
                if (f < m) {
                    r.push(l.top());
                    l.pop();
                    l.push(f);
                } else
                    r.push(f);
                m = l.top();
            } else if (p == q) {
                if (f < m) {
                    l.push(f);
                    m = l.top();
                } else {
                    r.push(f);
                    m = r.top();
                }
            } else {
                if (f < m)
                    l.push(f);
                else {
                    l.push(r.top());
                    r.pop();
                    r.push(f);
                }
                m = l.top();
            }
            m %= mod;
            ans = ans + f;
        }
        cout << ans << endl;
    }
    return 0;
}
