#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

unordered_set<int>ans;
list<pair<ll,pair<int,int> > >*g;
int n,m;

void dijkstras(int root){
    vector<ll>dist(n,LLONG_MAX);
    dist[root]=0;
    priority_queue<pair<ll,pair<int,int> >,greater<pair<ll,pair<int,int> > > >pq;
    pq.insert({0,{-1,root}});
    while(!pq.empty()){
        pair<ll,pair<int,int> >pp=pq.top();pq.pop();
        for(auto &it:g[pp.ss.ss]){
            if(dist[it.ss.ss]>=dist[pp.ss.ss]+it.ff){
                ans.erase(it.ss.ff);
                dist[it.ss.ss]=dist[pp.ss.ss]+it.ff;
                if(pp.ss.ff>=0)ans.insert(pp.ss.ff);
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    for(int t=1;t<=test;t++){
        ans.clear();
        cin>>n>>m;
        ans.reserve(n);
        g=new list<pair<int,pair<int,int> > >[n];
        for(int i=0;i<n;i++)parent[i]=i;
        for(int i=0;i<m;i++){
            ans.insert(i);
            int u,v,w;cin>>u>>v>>w;
            g[u].push_back({w,{i,v}});
            g[v].push_back({w,{i,u}});
        }
        for(int i=0;i<n;i++){
            dijkstras(i);
        }
        cout<<"Case #"<<t<<": "<<endl;
        for(auto &it:ans)cout<<it<<" ";cout<<endl;
    }
    return 0;
}

