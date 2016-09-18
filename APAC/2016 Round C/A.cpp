#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;
    for(int tst=1;tst<=test;tst++){
        cout<<"Case #"<<tst<<": \n";
        int p;cin>>p;
        vector<ll>pt(p);
        for(auto &it:pt)cin>>it;
        int n;cin>>n;
        unordered_map<string,multiset<ll> >mp;
        while(n--){
            ll w;cin>>w;
            for(int i=0;i<p;i++){
                string s;cin>>s;
                mp[s].insert(w*pt[i]);
            }
        }
        int m;cin>>m;
        set<pair<ll,string> >st;
        ll t,scr;
        for(auto &it:mp){
            t=m,scr=0;
            for(auto jt=it.second.rbegin();(jt!=it.second.rend()) && t;jt++,t--) scr+=(*jt);
            st.insert({-scr,it.first});
        }
        t=1,scr=1,m=1;
        for(auto it=st.begin();it!=st.end();it++){
            if(it->first==scr) cout<<m<<": ";
            else cout<<t<<": ",m=t;
            cout<<it->second<<endl;
            scr=it->first;
            t++;
        }
    }
    return 0;
}

