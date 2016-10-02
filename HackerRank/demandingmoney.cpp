#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
ll ans=0,cnt=0,n,m,c,t;
list<int>* g[35];
vector<int>arr(35),visited(35,0);
vector<vector<ll> >dp(35,vector<ll>(2,-1));

ll util(auto start,ll val,int choice){
    if(start>=n)return 0;
    if(visited[start])return val;
    if(dp[start][choice]!=-1)return dp[start][choice];
    visited[start]=1;
    dp[start][choice]=0;
    for(auto &jt:g[start]){
        if(choice){
            for(auto &it:g[start]) visited[it]++;
            dp[start][choice]+=util(jt,val+arr[start],0);
            for(auto &it:g[start]) visited[it]--;
        }
        else{
            if(!visited[jt]){
                ll a=util(jt,val,1);
                ll b=util(jt,val,0);
            }
            dp[start][choice]+=max(a,b);
        }
    }
    visited[start]=0;
    return dp[start][choice];
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)st.insert(i), cin>>arr[i];
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v; u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    util(0);
    cout<<ans<<endl;
    return 0;
}

