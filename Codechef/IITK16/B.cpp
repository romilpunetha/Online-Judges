#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
ll n,m,ans=0;
list<pair<int,int> >*g;
vector<ll>visited(n+1,0),dist(1e4+10,LLONG_MAX);

void prims(){
    dist[1]=0;
    priority_queue<pair<int,int>, vector<pair<int,int > >,greater<pair<int,int> > >pq;
    vector<bool>visited(n+1,0);
    pq.push({0,1});
    while(!pq.empty()){
        int u=pq.top().ss;
        pq.pop();
        visited[u]=1;
        for(auto &it:g[u]){
            ll v=it.ff,weight=it.ss;
            if(!visited[v] && dist[v]>weight){
                dist[v]=weight;
                pq.push({dist[v],v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    g=new list<pair<int,int> >[n+1];
    while(m--){
        int u,v,w=0,t;
        cin>>u>>v>>t;
        if(t)cin>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    prims();
    for(int i=1;i<=n;i++)ans+=dist[i];
    cout<<ans<<endl;
    return 0;
}

