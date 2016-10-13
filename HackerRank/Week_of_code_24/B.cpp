#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;while(test--){
        int n;string s;cin>>n>>s;
        s=s[0]+s+s[n-1];
        bool space=0,happy=1;
        unordered_map<char,int>mp;
        for(int i=1;i<=n;i++){
            if(s[i]!=s[i-1] && s[i]!=s[i+1]) happy = 0;
            if(s[i]=='_')space=1;
            else mp[s[i]]++;
        }
        if(happy) cout<<"YES\n";
        else if(!happy && space==0) cout<<"NO\n";
        else {
            bool flag=0;
            for(auto &it:mp) if(it.second==1)flag=1;
            if(flag)cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
    return 0;
}

