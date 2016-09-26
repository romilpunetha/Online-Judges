#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

ll mod=1e9+7;

ll ncrdp(int n, int r, int p){
    ll C[r+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}

ll ncr(ll n, ll r, ll p)
{
    if (r==0)
        return 1;
    ll ni = n%p, ri = r%p;
    return (ncr(n/p, r/p, p) * ncrdp(ni, ri, p)) % p;
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n,k;cin>>n>>k;
    cout<<ncr(n,k,mod)<<endl;
    return 0;
}

