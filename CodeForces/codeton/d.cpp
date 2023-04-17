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

ll getL(ll a, ll b, ll d) {
    if (d == 1) return 1;
    return max(d - 2, 0LL) * (a - b) + a + 1;
}

ll getR(ll a, ll b, ll d) {
    return max(d - 1, 0LL) * (a - b) + a;
}

ll queryL(ll a, ll b, ll L) {
    if (a >= L) return 1;
    if ((a - b) + a >= L) return 2;
    return floor((1.0 * (L - a - 1)) / (a - b)) + 2;
}

ll queryR(ll a, ll b, ll R) {
    if (a >= R) return 1;
    return ceil((1.0 * (R - a)) / (a - b)) + 1;
}

void solve() {
    int n;
    cin >> n;
    ll L = LLONG_MIN, R = LLONG_MAX;
    while (n--) {
        ll type, a, b, d;
        cin >> type;
        if (type == 1) {
            cin >> a >> b >> d;
            ll l = getL(a, b, d);
            ll r = getR(a, b, d);
            if (l > R || r < L)
                cout << 0 << " ";
            else {
                cout << 1 << " ";
                L = max(l, L);
                R = min(r, R);
            }
        } else {
            cin >> a >> b;
            ll l = queryL(a, b, L);
            ll r = queryR(a, b, R);
            if (l == r)
                cout << l << " ";
            else
                cout << -1 << " ";
        }
    }
    cout << endl;
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
