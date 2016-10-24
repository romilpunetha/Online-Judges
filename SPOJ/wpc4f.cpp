#include<bits/stdc++.h>
#define tr1(x)                cerr << #x << ": " << x << endl;
#define tr2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

typedef struct node{
    ll a,b,c;
}node;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;while(test--){
        int n;cin>>n;
        vector<node>dp(n+1,{0,0,0});
        for(int i=1;i<=n;i++){
            int p,q,r;cin>>p>>q>>r;
            dp[i].a=min(dp[i-1].b, dp[i-1].c) + p;
            dp[i].b=min(dp[i-1].a, dp[i-1].c) + q;
            dp[i].c=min(dp[i-1].a, dp[i-1].b) + r;
        }
        cout<<min(dp[n].a, min(dp[n].b, dp[n].c))<<endl;
    }
    return 0;
}

