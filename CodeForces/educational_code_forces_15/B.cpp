#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    unordered_map<ll,ll>mp;
    ll res=0;
    for(int i=0;i<n;i++){
        ll t;cin>>t;
        ll num=2;while(num<t)num<<=1;
        while(num<=1e9+1e9)res+=mp[num-t],num<<=1;
        mp[t]++;
    }
    cout<<res<<endl;
    return 0;
}

