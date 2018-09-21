
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
#define Pii P<int, int>
#define Pll P<long long, long long>
#define Graph V<L<Pii> >
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

Graph g;
PQ<Pll, V<Pll>, greater<Pll> > pq;
V<ll> dist(1e6, 1e16), hops(1e6, 1e16), pre(1e6, 0);
int n, m;

ll get_hops(int u, int d){
    if(pre[u] == -1) return hops[u];
    else if((pre[u] + d) & 1) return hops[u] + 1;
    else return hops[u];
}

void dijkstra(){
    pre[1] = -1, dist[1] = 0, hops[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        Pii u = pq.top();
        pq.pop();
        for(auto &v : g[u.ss]){
            if(dist[v.ff] > dist[u.ss] + v.ss){
                dist[v.ff] = dist[u.ss] + v.ss;
                hops[v.ff] = get_hops(u.ss, v.ss);
                pre[v.ff] = v.ss;
                pq.push({dist[v.ff], v.ff});
            }
            else if(dist[v.ff] == dist[u.ss] + v.ss){
                int thops = get_hops(u.ss, v.ss);
                if(hops[v.ff] > thops) hops[v.ff] = thops, pre[v.ff] = v.ss;
                else if(hops[v.ff] == thops){
                    if(!pre[v.ff]) pre[v.ff] = v.ss;
                    else if((pre[v.ff] + v.ss) & 1) pre[v.ff] = -1;
                }
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    g.resize(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    dijkstra();
    cout << dist[n] << " " << hops[n] << endl;
    return 0;
}

