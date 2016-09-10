#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
vector<int>tree(1e6+10,0),arr(1e6,0);

int expp(int a,int b){
    int res=1;
    while(b){
        if(b&1)res=(res*a)%7;
        a=(a*a)%7;
        b>>=1;
    }
    return res%7;
}

void build(int node,int start,int endd){
    if(start==endd) tree[node]=arr[start];
    else{
        int mid=(start+endd)>>1;
        build(2*node+1,start,mid);
        build(2*node+2,mid+1,endd);
        tree[node]=((tree[2*node+1]* expp(10,endd-mid))%7 + tree[2*node+2])%7;
    }
}

int query(int node,int start,int endd,int l,int r){
    if(start>r || endd<l)return 0;
    if(start>=l && endd<=r)return tree[node];
    int mid=(start+endd)>>1;
    int p=query(2*node+1,start,mid,l,r);
    int q=query(2*node+2,mid+1,endd,l,r);
    return ((p*expp(10,max(min(r,endd)-mid,0)))%7 + q)%7;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s;int q;cin>>s>>q;
    int len=s.length();
    for(int i=0;i<len;i++)arr[i]=(s[i]-'0')%7;
    build(0,0,len-1);
    while(q--){
        int l,r;cin>>l>>r;l--,r--;
        if(!query(0,0,len-1,l,r))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

