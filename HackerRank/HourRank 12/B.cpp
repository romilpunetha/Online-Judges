#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    m=min(m,n-m);
    multiset<ll>st1,st2;
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];st2.insert(arr[i]);
    }
    sort(arr.begin(),arr.end());
    int j = (n-1) / 2, k = (n-1) / 2 + 2;
    for(int i = 0; i < m ; i++){
        if(!(i&1)) st1.insert(arr[j]), st2.erase(st2.find(arr[j])), j -= 2;
        else st1.insert(arr[k]), st2.erase(st2.find(arr[k])), k += 2;
    }
    ll ans = 0;
    for(auto &it:st1){
        for(auto &jt:st2){
            ans +=
                abs(it-jt);
        }
    }
    cout<<ans<<endl;
    return 0;
}

