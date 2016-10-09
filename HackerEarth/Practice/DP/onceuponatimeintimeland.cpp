#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;while(test--){
        int n,k;cin>>n>>k;
        vector<ll>arr(n),dp(1e6+10,0);
        for(auto &it:arr)cin>>it;
        for(int i=n-1;i>=0;i--){
            dp[i]=max(dp[i+1],max(arr[i],0LL)+dp[i+k+1]);
        }
        for(int i=0;i<=k;i++)dp[0]=max(dp[0],dp[i]);
        cout<<dp[0]<<endl;
    }
    return 0;
}

