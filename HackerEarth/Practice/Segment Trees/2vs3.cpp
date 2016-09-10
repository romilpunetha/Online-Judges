#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
vector<int>tree(1e6+10,0),arr(1e6,0);

int expp(int a,int b){
    int res=1;
    while(b){
        if(b&1)res=(res*a)%3;
        a=(a*a)%3;
        b>>=1;
    }
    return res%3;
}

void build(int node,int start,int endd){
    if(start==endd) tree[node]=arr[start];
    else{
        int mid=(start+endd)>>1;
        build(2*node+1,start,mid);
        build(2*node+2,mid+1,endd);
        tree[node]=((tree[2*node+1]* expp(2,endd-mid))%3 + tree[2*node+2])%3;
    }
}

void update(int node,int s,int e,int idx){
    if(s==e){if(!arr[idx])arr[idx]=1,tree[node]=1;}
    else{
        int mid=(s+e)>>1;
        if(s<=idx && idx<=mid)update(node*2+1,s,mid,idx);
        else update(node*2+2,mid+1,e,idx);
        tree[node]=((tree[2*node+1]* expp(2,e-mid))%3 + tree[2*node+2])%3;
    }
}

int query(int node,int start,int endd,int l,int r){
    if(start>r || endd<l)return 0;
    if(start>=l && endd<=r)return tree[node];
    int mid=(start+endd)>>1;
    int p=query(2*node+1,start,mid,l,r);
    int q=query(2*node+2,mid+1,endd,l,r);
    return ((p*expp(2,max(min(r,endd)-mid,0)))%3 + q)%3;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s;int q,n;cin>>n>>s>>q;
    for(int i=0;i<n;i++)arr[i]=s[i]-'0';
    build(0,0,n-1);
    while(q--){
        int t,l,r;cin>>t;
        if(!t) {cin>>l>>r;cout<<query(0,0,n-1,l,r)<<endl;}
        else{cin>>l;update(0,0,n-1,l);}
    }
    return 0;
}

