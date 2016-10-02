#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int test;
string a,b;
ll dp[1000][1000];
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>test;
    for(int t=0;t<test;t++){
        cin>>a>>b;
        int l1=a.length(),l2=b.length();
        ll ans=0,i=0;
        while(a[i])ans+=a[i++]-'0';
        i=0;
        while(b[i])ans+=b[i++]-'0';
        memset(dp,0,sizeof(dp));
        for(i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(a[i-1]==b[j-1]){
                    dp[i][j]=max(dp[i][j],dp[i][j-1]+2*(a[i-1]-'0'));
                }
            }
        }
        cout<<ans-dp[l1][l2]<<endl;
    }
    return 0;
}

