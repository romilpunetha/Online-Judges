#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

vector<set<int> >road(410),rail(410);

int n,m;

void dijkstra(vector<int>&dist1,vector<int>&dist2,vector<set<int> >&g){
    dist1[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
    pq.push({0,1});
    while(!pq.empty()){
        int u=pq.top().second;
        int w=1;
        pq.pop();
        for(auto &it:g[u]){
            if(dist1[it]==dist2[it] && dist1[it]!=INT_MAX)w=2;
            else w=1;
            if(dist1[it]>dist1[u]+w){
                dist1[it]=dist1[u]+w;
                pq.push({dist1[it],it});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            road[i].insert(j);
            road[j].insert(i);
        }
    }
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        rail[u].insert(v);
        rail[v].insert(u);
        road[u].erase(v);
        road[v].erase(u);
    }
    int ans=INT_MAX;
    vector<int>dist1(410,INT_MAX),dist2(410,INT_MAX);
    dijkstra(dist1,dist2,rail);
    dijkstra(dist2,dist1,road);
    ans=max(dist1[n],dist2[n]);
    dist1.clear();
    dist2.clear();
    dist1.resize(410,INT_MAX),dist2.resize(410,INT_MAX);
    dijkstra(dist2,dist1,road);
    dijkstra(dist1,dist2,rail);
    ans=min(ans,max(dist1[n],dist2[n]));
    if(ans==INT_MAX)ans=-1;
    cout<<ans<<endl;
    return 0;
}

