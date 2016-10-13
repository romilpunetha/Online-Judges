#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int s,t,a,b,m,n,k,ans=0;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>s>>t>>a>>b>>m>>n;
    while(m--){ cin>>k; ans+=(a+k>=s && a+k<=t); }
    cout<<ans<<endl; ans=0;
    while(n--){ cin>>k; ans+=(b+k>=s && b+k<=t); }
    cout<<ans<<endl;
    return 0;
}

