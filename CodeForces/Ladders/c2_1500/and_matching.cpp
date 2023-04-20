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
#define Vi V<int>
#define VVi V<V<int>>
#define Vll V<ll>
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
#define Graph V<L<int>>
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define sz size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
using namespace std;
template <typename A, typename B>
inline ostream &operator<<(ostream &os, const pair<A, B> &v) { return os << v.first << ' ' << v.second; }
template <typename A>
inline ostream &operator<<(ostream &os, const vector<A> &v) {
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

int c(int x, int n) {
    return x ^ (n - 1);
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 4 && k == n - 1) {
        cout << -1 << endl;
        return;
    }
    ST<int> skip;
    if (k > 0 && k < n - 1) {
        skip.insert(0);
        skip.insert(k);
        skip.insert(c(k, n));
        skip.insert(n - 1);
        cout << 0 << " " << c(k, n) << endl;
        cout << k << " " << n - 1 << endl;
    } else if (k == n - 1) {
        skip.insert(0);
        skip.insert(1);
        skip.insert(2);
        skip.insert(n - 1);
        skip.insert(n - 2);
        skip.insert(n - 3);
        cout << n - 1 << " " << n - 2 << endl;
        cout << n - 3 << " " << 1 << endl;
        cout << 0 << " " << 2 << endl;
    }
    for (int i = 0; i < n / 2; i++) {
        if (der(skip, i)) continue;
        cout << i << " " << c(i, n) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    // int limit = 8;
    // for (int i = 0; i < limit; i++) {
    //     for (int j = i + 1; j < limit; j++) tr3(i, j, (i & j));
    // }
    while (T--)
        solve();
    return 0;
}