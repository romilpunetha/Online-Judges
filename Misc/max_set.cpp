#include<bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define present(c, x) ((c).find(x) != (c).end())
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define mp make_pair
#define V vector
#define L list
#define P pair
#define M map
#define S set
#define UM unordered_map
#define US unordered_set
#define Graph map<int, int> *
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
UM<int, US<int>> mp1;
S<V<V<int> > >res;
V<int>tmp, visited;
V<V<int> >ans;
S<int> neg;

void dfs(int u){
    tmp.pb(u);
    visited[u] = 1;
    for(auto &v : g[u]){
        if(!visited[v.ff] && v.ss >= 0 && !present(neg, v.ff)){
            for(auto &it : mp1[v.ff]) neg.insert(it);
            dfs(v.ff);
        }
    }
}

void util(int i){
    neg.clear();
    for(auto &it : mp1[i]) neg.insert(it);
    if(!visited[i]) dfs(i);
    sort(all(tmp));
    if(!tmp.empty()) ans.pb(tmp);
    tmp.clear();
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, m; cin >> n >> m; // n = no of nodes, m = no. of edges
    g = new M<int, int>[n + 1];
    while(m--){  // taking all edges from u to v with cost w as input
        int u, v, w; cin >> u >> v >> w;
        if( !g[u][v] || w < g[u][v] ) g[u][v] = w, g[v][u] = w; // creating graph
        if(w < 0) mp1[u].insert(v), mp1[v].insert(u); // keeping track of -ve edges
    }
    for(int i = 1; i <= n; i++){
        visited.clear(); visited.resize(n + 1, 0);
        util(i); // running dfs from root node to get the main branch
        for(auto j = 1; j <= n; j++) util(j); // running dfs from remaining nodes to get the leftover sets
        res.insert(ans); ans.clear();
    }
    for(auto &it : res){
        for(auto &jt : it){
            for(auto &kt : jt) cout << kt << " "; cout << "    ";
        }
        cout << endl;
    }
    return 0;
}

