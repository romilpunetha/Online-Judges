#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
ll ans=0,n,q,lim=5e5,mod=1e9+7;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    vector<ll>a(n),b(n),dp1(lim,0),dp2(lim,0);
    dp1[0]=dp2[0]=1;
    for(auto &it:a)cin>>it;
    for(auto &it:b)cin>>it;
    cin>>q;
    for(int i=0;i<n;i++){
        for(int j=lim-a[i]-1;j>=0;j--){
            if(dp1[j])dp1[j+a[i]]+=dp1[j];
            dp1[j+a[i]]%=mod;
        }
        for(int j=lim-b[i]-1;j>=0;j--){
            if(dp2[j])dp2[j+b[i]]+=dp2[j];
            dp2[j+b[i]]%=mod;
        }
    }
    for(int i=1;i<lim;i++)dp1[i]+=dp1[i-1],dp1[i]%=mod;
    for(int i=0;i<=lim-q-1;i++){
        ll s=0,e=dp1[lim-1]%mod;
        if(i-q-1>=0)s=dp1[i-q-1]%mod;
        if(i+q<lim)e=dp1[i+q]%mod;
        ans=(ans%mod+ ((e-s+mod)%mod*dp2[i]%mod)%mod +mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}

