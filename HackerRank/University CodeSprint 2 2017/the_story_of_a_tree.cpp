#include<bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define present(c,x) ((c).find(x) != (c).end())
#define present(c,x, y) ((c).find({x, y}) != (c).end())
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
set<pair<int, int> >st1;
vector<int> p12, p21;

void dfs(int root, int parent){
    st1.insert({parent, root});
    p12[root] += p12[parent];
    p21[root] += p21[parent];
    for(auto &it : g[root]){
        if(it != parent) dfs(it, root);
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int q; cin >> q; while(q--){
        int n; cin >> n;
        st1.clear(), p12.clear(), p21.clear();
        p12.resize(n + 10, 0), p21.resize(n + 10, 0);
        g = new list<int>[n + 1];
        for( int i = 1; i < n; i++ ){
            int u, v; cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(1, 0);
        int g, k, ans = 0, cnt = 0; cin >> g >> k;
        while(g--){
            int u, v; cin >> u >> v;
            if(present(st1, u, v)) cnt++, p12[v] = 1;
            else if(present(st1, v, u)) p21[u] = 1;
        }
        dfs(1, 0);
        for(int i = 1; i <= n; i++){
            int temp = cnt + p21[i] - p12[i];
            if(temp >= k) ans++;
        }
        if(ans == 0) cout << "0/1" << endl;
        else cout << ans / __gcd(ans, n) << "/" << n / __gcd(ans, n) << endl;
    }
    return 0;
}

