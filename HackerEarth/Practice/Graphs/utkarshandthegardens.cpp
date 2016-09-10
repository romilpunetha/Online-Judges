#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
list<int>*g;
vector<bool>visited;
int ans=0;

void dfs(int root,const int &start,int count){
    if(count>3) return;
    visited[root]=1;
    for(auto &it:g[root]){
        if(!visited[it])dfs(it,start,count+1);
        else ans+=(count==3 && it==start);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    visited.resize(n,0);
    g=new list<int>[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int t;cin>>t;
            if(t)g[i].push_back(j);
        }
    }
    for(int i=0;i<n;i++){
        visited.clear();
        visited.resize(n,0);
        dfs(i,i,0);
    }
    cout<<ans/4<<endl;
    return 0;
}

