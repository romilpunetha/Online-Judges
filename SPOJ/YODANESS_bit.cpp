#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
unordered_map<string,int>mp;
int test,size,i,ans;
vector<int>bit (1e6+10,0);
vector<int>arr (1e6+10,0);

void init(){
    i=0;
    bit.clear();
    bit.resize(1e6+10);
    mp.clear();
    mp.reserve(1e6+10);
    arr.clear();
    arr.resize(size+1);
    ans=0;
}

void update(int ind,int val){
    while(ind<=size){
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
    for(cin>>test;test--;){
        init();
        cin>>size;
        for(i=1;i<=size;i++){
            string t;cin>>t;
            mp[t]=i;
        }
        for(i=1;i<=size;i++) {
            string t;cin>>t;arr[i]=mp[t];
        }
        for(i=size;i>0;i--){
            ans+=query(arr[i]-1);
            update(arr[i],1);
        }
        cout<<ans<<endl;
    }
    return 0;
}

