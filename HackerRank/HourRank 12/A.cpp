#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s;ll n;cin>>s>>n;
    int len=s.length();
    vector<int>arr(len,0);
    for(int i=0;i<len;i++){
        if(i)arr[i]+=arr[i-1];
        if(s[i]=='a')arr[i]+=1;
    }
    ll ans=0;
    ans=(n/len)*arr[len - 1];
    if(n%len)ans+= arr[(n%len) - 1];
    cout<<ans<<endl;
    return 0;
}

