#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
list<int > *g;
vector<int>dist;

void dijkstra(){
    priority_queue<pair<int,int>,vector<pair<int,int> > >q;
    dist[0]=0;
    q.push({0,0});
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        for(auto &it:g[u]){
            if(dist[it] > dist[u]+1)
            {
                dist[it] = dist[u]+1;
                q.push({dist[it],it});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    g=new list<int>[n];
    dist.resize(n,INT_MAX);
    for(int i=0;i<n;i++){
        int t;cin>>t;t--;
        g[i].push_back(t);
        if(i+1<n)g[i].push_back(i+1);
        if(i+1<n) g[i+1].push_back(i);
    }
    dijkstra();
    for(auto &it:dist)cout<<it<<" ";cout<<endl;
    return 0;
}

