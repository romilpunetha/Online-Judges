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
#define M map
#define S set
#define UM unordered_map
#define MM multimap
#define UMM unordered_multimap
#define MS multiset
#define US unordered_set
#define UMS unordered_multiset
#define Graph list<int> *
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

Graph g;
V<int> parent, ap, low, disc, visited;
S<P<int, int> > bridge;
int t = 1;

void ap_bridge(int u) {
    visited[u] = 1;
    disc[u] = low[u] = t++;
    int children = 0;
    for (auto &v : g[u]) {
        if (!visited[v]) {
            children++;
            parent[v] = u;
            ap_bridge(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) bridge.insert({ min(u, v), max(u, v) });
            if (parent[u] == -1 && children > 1) ap[u] = 1;
            if (parent[u] != -1 && low[v] >= disc[u]) ap[u] = 1;
        } else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    g = new L<int>[n];
    visited.resize(n, 0), parent.resize(n, -1);
    ap = low = disc = visited;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 0; i < n; i++)
        if (!visited[i]) ap_bridge(i);
    int cnt = 0;
    for (auto &it : ap) cnt += it == 1;
    cout << cnt << endl;
    for (int i = 0; i < n; i++)
        if (ap[i]) cout << i << " ";
    cout << endl;
    cout << bridge.size() << endl;
    for (auto &it : bridge) cout << it.ff << " " << it.ss << endl;
    return 0;
}
