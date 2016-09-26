#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    unordered_map<int,int>mp;
    while(n--){
        int t;cin>>t;mp[t]++;
    }
    int ans=0;
    for(auto it:mp)ans+=it.ss/2;
    cout<<ans;
    return 0;
}

