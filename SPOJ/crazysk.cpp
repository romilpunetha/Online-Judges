#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    for(cin>>test;test--;){
        unsigned long long x,n,ans=0,rem=0;cin>>x>>n;
        rem=ans=x;
        while(rem>=n){
            ll s=rem%n;
            ll t=rem/n;
            ans+=t;
            rem=s+t;
        }
        cout<<ans<<endl;
    }
    return 0;
}

