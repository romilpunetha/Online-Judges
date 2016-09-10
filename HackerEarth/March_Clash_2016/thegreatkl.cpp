#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<list<int> > graph;


int main()
{
    ll n,m;
    cin>>n>>m;
    graph g(n+1);
    vector<int> visited(n+1,0);
    vector<int> cupid(n+1,0);
    vector<int> ma(m+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>cupid[i];
        ma[cupid[i]]=i;
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    return 0;
}
