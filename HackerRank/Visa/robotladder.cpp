#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int mod=1e9+7;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n,k;
    cin>>n>>k;
    vector<vector<ll> >dp(k+1,vector<ll>(n+1,0));
    for(int i=1;i<=n;i++)dp[0][i]=1;
    for(int i=0;i<=k;i++)dp[i][1]=1,dp[i][0]=1;
    for(int i=1;i<=k;i++){
        for(int j=2;j<=n;j++){
            dp[i][j]+=dp[i][j-1]+dp[i-1][j-2];
            dp[i][j]%=mod;
        }
    }
    ll ans=0;
    for(int i=0;i<=k;i++) ans+=dp[i][n],ans%=mod;
    cout<<ans<<endl;
    return 0;
}

