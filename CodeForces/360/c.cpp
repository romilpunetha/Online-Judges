#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
vector<set<int> >g;
vector<int>color,visited;
int flag=0;

int neg(int a){
    return a==1?2:1;
}

void dfs(int root,int clr){
    visited[root]=1;
    color[root]=clr;
    for(auto it:g[root]){
        if(color[it]==color[root]){flag=1;return;}
        else if(!visited[it]) dfs(it,neg(color[root]));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;cin>>n>>m;
    g.resize(n);
    color.resize(n,0);
    visited.resize(n,0);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;u--;v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    for(int i=0;i<n;i++){
        if(!visited[i]) dfs(i,1);
        if(flag)break;
    }
    if(flag)cout<<-1<<endl;
    else{
        int c1=0,c2=0;
        for(auto it:color) {c1+=it==1;c2+=it==2;}
        cout<<c1<<endl;
        for(int i=0;i<n;i++) if(color[i]==1) cout<<i+1<<" ";
        cout<<endl;
        cout<<c2<<endl;
        for(int i=0;i<n;i++) if(color[i]==2) cout<<i+1<<" ";
        cout<<endl;
    }
    return 0;
}

