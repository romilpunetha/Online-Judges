#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll a,b,m=0,n=0,i=0;
string s;

ll exp(ll a,ll b,ll mod){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res%mod;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>s>>a>>b;
    int len=s.length();
    vector<ll>arr(1e6);
    m=(s[0]-'0')%a;
    for(i=1;i<len;i++) n=(n*10+(s[i]-'0'))%b;
    whats(m);whats(n);
    for(i=1;i<len;i++){
        if(s[i]-'0' && !m && !n) break;
        m=(m*10+(s[i]-'0'))%a;
        n=(n - (((s[i]-'0') * exp(10,len-i-1,b))%b)+b)%b;
    }
    if(i<len){
        cout<<"YES\n";
        for(int j=0;j<len;j++){
            cout<<s[j];
            if(j==i-1)cout<<endl;
        }
        cout<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}

