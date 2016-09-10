#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
vector<ll>bit;
int test,q,n,u,size,i;
void init(){
    i=0;
    bit.clear();
    bit.resize(1e6+10,0);
}

void update(int ind,ll val){
    while(ind<=size){
        bit[ind]+=val;
        ind+=ind&-ind;
    }
}

ll query(int ind){
    ll sum=0;
    while(ind>0){
        sum+=bit[ind];
        ind-=ind&-ind;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(cin>>test;test--;){
        cin>>n>>u;size=n;
        init();
        for(i=0;i<u;i++){
            int l,r,val;cin>>l>>r>>val;l++,r++;
            update(l,val);
            update(r+1,-val);
        }
        cin>>q;
        for(i=0;i<q;i++){
            int l;cin>>l;l++;
            cout<<query(l)<<endl;
        }
    }
    return 0;
}

