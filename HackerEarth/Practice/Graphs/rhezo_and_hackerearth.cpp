#include<bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define der(c, x, y) ((c).find({x, y}) != (c).end())
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
#define MS multiset
#define US unordered_set
#define UMS unordered_multiset
#define PQ priority_queue
#define Graph list<int>*
#define tr1(x)                cerr << #x << ": " << x << endl;
#define tr2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

Graph g;
V<int> parent, low, disc, visited;
ST<P<int, int> > bridge;
MP<int, P<int, int> > mp;
int t = 1;

void find_bridge(int u){
    visited[u] = 1;
    disc[u] = low[u] = t++;
    for(auto &v : g[u]){
        if(!visited[v]){
            parent[v] = u;
            find_bridge(v);
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u]) bridge.insert({min(u, v), max(u, v)});
        }
        else if(v != parent[u]) low[u] = min(low[u], disc[v]);
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, m, k; cin >> n >> m;
    g = new L<int>[n + 10];
    visited.resize(n, 0), parent.resize(n, -1);
    low = disc  = visited;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        mp[i] = {min(u, v), max(u, v)};
    }
    for(int i = 1; i <= n; i++) if(!visited[i]) find_bridge(i);
    cin >> k;
    for(int i = 0; i < k; i++){
        int t; cin >> t;
        P<int, int> &p = mp[t];
        if(der(bridge, p.ff, p.ss)) cout << "Unhappy\n";
        else cout << "Happy\n";
    }
    return 0;
}


