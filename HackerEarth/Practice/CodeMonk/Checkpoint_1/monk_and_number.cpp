#include <bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define present(c, x) ((c).find(x) != (c).end())
#define mod 1000000007
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
int n;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> n;
        unordered_map<ll, ll> mp;
        for (int i = 0; i < n; i++) {
            ll t;
            cin >> t;
            for (ll j = 2, num = t; j * j <= num; j++) {
                if (t % j == 0) {
                    tr1(j);
                    while (t % j == 0) t /= j, mp[j]++;
                }
            }
            if (t > 1) mp[t]++;
        }
        ll ans = 1;
        for (auto &it : mp) {
            ll sum = 0, pow = 1;
            for (ll i = it.ss + 1; i > 0; i--) {
                sum = (sum + (i * pow) % mod) % mod;
                pow *= it.ff;
                pow %= mod;
            }
            ans *= sum;
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}
