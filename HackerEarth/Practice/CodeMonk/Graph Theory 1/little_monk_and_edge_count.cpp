#include<bits/stdc++.h>
#define endl '\n'
#define inf int_max
#define pb push_back
#define present(c,x) ((c).find(x) != (c).end())
#define mod 1000000007
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define tr1(x)                cerr << #x << ": " << x << endl;
#define tr2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(),(a).end()
using namespace std;
typedef long long ll;

list<int> *g;
map<pair<int, int>, ll> mp;

ll dfs(int u, int p){
    ll t = 1;
    for(auto &v : g[u]){
        ll k = 0;
        if(v != p){
            k = dfs(v, u);
            mp[{u, v}] = k;
        }
        t += k;
    }
    return t;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, q; cin >> n >> q;
    g = new list<int>[n];
    vector<pair<int, int> >e(n);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v; u--, v--;
        e[i] = {u, v};
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0, -1);
    while(q--){
        int t; cin >> t; t--;
        int u = e[t].ff, v = e[t].ss;
        ll ans = 0, k = mp[{u, v}], l = mp[{v, u}];
        if(k) ans = (n - k) * k;
        else ans = (n - l) * l;
        cout << ans << endl;
    }
    return 0;
}
