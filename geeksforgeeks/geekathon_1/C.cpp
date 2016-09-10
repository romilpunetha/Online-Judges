#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

list<int>*g;
vector<bool>visited;

int dfs(int root,int x,int y){
    if(visited[x] && root==y)return 1;
    if(visited[y] && root==x)return 2;
    visited[root]=1;
    int ans=0;
    for(auto &it:g[root]){
        if(!visited[it])ans=dfs(it,x,y);
        if(ans)break;
    }
    visited[root]=0;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;while(test--){
        int n;cin>>n;
        g=new list<int>[n+1];
        vector<int>in(1010,0);
        visited.clear();
        visited.resize(n+1,0);
        for(int i=0;i<n-1;i++){
            int x,y;cin>>x>>y;
            g[x].push_back(y);
            in[y]++;
        }
        int q;cin>>q;while(q--){
            int x,y;cin>>x>>y;
            for(int i=1;i<=n;i++){
                if(!in[i]){
                    int ans=dfs(i,x,y);
                    if(!ans)cout<<"-1 ";
                    else if(ans==1)cout<<x<<" ";
                    else cout<<y<<" ";
                    break;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}

