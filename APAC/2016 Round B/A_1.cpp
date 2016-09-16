#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int n,m,k,test,u,v;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>test;
    for(int t=1;t<=test;t++){
        cin>>n>>m>>k;
        ll dp[n+1][n+1][24];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<24;k++)dp[i][j][k]=INT_MAX,dp[i][i][k]=0;
            }
        }
        for(int i=0;i<m;i++){
            cin>>u>>v;
            for(int j=0;j<24;j++){
                cin>>dp[u][v][j];
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    for(int t=0;t<24;t++){
                        if(dp[i][j][t]>dp[i][k][(t-2+24)%24]+dp[k][j][(t-1+24)%24])
                        {
                            dp[i][j][t]=dp[i][k][(t-2+24)%24]+dp[k][j][(t-1+24)%24];
                        }
                    }
                }
            }
        }
        cout<<"Case #"<<t<<": ";
        while(k--){
            int d,time;cin>>d>>time;
            ll ans=INT_MAX;
            for(int i=0;i<24;i++){
                ans=min(ans,dp[1][d][i]);
            }
            cout<<(ans==INT_MAX?-1:ans)<<" ";
        }
        cout<<endl;
    }
    return 0;
}

