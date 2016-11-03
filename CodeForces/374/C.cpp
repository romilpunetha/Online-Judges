#include<bits/stdc++.h>
#define tr1(x)                cerr << #x << ":\t" << x << endl
#define tr2(x, y)             cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z)          cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d)       cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e)    cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int n, m, t,inf = 1e9+7;
list<pair<int,int> >*g;
vector<vector<int> >parent, dp;
vector<bool>visited;

void dfs(int u){
    visited[u] = 1;
    for(auto &it : g[u]){
        ll v = it.ff, w = it.ss;
        if(!visited[v]) dfs(v);
        for(int i = 1; i <= n; i++){
            if(dp[v][i-1] + w < dp[u][i]){
                dp[u][i] = dp[v][i-1] + w;
                parent[u][i] = v;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m>>t;
    g=new list<pair<int,int> >[n+1];
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    parent.resize(n+2,vector<int>(n+2));
    dp.resize(n+2,vector<int>(n+2,inf));
    visited.resize(n+2,0);
    dp[n][0]=0;
    parent[n][0]=n;
    dfs(1);
    int i = n,curr=1;
    for(; i >= 0; i--) if(dp[1][i] <= t) break;
    cout<< i+1 <<endl;
    while(curr != n){
        cout<< curr <<" ";
        curr=parent[curr][i--];
    }
    cout<< n <<endl;
    return 0;
}

