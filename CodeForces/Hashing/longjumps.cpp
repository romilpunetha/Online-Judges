#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,l,x,y,f1=0,f2=0,ans=-1;cin>>n>>l>>x>>y;
    unordered_set<int>mp;
    for(int i=0;i<n;i++){int t;cin>>t;
        mp.insert(t); f1= f1 || mp.find(t-x)!=mp.end();f2=f2 || mp.find(t-y)!=mp.end();
    }
    if(f1&&f2){cout<<0<<endl;return 0;}
    for(auto t:mp){
        if(t-x>=0 && (mp.find(t-x+y)!=mp.end() || mp.find(t-x-y)!=mp.end())) ans=t-x;
        if(t+x<=l && (mp.find(t+x+y)!=mp.end() || mp.find(t+x-y)!=mp.end())) ans=t+x;
        if(ans!=-1) break;
    }
    if(ans!=-1) {cout<<1<<endl<<ans<<endl; return 0;}
    if(f1){cout<<1<<endl<<y<<endl;return 0;}
    if(f2){cout<<1<<endl<<x<<endl;return 0;}
    cout<<2<<endl<<x<<" "<<y<<endl;
    return 0;
}

