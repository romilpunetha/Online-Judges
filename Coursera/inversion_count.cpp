#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll size,i,ans=0;
vector<int>bit (1e6+10,0);

void update(int ind,int val){
    while(ind<=1e6){
        bit[ind]+=val;
        ind+=ind & -ind;
    }
}

int query(int ind){
    int sum=0;
    while(ind>0){
        sum+=bit[ind];
        ind-=ind&-ind;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll size=100000;
    vector<int>arr(size);
    for(auto &it:arr)cin>>it;
    for(i=size-1;i>=0;i--){
        ans+=query(arr[i]-1);
        update(arr[i],1);
    }
    cout<<ans<<endl;
    return 0;
}

