#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m,ans=0;
list<int> *arr;
vector<int>cats;

void dfs(int root,int parent,int cnt){
    if(cats[root]) cnt++;
    else cnt=0;
    if(cnt>m) return;
    for(auto it:arr[root]){
        if(it!=parent)
            dfs(it,root,cnt);
    }
    if(cnt<=m && root!=0 && arr[root].size()==1) ans++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    arr=new list<int>[n];
    cats=vector<int>(n,0);
    for(int i=0;i<n;i++) cin>>cats[i];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;u--,v--;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    dfs(0,-1,0);
    cout<<ans<<endl;
    return 0;
}

