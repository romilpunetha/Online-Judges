#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int m,n;
map<ll,int>mp;
vector<int>bit(1000010,0);

void update(int i){
    while(i<=1000000){
        bit[i]++;
        i+=i&-i;
    }
}

int query(int i){
    int sum=0;
    while(i>0){
        sum+=bit[i];
        i-=i&-i;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    vector<ll>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i],mp[arr[i]]=1;
    int t=0;
    for(auto &it:mp)it.second=++t;
    for(auto &it:arr)it=mp[it],update(it);
    for(int i=0;i<m;i++){
        int t;cin>>t;
        auto q=mp.lower_bound(t);
        if(q->first!=t && q==mp.begin()){cout<<0<<" ";continue;}
        else if(q->first!=t) q--;
        cout<<query(q->second)<<" ";
    }
    return 0;
}

