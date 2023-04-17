#include <bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define der(c, x) ((c).find(x) != (c).end())
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define V vector
#define L list
#define P pair
#define MP map
#define ST set
#define UM unordered_map
#define MM multimap
#define UMM unordered_multimap
#define MST multiset
#define UST unordered_set
#define UMS unordered_multiset
#define PQ priority_queue
#define Pii P<int, int>
#define Pll P<long long, long long>
#define Graph V<L<int> >
#define all(a) (a).begin(), (a).end()
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
using namespace std;
template <typename A, typename B>
inline ostream& operator<<(ostream& os, const pair<A, B>& v) { return os << v.first << ' ' << v.second; }
template <typename A>
inline ostream& operator<<(ostream& os, const vector<A>& v) {
    auto it = v.begin();
    os << *it;
    for (++it; it != v.end();
         os << ' ' << *it++)
        ;
    return os;
}
void tr() { cout << endl; }
template <typename H, typename... T>
inline void tr(H head, T... tail) {
    cerr << head << ' ';
    tr(tail...);
}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<ll> x(n);
    vector<ll> y(n);
    for (int i = 1; i < n - 1; i++) {
        int a = s;
        int b = arr[i] - s;
        if (b < 0) {
            a += b;
            b = 0;
        }
        x[i] = a;
        y[i] = b;
    }

    ll dp[n][2];
    dp[1][0] = arr[0] * x[1];
    dp[1][1] = arr[0] * y[1];
    for (int i = 2; i < n - 1; i++) {
        dp[i][0] = min(dp[i - 1][0] + x[i] * y[i - 1], dp[i - 1][1] + x[i] * x[i - 1]);
        dp[i][1] = min(dp[i - 1][0] + y[i] * y[i - 1], dp[i - 1][1] + y[i] * x[i - 1]);
    }
    ll ans = min(dp[n - 2][0] + y[n - 2] * arr[n - 1], dp[n - 2][1] + x[n - 2] * arr[n - 1]);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
