#include <bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define der(c, x, y) ((c).find({ x, y }) != (c).end())
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
#define Graph list<int>
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

Graph *g;
int n, m, t = 1, ans = 0, edge_count = 0;
S<P<int, int> > bridges;
V<int> parent, visited, low, disc, color;

void get_bridge(int u) {
    disc[u] = low[u] = t++;
    visited[u] = 1;
    for (auto &v : g[u]) {
        if (!visited[v]) {
            parent[v] = u;
            get_bridge(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) bridges.insert({ u, v });
        } else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}

void set_color(int u, int colour) {
    visited[u] = 1;
    for (auto &v : g[u]) {
        if (visited[v]) continue;
        if (!der(bridges, u, v) && !der(bridges, v, u)) color[v] = color[u];
        set_color(v, color[v]);
    }
}

int get_diameter(int u) {
    visited[u] = 1;
    V<int> tmp = { 0, 0 };
    for (auto &v : g[u]) {
        if (!visited[v]) {
            if (color[v] == color[u])
                tmp.pb(get_diameter(v));
            else
                tmp.pb(get_diameter(v) + 1), edge_count++;
        }
    }
    sort(all(tmp));
    reverse(all(tmp));
    ans = max(ans, tmp[0] + tmp[1]);
    return tmp[0];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    g = new Graph[n + 1];
    parent.resize(n + 1, 0);
    visited = low = disc = color = parent;
    for (int i = 0; i <= n; i++) color[i] = i;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    get_bridge(1);
    visited.clear();
    visited.resize(n + 1, 0);
    set_color(1, color[1]);
    visited.clear();
    visited.resize(n + 1, 0);
    int res = get_diameter(1);
    ans = max(ans, res);
    cout << edge_count << " " << ans << endl;
    return 0;
}
