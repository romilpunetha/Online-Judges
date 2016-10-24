#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int test,n,q,t,len,mod=1e9+7;
string s;
map<multiset<char>,ll >mp;
unordered_map<ll,ll>dp;
ll util(int start){
    if(dp.find(start)!=dp.end())return dp[start];
    dp[start]=0;
    multiset<char>st;
    for(int i=start;i<len;i++){
        st.insert(s[i]);
        if(mp.find(st)!=mp.end()){
            if(i+1==len){
                return dp[start]=(dp[start]+mp[st])%mod;
            }
            dp[start]=(dp[start]+((util(i+1)%mod)*mp[st])%mod)%mod;
        }
    }
    return dp[start];
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>test;
    for(int tt=1;tt<=test;tt++){
        t=1;
        mp.clear();
        cin>>n>>q;
        while(n--){
            cin>>s;
            multiset<char>st;
            int i=0;
            while(s[i]) st.insert(s[i++]);
            mp[st]++;
            mp[st]%=mod;
        }
        cout<<"Case #"<<tt<<":";
        while(q--){
            cin>>s;
            dp.clear();
            len=s.length();
            cout<<" "<<util(0);
        }
        cout<<endl;
    }
    return 0;
}

