#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
typedef struct nodes{
    ll len=0,mn=0,mx=0;
}nodes;

vector<nodes>tree(1e6+10);
vector<int>arr(1e5+10);
int n,q,t,x,y;

void build(int node,int s,int e){
    if(s==e)tree[node]={1,arr[s],arr[s]};
    else{
        int mid=(s+e)>>1;
        build(2*node+1,s,mid);
        build(2*node+2,mid+1,e);
        if(tree[2*node+1].mx<tree[2*node+2].mn)tree[node]={tree[2*node+1].len+tree[2*node+2].len,tree[2*node+1].mn,tree[2*node+2].mx};
        else tree[node]=tree[2*node+2];
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;
    while(test--){
        cin>>n>>q;
        for(int i=0;i<n;i++)cin>>arr[i];
        build(0,0,n-1);
        for(int i=0;i<2*n;i++)cout<<tree[i].len<<" ";cout<<endl;
        while(q--){
            cin>>t>>x>>y;
            if(t){

            }
            else{

            }
        }
    }
    return 0;
}

