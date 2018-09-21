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
#define all(a) (a).begin(),(a).end()
#define tr1(x)                cerr << #x << ": " << x << endl;
#define tr2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
using namespace std;
template <typename A, typename B> inline ostream& operator<<(ostream&os, const pair<A, B> &v) {return os << v.first << ' ' << v.second;}
template <typename A> inline ostream& operator<<(ostream&os, const vector<A> &v){
    auto it = v.begin(); os << *it;for (++it; it != v.end(); os << ' ' << *it++); return os;
}
void tr(){cout<<endl;}
template <typename H, typename...T> inline void tr(H head, T... tail){
    cerr << head << ' ';
    tr(tail...);
}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

V<bool> visited;
V<ll>deg;
Graph g;

ll dfs(int u){
    if(visited[u]) return 0;
    visited[u] = 1;
    ll cnt = deg[u] & 1;
    for(auto v : g[u]){
        cnt += dfs(v);
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T; cin >> T; while(T--){
        int n, m; cin >> n >> m;
        g.clear(), g.resize(n + 1);
        visited.clear(), visited.resize(n + 1, 0);
        deg.clear(), deg.resize(n + 1, 0);
        for(int i = 0; i < m; i++){
            int u, v; cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
            deg[u]++, deg[v]++;
        }
        V<int> comp;
        for(int i = 1; i <= n; i++){
            if(!visited[i]) comp.pb(dfs(i));
        }
        ll ans = 0;
        for(auto &it : comp){
            if(it) ans += (it - 2) >> 1;
        }
        if(comp.size() == 1 && !comp[0]) cout << 0 << endl;
        else cout << ans + comp.size() << endl;
    }
    return 0;
}

