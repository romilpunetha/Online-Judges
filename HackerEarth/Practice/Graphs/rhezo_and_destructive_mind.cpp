#include<bits/stdc++.h>
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
int n, m, q, t = 1;
V<int>cnt, cut_vertex, disc, low, visited, parent;

void get_cut_vertex(int u){
    int children = 0;
    visited[u] = 1;
    disc[u] = low[u] = t++;
    for(auto &v : g[u]){
        if(!visited[v]){
            children++;
            parent[v] = u;
            get_cut_vertex(v);
            low[u] = min(low[u], low[v]);
            if(!parent[u] && children > 1) cut_vertex[u] =1;
            if(parent[u] && low[v] >= disc[u]) cut_vertex[u] = 1;
        }
        else if(v != parent[u]) low[u] = min(low[u], disc[v]);
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    g = new L<int>[n + 1];
    cnt.resize(n + 1, 0);
    cut_vertex = visited = parent = disc = low = cnt;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        cnt[u]++, cnt[v]++;
    }
    for(int i = 1; i <= n; i++) if(!visited[i]) get_cut_vertex(i);
    cin >> q;
    while(q--){
        int t; cin >> t;
        if(cut_vertex[t]) cout << "Satisfied " << cnt[t] << endl;
        else cout << "Not Satisfied" << endl;
    }
    return 0;
}

