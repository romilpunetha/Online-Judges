#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int n,m,k,test,u,v;
vector<vector<ll> >dist;
vector<ll>w(24);
list<pair<int,vector<ll> > >*g;

void ini(){
    dist.clear();
    dist.resize(24,vector<ll>(n+1,INT_MAX));
    for(int i=0;i<24;i++) dist[i][1]=0;
}


void dijkstras(){
    for(int i=0;i<24;i++){
        priority_queue<pair<ll,pair<int,int> > ,vector<pair<ll,pair<int,int> > >,greater<pair<ll,pair<int,int> > > >pq;
        pq.push({0,{1,i}});
        while(!pq.empty()){
            pair<ll,pair<int,int> >pp=pq.top();pq.pop();
            for(auto &it:g[pp.ss.ff]){
                if(dist[i][it.ff]>dist[i][pp.ss.ff]+it.ss[pp.ss.ss]){
                    dist[i][it.ff]=dist[i][pp.ss.ff]+it.ss[pp.ss.ss];
                    pq.push({dist[i][it.ff],{it.ff,(it.ss[pp.ss.ss] + pp.ss.ss)%24}});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>test;
    for(int t=1;t<=test;t++){
        cin>>n>>m>>k;
        ini();
        g=new list<pair<int,vector<ll> > >[n+1];
        for(int i=0;i<m;i++){
            cin>>u>>v;
            for(auto &it:w)cin>>it;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        cout<<"Case #"<<t<<": ";
        dijkstras();
        while(k--){
            int d,time;cin>>d>>time;
            cout<<(dist[time][d]==INT_MAX?-1:dist[time][d])<<" ";
        }
        cout<<endl;
    }
    return 0;
}

