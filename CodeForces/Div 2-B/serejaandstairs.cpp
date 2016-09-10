#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int t;cin>>t;mp[t]++;
    }
    vector<int>res;
    for(auto &it:mp) {res.push_back(it.first);it.second--;}
    for(auto it=mp.rbegin();it!=mp.rend();it++){
        if(it==mp.rbegin()) continue;
        if(it->second!=0) res.push_back(it->first);
    }
    cout<<res.size()<<endl;
    for(auto it:res) cout<<it<<" ";cout<<endl;
    return 0;
}

