#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
ll mod=1e9+7;

ll pow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n,ans=0,t=1;cin>>n;
    vector<ll>arr(n),g(n+1,0);
    for(int i=0;i<n;i++)cin>>arr[i],arr[i]%=mod;
    g[0]=pow(2,n);
    for(int i=1;i<=n/2;i++) {
        g[i]=g[i-1] + pow(2,n-2*i);
        g[i]%=mod;
    }
    t=1;
    for(int i=0;i<n;i++){
        ans+= (arr[i] * (i<=(n-1)/2?g[i]-t:g[n-i-1]-t))%mod;
        if(i<=(n-1)/2){whats(g[i]);t<<=1;}
        else {whats(g[n-i-1]);t>>=1;}
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}

