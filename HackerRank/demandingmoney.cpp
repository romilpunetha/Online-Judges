#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int n,m,c,t;
list<int>* g;

bool myfun(const pair<int,pair<ll,ll> >&a,const pair<int,pair<ll,ll> >&b){
    return a.ss.ff-a.ss.ss>b.ss.ff-b.ss.ss;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    vector<pair<int,pair<ll,ll> > >arr(n,{0,{0,0}});
    unordered_set<int>st;
    unordered_map<ll,int>mp;
    g=new list<int>[n+1];
    for(int i=0;i<n;i++)st.insert(i), cin>>arr[i].ss.ff;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v; u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
        arr[u].ss.ss+=arr[v].ss.ff;
        arr[v].ss.ss+=arr[u].ss.ff;
    }
    for(auto &it:arr)mp[it.ss.ff-it.ss.ss]++;
    sort(arr.begin(),arr.end(),myfun);
    ll ans=0,cnt=0;
    for(int i=0;i<n;i++){
        if(st.find(arr[i].ff)!=st.end()){
            ans+=arr[i].ss.ff;
            st.erase(arr[i].ff);
            for(auto &it:g[arr[i].ff])st.erase(it);
        }
    }
    cout<<ans<<endl;
    return 0;
}

