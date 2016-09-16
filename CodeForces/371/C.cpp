#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll mx=(1e5+10)*20,t=0;
vector<vector<ll> >arr(mx,vector<ll>(2,-1));
vector<ll>cnt(mx,0);

void insert(ll num){
    ll p=0;
    for(int i=20;i>=0;i--){
        if(arr[p][num&1]==-1) arr[p][num&1]=++t;
        p=arr[p][num&1],cnt[p]++;
        num/=10;
    }
}

void erase(ll num){
    ll p=0;
    for(int i=20;i>=0;i--){
        p=arr[p][num&1];
        cnt[p]--;
        num/=10;
    }
}

ll query(string &num){
    ll p=0;
    for(int i=20;i>=0;i--){
        if(arr[p][num&1]!=-1 && cnt[arr[p][(num&1)]]) p=arr[p][(num&1)];
        else return 0;
        num/=10;
    }
    return cnt[p];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;while(n--){
        char c;ll t;cin>>c>>t;
        if(c=='+') insert(t);
        if(c=='-') erase(t);
        if(c=='?') cout<<query(t)<<endl;
    }
    return 0;
}

