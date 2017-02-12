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

int n;

vector<int> parent(1e5 + 10, 0);

ll powe(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res *= a;
        a = a * a;
        res %= mod;
        a %= mod;
        b >>= 1;
    }
    return res % mod;
}

int find(int x){
    while(x != parent[x]){
        parent[x] = parent[parent[x]];
        x  = parent[x];
    }
    return x;
}

void join(int x, int y){
    int p = find(x);
    int q = find(y);
    if(p != q){
        parent[q] = p;
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) parent[i] = i;
    int q, u, v;
    cin >> q;
    while(q--){
        cin >> u >> v;
        for(int i = u, j = v; i < j; i++, j--)
            join(i, j);
    }
    unordered_set<int> st;
    for(int i = 1; i <= n; i++){
        st.insert(find(i));
    }
    cout << powe(10, st.size()) << endl;
    return 0;
}

