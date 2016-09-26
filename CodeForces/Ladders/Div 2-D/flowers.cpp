#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int mod=1e9+7;
ll arr[1000010],dp[1000010];
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,k;cin>>n>>k;
    memset(arr,0,sizeof(arr));
    memset(dp,0,sizeof(dp));
    arr[0]=1;dp[0]=0;
    for(int i=1;i<k;i++)arr[i]=1,dp[i]=(dp[i-1]+arr[i])%mod;
    for(int i=k;i<1e6;i++){
        arr[i]=(arr[i-1]+arr[i-k])%mod;
        dp[i]=(dp[i-1]+arr[i])%mod;
    }
    while(n--){
        int a,b;cin>>a>>b;
        cout<<(dp[b]%mod - dp[a-1]%mod +mod)%mod<<endl;
    }
    return 0;
}

