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
#define Graph V<L<Pii> >
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
    for (++it; it != v.end(); os << ' ' << *it++)
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

int n, m;
V<ll> arr(1e6, 0), p(1e6, 0), X(1e6, inf);
PQ<P<int, Pii>, V<P<int, Pii> > > pq;

int get(int x) {
    return x == p[x] ? x : (p[x] = get(p[x]));
}

void merge(int x, int y, int w) {
    x = get(x);
    y = get(y);
    if (x != y) {
        p[x] = y;
        if (X[y] > w) X[y] = w;
        arr[y] += arr[x];
    }
}

void solve(int u, int v) {
    while (get(u) != get(v)) {
        auto it = pq.top();
        pq.pop();
        ll W = it.ff, U = it.ss.ff, V = it.ss.ss;
        merge(U, V, W);
    }
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        ll W = it.ff, U = it.ss.ff, V = it.ss.ss;
        if (X[get(v)] > W) break;
        merge(U, V, W);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i], p[i] = i;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        pq.push({ w, { u, v } });
    }
    int u, v;
    cin >> u >> v;
    solve(u, v);
    cout << X[get(v)] << " " << arr[get(v)] << endl;
    return 0;
}
