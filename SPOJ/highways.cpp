#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
list<pair<int,int> >*arr;
int n,m,a,b;
vector<int>dist,vis;
void dijkstra(){
    vis[a]=1;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
    pq.push({0,a});
    while(!pq.empty()){
        pair<int,int> node=pq.top();pq.pop();
        if(node.second==b) return;
        vis[node.second]=1;
        for(auto it:arr[node.second]){
            if(!vis[it.second] && dist[it.second]>dist[node.second]+it.first){
                dist[it.second]=dist[node.second]+it.first;
                pq.push({dist[it.second],it.second});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    for(cin>>test;test--;){
        cin>>n>>m>>a>>b;a--,b--;
        arr=new list<pair<int,int> >[n];
        dist=vector<int>(n,INT_MAX),vis=vector<int>(n,0);
        dist[a]=0;
        for(int i=0;i<m;i++){
            int u,v,w;cin>>u>>v>>w;u--,v--;
            arr[u].push_back({w,v});
            arr[v].push_back({w,u});
        }
        dijkstra();
        cout<<(dist[b]==INT_MAX?"NONE":to_string(dist[b]))<<endl;
        delete [] arr;
        dist.clear();
        vis.clear();
    }
    return 0;
}

