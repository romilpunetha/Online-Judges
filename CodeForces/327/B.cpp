#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,m,i=0;
    string s;
    unordered_map<char,list<int> >mp;
    cin>>n>>m>>s;
    while(s[i]){
        mp[s[i]].push_back(i);
        i++;
    }
    while(m--){
        char a,b;cin>>a>>b;
        if(a==b)continue;
        swap(mp[a],mp[b]);
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        for(auto jt=(it->second).begin();jt!=(it->second).end();jt++) s[*jt]=it->first;
    }
    cout<<s<<endl;
    return 0;
}

