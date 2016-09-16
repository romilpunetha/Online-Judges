#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
ll n,m,u,v,w,test;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>test;
    for(int t=1;t<=test;t++){
        cin>>n>>m;
        set<ll>ans;
        vector<pair<ll,pair<ll,pair<ll,ll> > > >st(m);
        vector<vector<ll> >arr(n,vector<ll>(n,INT_MAX));
        for(int i=0;i<m;i++){
            ans.insert(i);
            cin>>u>>v>>w;
            arr[u][v]=min(arr[u][v],w);
            arr[v][u]=min(arr[v][u],w);
            st[i]={i,{w,{u,v}}};
        }
        for(int k=0;k<n;k++){
            arr[k][k]=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(arr[i][j]>arr[i][k]+arr[k][j]){
                        arr[i][j]=arr[i][k]+arr[k][j];
                    }
                }
            }
        }
        for(auto &it:st){
            if(it.ss.ff==arr[it.ss.ss.ff][it.ss.ss.ss])ans.erase(it.ff);
        }
        cout<<"Case #"<<t<<":"<<endl;
        for(auto &it:ans)cout<<it<<endl;
    }
    return 0;
}

