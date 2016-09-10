#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a,b,p,q;cin>>n>>a>>b>>p>>q;
    ll red=n/a;
    ll blue=n/b;
    ll both=n/((a*b)/__gcd(a,b));
    red-=both;blue-=both;
    ll sum=red*p+blue*q+ both*(max(p,q));
    cout<<sum<<endl;

    return 0;
}

