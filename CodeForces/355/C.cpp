#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;cin>>s;
    int t=0,mod=1e9 +7,ans=1,cnt=0;
    unordered_map<char,int>mp;
    mp.reserve(64);
    for(char i='0';i<='9';i++) mp[i]=t++;
    for(char i='A';i<='Z';i++) mp[i]=t++;
    for(char i='a';i<='z';i++) mp[i]=t++;
    mp['-']=t++;mp['_']=t;
    int len=s.size();
    for(int i=0;i<len;i++){
        int num=mp[s[i]];
        for(int j=0;j<6;j++) cnt+= (num&(1<<j))==0?1:0;
    }
    while(cnt--) ans= ((ll)ans*3)%mod;
    cout<<ans<<endl;
    return 0;
}

