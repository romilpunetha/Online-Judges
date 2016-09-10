#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n;
vector<list<pair<int,ll> > >g;
vector<ll>arr;
ll ans=0;

void dfs(int root,int parent,ll dist,int flag){
    bool cnt=0;
    if(dist>arr[root] || flag) cnt=1;
    for(auto it:g[root]){
        if(it.first!=parent){
            dfs(it.first,root,max(dist+it.second,it.second),cnt);
        }
    }
    if(flag || cnt)ans++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    arr.resize(n+1);
    g.resize(n+1);
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n-1;i++){
        ll v,cost;
        cin>>v>>cost;
        g[i+1].push_back({v,cost});
        g[v].push_back({i+1,cost});
    }
    dfs(1,-1,0,0);
    cout<<ans<<endl;
    return 0;
}

