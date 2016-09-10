#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

list<int>*g;
vector<bool>visited;
vector<int>arr;
vector<int>ind,val;

void dfs(int root){
    visited[root]=true;
    val.push_back(arr[root]);
    ind.push_back(root);
    for(auto &it:g[root]){
        if(!visited[it])dfs(it);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;cin>>n>>m;
    arr.resize(n);
    visited.resize(n,0);
    g=new list<int>[n];
    for(auto &it:arr)cin>>it;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            val.clear(),ind.clear(),dfs(i);
            sort(val.begin(),val.end(),[](int a,int b){return a>b;});
            sort(ind.begin(),ind.end());
            for(int i=0;i<ind.size();i++){
                arr[ind[i]]=val[i];
            }
        }
    }
    for(auto &it:arr)cout<<it<<" ";cout<<endl;
    return 0;
}

