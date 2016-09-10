#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int firstUniqChar(string s) {
    int len=s.length();
    unordered_map<char,pair<int,int> >mp;
    for(int i=0;i<len;i++){
        if(mp.find(s[i])==mp.end())mp[s[i]]={1,i};
        else mp[s[i]]={mp[s[i]].first+1,mp[s[i]].second};
    }
    int ans=INT_MAX;
    for(auto &it:mp) if(it.second.first==1) ans=min(ans,it.second.second);
    return ans==INT_MAX?-1:ans;
}
int main(){
    string s;cin>>s;
    cout<<firstUniqChar(s)<<endl;
    return 0;
}
