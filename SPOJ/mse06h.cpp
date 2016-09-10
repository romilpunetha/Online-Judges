#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
vector<int>bit;
int n,m,k;

void init(){
    bit.clear();
    bit.resize(1e6+10);
}

void update(int ind,int val){
    while(ind<=max(n,m)){
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
    int test;
    cin>>test;
    for(int t=1;t<=test;t++){
        cin>>n>>m>>k;
        init();
        vector<pair<int,int> >arr(k);
        for(int i=0;i<k;i++){
            cin>>arr[i].first>>arr[i].second;
        }
        sort(arr.begin(),arr.end());
        ll ans=0;
        for(int i=k-1;i>=0;i--){
            ans+=query(arr[i].second-1);
            update(arr[i].second,1);
        }
        cout<<"Test case "<<t<<": "<<ans<<endl;
    }
    return 0;
}

