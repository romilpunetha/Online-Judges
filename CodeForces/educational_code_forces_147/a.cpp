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

typedef struct bitTree {
    Vll arr;
    int limit;

    bitTree(int n) {
        limit = n + 10;
        arr.resize(limit, 0);
    }

    void insert(int i, ll val) {
        while (i < limit) {
            arr[i] += val;
            i += i & -i;
        }
    }

    ll query(int i) {
        ll sum = 0;
        while (i) {
            sum += arr[i];
            i -= i & -i;
        }
        return sum;
    }
} bitTree;

int solve() {
    string s;
    cin >> s;
    int cnt = 0;
    bool isZero = false;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '?') {
            cnt++;
            if (i == 0) isZero = true;
        }
    }
    if (s[0] == '0') return 0;
    if (cnt == 0) return 1;
    if (isZero)
        return pow(10, cnt - 1) * 9;
    else
        return pow(10, cnt);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        cout << solve() << endl;
    return 0;
}