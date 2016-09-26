#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;
    for(int tst=1;tst<=test;tst++){
        ll p,e,t;
        cin>>p>>e>>t;
        vector<ll>np(p),ne(e),nt(t);
        vector<pair<ll,ll> >npne(p*e);
        for(auto &it:np)cin>>it;
        for(auto &it:ne)cin>>it;
        for(auto &it:nt)cin>>it;
        int k=0;
        for(int i=0;i<p;i++){
            for(int j=0;j<e;j++){
                npne[k++]={(np[i]*ne[j]),ne[j]};
            }
        }
        unordered_multimap<ll,ll>mp;
        for(int i=0;i<e;i++){
            for(int j=0;j<t;j++){
                mp.insert({ne[i]*nt[j],ne[i]});
            }
        }
        cout<<"Case #"<<tst<<":"<<endl;
        cin>>k;
        while(k--){
            ll p,q;cin>>p>>q;
            int flag=1;
            for(auto &it:npne){
                if((it.first*q)%p==0){
                    auto r=mp.equal_range((it.first*q)/p);
                    for(auto jt=r.first;jt!=r.second && flag;jt++){
                        if(jt->second!=it.second)flag=0;
                    }
                }
            }
            if(!flag)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
