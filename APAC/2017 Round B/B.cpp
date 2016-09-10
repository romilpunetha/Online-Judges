#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll a,b,n,k,ans=0,rep=0;

ll exp(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%k;
        a=(a*a)%k;
        b>>=1;
    }
    return res%k;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;
    for(int t=1;t<=test;t++){
        cin>>a>>b>>n>>k;
        ans=0;
        vector<ll>A(k,0),B(k,0);
        for(int i=1;i<=k;i++){
            ll p=exp(i,a);
            ll q=exp(i,b);
            ll cnt=(n/k) + (i<=(n%k));
            A[p]+=cnt,B[q]+=cnt;
            A[p]%=mod,B[q]%=mod;
            if((p+q)%k==0)ans-=cnt%mod,ans=(ans%mod);
        }
        for(int i=0;i<k;i++){
            ans+=A[i]*B[(k-i)%k] %mod;
            ans=(ans%mod +mod)%mod;
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 0;
}

