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
inline ostream &operator<<(ostream &os, const pair<A, B> &v) { return os << v.first << ' ' << v.second; }
template <typename A>
inline ostream &operator<<(ostream &os, const vector<A> &v) {
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

V<int> vis;
Graph g;

void dfs(int u) {
    vis[u] = 1;
    for (auto &v : g[u]) {
        if (!vis[v]) cout << u << " " << v << endl, dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, d, k;
    cin >> n >> d >> k;
    V<int> degree(n + 100, 0);
    g.resize(n + 100);
    vis = degree;
    if (n <= d) return cout << "NO" << endl, 0;
    PQ<P<int, int>, V<P<int, int> >, greater<P<int, int> > > pq;
    for (int i = 1; i <= d; i++) g[i].pb(i + 1), g[i + 1].pb(i), degree[i + 1]++, degree[i]++;
    for (int i = 2; i <= d; i++) pq.push({ max(i - 1, d - i + 1), i });
    n -= d + 1;
    int m = d + 2;
    while (n > 0 && !pq.empty()) {
        auto t = pq.top();
        pq.pop();
        if (t.ff < d && degree[t.ss] < k) {
            degree[t.ss]++, degree[m]++;
            if (degree[m] < k) pq.push({ t.ff + 1, m });
            if (degree[t.ss] < k) pq.push({ t.ff, t.ss });
            g[m].pb(t.ss);
            g[t.ss].pb(m);
            m++, n--;
        }
    }
    for (auto &it : degree)
        if (it > k) n = -1;
    if (n != 0)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        dfs(1);
    }
    return 0;
}
