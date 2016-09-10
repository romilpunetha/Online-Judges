#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int mod=1e9+7,a,b,k;
ll res=0;
vector<ll>fact(1e6+100,0);


ll exp(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res*=a,res%=mod;
        a*=a;
        a%=mod;
        b>>=1;
    }
    return res;
}

bool is_Excellent(ll num){
    while(num){
        if(num%10!=a && num%10!=b) return false;
        num/=10;
    }
    return true;
}

ll com(ll n,ll i){
    return ((fact[n] * exp(fact[i],mod-2)%mod) * exp(fact[n-i],mod-2))%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>k;
    fact[0]=1;
    for(int i=1;i<1e6+100;i++)fact[i]= (i*fact[i-1])%mod;
    for(int i=0;i<=k;i++){
        ll sum= a*i + b*(k-i);
        if(is_Excellent(sum)){
            res+=com(k,i);
            res%=mod;
        }
    }
    cout<<res<<endl;
    return 0;
}

