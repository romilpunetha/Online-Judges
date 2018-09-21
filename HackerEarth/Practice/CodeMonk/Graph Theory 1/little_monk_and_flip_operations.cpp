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
    auto it = v.begin(); os << *it;for (++it; it != v.end(); os << ' ' << *it++) ; return os;
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

ll n, a;
V<int>arr;
bool visited[40][100100];
Graph g;
ll ans = 0;

V<int> dfs(int u, int pos){
    if(visited[pos][u]) return {0, 0, 0};
    visited[pos][u] = 1;
    int cnt = 0;
    V<int> t(3, 0);
    for(auto &v : g[u]){
        auto p = dfs(v, pos);
        if(p[1] == 1 && !((arr[u] >> pos) & 1)) p[2] = 1;
        if(p[2] && p[1] != ((arr[u] >> pos) & 1)) cnt = max(cnt, p[0] +  1);
        else cnt = max(cnt, p[0]);
        t[2] |= p[2];
    }
    t[0] = cnt;
    t[1] = (arr[u] >> pos) & 1;
    return t;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> a;
    g.resize(n + 1);
    arr.resize(n + 1);
    memset(visited, 0, sizeof(visited));
    for(int i = 1; i < n; i++){
        ll u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 0; i < 32; i++){
        auto res = dfs(a, i);
        ans += res[0] + (res[1] | res[2]) ;
    }
    cout << ans << endl;
    return 0;
}

