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

pair<ll, ll> operator+(pair<ll, ll> &a, pair<ll, ll>&b){
    pair<ll, ll> c = {a.ff + b.ff, a.ss + b.ss};
    return c;
}

vector<pair<ll, ll> > size(2e6 + 10);
vector<ll> parent(2e6 + 10);
vector<bool> visited(2e6 + 10, 0);

int find(int x){
    while(x != parent[x]){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void merge(int u, int v){
    int p = find(u), q = find(v);
    if(p != q){
        parent[p] = q;
        size[q] = size[q] + size[p];
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int x, y, q1, q2, q3, u, v ; cin >> x >> y;
    for(int i = 1; i <= x + y; i++){
        if(i <= x) size[i] = {1, 0};
        else size[i] = {0, 1};
        parent[i] = i;
    }
    cin >> q1; while(q1--){
        cin >> u >> v;
        merge(u, v);
    }
    cin >> q2; while(q2--){
        cin >> u >> v;
        merge(x + u, x + v);
    }
    cin >> q3; while(q3--){
        cin >> u >> v;
        merge(u, x + v);
    }
    ll ans = 0;
    for(int i = 1; i <= x + y; i++){
        int t = find(i);
        if(!visited[t]){
            visited[t] = 1;
            ans += size[t].ff * (y - size[t].ss);
        }
    }
    cout << ans << endl;
    return 0;
}

