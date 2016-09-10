#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

vector<ll>arr;
ll n,m;
ll ans=0;
ll bs(){
    ll start=1,end=2e9+10;
    while(start<end){
        ll mid= (start + end)>>1;
        ll sum=0;
        for(auto &it:arr){
            if(it>mid) sum+=it-mid;
        }
        if(sum>=m){
            start=mid+1;
            ans=max(ans,mid);
        }
        else end=mid;
    }
    return ans;
}

int main(){
    scanf(" %lld %lld",&n,&m);
    arr.resize(n);
    for(int i=0;i<n;i++) scanf(" %lld",&arr[i]);
    printf("%lld\n",bs());
    return 0;
}

