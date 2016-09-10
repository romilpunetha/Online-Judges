#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
vector<pair<int,int> >arr(1e5+10);
vector<int>tree(4*(1e5+10),0),lazy(4*(1e5+10),0);
int n,m;

void build(int node,int s,int e){
    if(s==e)tree[node]=arr[s].first;
    else{
        int mid=(s+e)>>1;
        build(2*node+1,s,mid);
        build(2*node+2,mid+1,e);
        tree[node]=min(tree[node*2+1],tree[node*2+2]);
    }
}

void update(int node,int s,int e,int l,int r,int x,int val){
    if(s>e || s>r || e<l)return ;
    if(lazy[node]){
        tree[node]+=lazy[node];
        if(s!=e) lazy[node*2+1]+=lazy[node],lazy[2*node+2]+=lazy[node];
        lazy[node]=0;
    }
    if(tree[node]>x){
        tree[node]+=val;
        if(s!=e)lazy[2*node+1]+=val,lazy[2*node+2]+=val;
        return;
    }
    if(s==e)return;
    int mid=(s+e)>>1;
    update(2*node+1,s,mid,l,r,x,val);
    update(2*node+2,mid+1,e,l,r,x,val);
    tree[node]=min(tree[node*2+1],tree[node*2+2]);
}

int query(int node,int s,int e,int l,int r){
    if(s>e || s>r || e<l)return INT_MAX;
    if(lazy[node]){
        tree[node]+=lazy[node];
        if(s!=e)lazy[2*node+1]+=lazy[node],lazy[2*node+2]+=lazy[node];
        lazy[node]=0;
    }
    if(s>=l && e<=r)return tree[node];
    int mid=(s+e)>>1;
    int p=query(2*node+1,s,mid,l,r);
    int q=query(2*node+2,mid+1,e,l,r);
    return min(p,q);
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second=i+1;
    }
    sort(arr.begin(),arr.begin()+n);
    build(0,0,n-1);
    cin>>m;while(m--){
        int t;cin>>t;
        update(0,0,n-1,0,n-1,t,-1);
    }
    for(int i=0;i<n;i++) arr[i].first=query(0,0,n-1,i,i),swap(arr[i].first,arr[i].second);
    sort(arr.begin(),arr.begin()+n);
    for(int i=0;i<n;i++)cout<<arr[i].second<<" ";cout<<endl;
    return 0;
}

