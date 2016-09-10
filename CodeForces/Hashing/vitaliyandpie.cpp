#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,ans=0;cin>>n;
    string s;cin>>s;
    unordered_map<char,int>mp;
    for(int i=0;i<(int)s.length();i++){
        if(i%2==0) mp[s[i]]++;
        else if(mp[tolower(s[i])]==0) ans++;
        else mp[tolower(s[i])]--;
    }
    cout<<ans<<endl;
    return 0;
}

