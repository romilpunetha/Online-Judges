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

bool g[1010][1010];
int n, m, k;

vector<int>sizes, parent;

set<pair<int,int> >st;
unordered_set<int> gov;

int find(int x){
    while(x != parent[x]) x = parent[x];
    return x;
}

bool unions(int x, int y){
    int p = find(x);
    int q = find(y);
    bool r = present(gov, p);
    bool s = present(gov, q);
    if(r && s && p != q) return 0;
    if(r && s && p == q){
        sizes[p]++;
        return 1;
    }
    if(r){
        parent[q] = p;
        sizes[p] += sizes[q];
        return 1;
    }
    if(s){
        parent[p] = q;
        sizes[q] += sizes[p];
        return 1;
    }
    parent[p] = q;
    sizes[q] += sizes[p];
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    memset(g, 0, sizeof(g));
    parent.resize(n + 1);
    sizes.resize(n + 1, 1);
    for(int i = 1; i <= n; i++) parent[i] = i;
    for(int i = 0; i < k; i++){
        int t; cin >> t;
        gov.insert(t);
    }
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u][v] = g[v][u] = 1;
        u = find(u);
        v = find(v);
        if(u != v) unions(u, v);
    }
    //for(auto it : sizes) cout << it << " "; cout << endl;
    for(int i = 1; i <= n; i++){
        if(present(gov, i)) st.insert({sizes[i], i});
    }
    int ans = 0;
    int mgov = (st.rbegin())->ss;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(!g[i][j]){
                g[i][j] = g[j][i] = 1;
                int p = find(i);
                int q = find(j);
                bool r = present(gov, p);
                bool s = present(gov, q);
                if( !( (r && p != mgov) || (s && q != mgov)) ){
                    ans += unions(i, j);
                    //tr2(i, j);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

