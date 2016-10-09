#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef long double ld;

ld x[3010],y[3010],f[3010],dp[3010];
int n;

ld dist(ld x1,ld y1,ld x2,ld y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)dp[i]=INT_MIN;
    for(int i=0;i<n;i++)cin>>x[i]>>y[i]>>f[i];
    dp[n-1]=f[n-1];
    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            dp[j]=max(dp[j],dp[i]+f[j]-dist(x[i],y[i],x[j],y[j]));
        }
    }
    cout<<fixed<<setprecision(6)<<dp[0]<<endl;
    return 0;
}
