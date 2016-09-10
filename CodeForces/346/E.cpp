#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;cin>>n>>m;
    set<pair<int,int> >s;
    map<int,int>mp;
    map<int,set<int> >adj;
    for(int i=0;i<n;i++)s.insert(make_pair(0,i+1));
    for(int i=0;i<m;i++)
    {
        int u,v;cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
        mp[u]++,mp[v]++;
        set<pair<int,int> >::iterator ui=s.find(make_pair(mp[u]-1,u)),vi=s.find(make_pair(mp[v]-1,v));
        if(ui!=s.end()) s.erase(ui);s.insert(make_pair(mp[u],u));
        if(vi!=s.end()) s.erase(vi);s.insert(make_pair(mp[v],v));
    }
    int cnt=0;
    while(!s.empty() && s.begin()->first==0) cnt++,s.erase(s.begin());
    while(!s.empty() && s.begin()->first==1)
    {
        int u=s.begin()->second;
        int v=*(adj[u].begin());
        adj[v].erase(adj[v].find(u));
        s.erase(s.begin());
        s.erase(s.find(make_pair(mp[v],v)));
        mp[v]--;
        s.insert(make_pair(mp[v],v));
        while(!s.empty() && s.begin()->first==0) cnt++,s.erase(s.begin());
    }
    cout<<cnt<<endl;
    return 0;
}

