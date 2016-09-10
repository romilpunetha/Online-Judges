#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int mod=1e9+7;
ll fast_pow(ll a, ll b, ll m) {
    ll res=1;
    while(b) {
        if(b&1) res = (res*a)%m;
        a = (a*a)%m;
        b>>=1;
    }
    return res%mod;
}

int main() { std::ios::sync_with_stdio(false); cin.tie(NULL);
    ll a, b, n, x;
    cin>>a>>b>>n>>x;
    if(a==1){
        cout<< (x + ((n%mod)*b)%mod)%mod<<endl;
        return 0;
    }
    n=n%mod;
    ll an = fast_pow(a, n, mod);
    ll sec = ((an -1) * fast_pow(a-1, mod-2, mod))%mod;
    sec = (sec*b)%mod;
    an = (an*x)%mod;
    cout<< (an + sec)%mod;
    return 0;
}
