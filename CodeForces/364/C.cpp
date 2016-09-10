#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n;string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s;
    int i=0,start=0,ans=INT_MAX;
    map<char,int>mp;
    while(s[i])mp[s[i++]]++;
    i=0;int res=mp.size();
    mp.clear();
    while(i<n){
        while(i<n && (int)mp.size()<res)mp[s[i]]++,i++;
        while(start<n && (int)mp.size()==res){
            mp[s[start]]--;
            ans=min(i-start,ans);
            if(mp[s[start]]==0)mp.erase(s[start]);
            start++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

