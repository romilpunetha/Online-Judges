#include<bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
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
int n, m;
vector<int> parent, cnt;

int find(int u){
    while(u != parent[u]){
        parent[u] = parent[parent[u]];
        u = parent[u];
    }
    return u;
}

void unions(int u, int v){
    int p = find(u), q = find(v);
    if(p == q) return;
    parent[p] = q;
    cnt[q] += cnt[p];
}


int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    parent.resize(n);
    cnt.resize(n, 0);
    for(auto &it : cnt) it = 1;
    for(int i = 0; i < n; i++) parent[i] = i;
    while(m--){
        int u, v; cin >> u >> v; u--, v--;
        unions(u, v);
    }
    for(int i = 0; i < n; i++) cout << cnt[parent[find(i)]] - 1 << " ";
    return 0;
}

