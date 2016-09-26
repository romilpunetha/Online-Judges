#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

unordered_map<ll,vector<pair<ll,ll> > >mp;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n,m,k,r,c1,c2;
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        cin>>r>>c1>>c2;
        mp[r].push_back({c1,-k});
        mp[r].push_back({c2,k});
    }
    for(auto &it:mp)sort(it.ss.begin(),it.ss.end());
    ll ans=0;
    for(auto &it:mp){
        vector<pair<ll,ll> >&arr=it.ss;
        int len=arr.size(),active=0,prev=0;
        for(int i=0;i<len;i++){
            if(arr[i].ss<0){
                active++;
                if(active==1) prev=arr[i].ff;
            }
            else{
                active--;
                if(active==0)ans+=arr[i].ff-prev+1;
            }
        }
    }
    cout<<n*m-ans<<endl;
    return 0;
}

