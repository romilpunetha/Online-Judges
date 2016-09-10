#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<int,unordered_set<int> >mp;
vector<int>rep,vis;
int ans=INT_MAX;

void dfs(int src,int level,int parent,int sum=0){
    if(level>2) {ans=min(ans,sum);return;}
    for(auto it:mp[src]){
        if(!vis[it] && rep[it]>=0 && mp[it].find(parent)!=mp[it].end()){
            dfs(it,level+1,parent,sum+rep[src]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;cin>>n>>m;
    vis=vector<int>(n+1,0);
    rep=vector<int>(n+1,-2);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        rep[u]++,rep[v]++;
        mp[u].insert(v);
        mp[v].insert(u);
    }
    for(auto it:mp){
        vis[it.first]=1;
        if(rep[it.first]>=0) dfs(it.first,0,it.first);
    }
    cout<<(ans==INT_MAX?-1:ans)<<endl;
    return 0;
}

