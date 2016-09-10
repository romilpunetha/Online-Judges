#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll n,m,ans=0;
vector<list<ll> >g;
vector<ll>dp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    g.resize(n+1);
    dp.resize(n+1,0);
    for(int i=0;i<m;i++){
        ll u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(auto it:g[i]){
            dp[i]=max(dp[i],dp[it]+ (it<i) );
        }
        ans=max(ans,dp[i]*(int)g[i].size());
    }
    cout<<ans<<endl;
    return 0;
}

