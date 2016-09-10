#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,balance=0,i,c=0,d=0,mn=INT_MAX,mod=1e9 + 7;cin>>n>>m;
    string s;cin>>s;
    vector<vector<int> > dp(n-m+1,vector<int>(n-m+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n-m;i++)
    {
        dp[i][0]=dp[i-1][1];
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=dp[i-1][j-1] + dp[i-1][j+1];
            dp[i][j]%=mod;
        }
    }
    i=0;
    while(s[i]!='\0')
    {
        balance+=s[i++]=='('?1:-1;
        mn=min(mn,balance);
    }
    ll ans=0;
    for(c=0;c<=n-m;c++)
    {
        for(d=0;d<=c;d++)
        {
            if(d>= -mn && d+balance<=n-m && d+balance>=0)
            {
                ans+= (ll)dp[c][d]*(ll)dp[n-m-c][d+balance];
                ans%=mod;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

