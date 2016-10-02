#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int n,m;
vector<int>tree(1e6,0),lazy(1e6,0);
vector<char>arr(1e6);

void flip(int a){
    if(arr[a]=='>')arr[a]='<';
    else arr[a]='>';
}

void build(int node,int s,int e){
    if(s==e)tree[node]=0;
    else{
        int mid=(s+e)>>1;
        build(2*node+1,s,mid);
        build(2*node+2,mid+1,e);
        tree[node]=tree[2*node+1]+tree[2*node+2]+(arr[mid]=='<');
    }
}

void update(int node,int s,int e,int l,int r){
    if(s>r || e<l || s==e)return ;
    if(lazy[node]) lazy[node]=0,lazy[2*node+1]^=1,lazy[2*node+2]^=1;
    else if(s>=l && e<=r){
        tree[node]=e-s-tree[node];
        flip((s+e)>>1);
        lazy[2*node+1]^=1,lazy[2*node+2]^=1;
        return;
    }
    int mid=(s+e)>>1;
    update(2*node+1,s,mid,l,r);
    update(2*node+2,mid+1,e,l,r);
    if(mid<r && mid>=l)flip(mid);
    tree[node]=tree[2*node+1]+tree[2*node+2]+(mid<r && mid>=l && arr[mid]=='<');
}

int query(int node,int s,int e,int l,int r){
    if(s>r || e<l || s>=e)return 0;
    if(lazy[node]){
        tree[node]=e-s-tree[node];
        flip((s+e)>>1);
        lazy[node*2+1]^=1,lazy[2*node+2]^=1;
        lazy[node]=0;
    }
    if(s>=l && e<=r)return tree[node];
    int mid=(s+e)>>1;
    int p=query(2*node+1,s,mid,l,r);
    int q=query(2*node+2,mid+1,e,l,r);
    return p+q+((mid<r && mid>=l) && arr[mid]=='<');
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    n--;
    for(int i=0;i<n;i++) cin>>arr[i];
    build(0,0,n);
    while(m--){
        int t,p,q;cin>>t>>p>>q;
        p--,q--;
        if(t==1) update(0,0,n,p,q);
        else{
            if(p==q)cout<<0<<endl;
            else if(p<q)cout<<query(0,0,n,p,q)<<endl;
            else cout<<p-q-query(0,0,n,q,p)<<endl;
        }
    }
    return 0;
}

