#include<bits/stdc++.h>
#define tr1(x)                cerr << #x << ":\t" << x << endl
#define tr2(x, y)             cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z)          cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d)       cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e)    cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int n, w = 0, b = 0;
list<int> *g;
vector<int> color, visited;

void dfs(int u){
    for(auto &v : g[u]){
        if(!visited[v] && color[v] == color[u]){
            visited[v] = 1;
            dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    g = new list<int>[n];
    color = vector<int>(n);
    visited = vector<int>(n, 0);
    for(auto &it : color) cin >> it;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visited[i] = 1;
            dfs(i);
            if(color[i] == 0) b ++;
            else w ++;
        }
    }
    cout << min(b,w) << endl;
    return 0;
}

