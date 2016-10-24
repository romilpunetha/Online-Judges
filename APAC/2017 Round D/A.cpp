#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
double dp[2001][2001];
double count(int n,int m,int vote,double p) {
    if(dp[n][m]>=0)return dp[n][m];
    if(n==0||m==0)  return dp[n][m]=p;
    if(vote==0) return dp[n][m]=0;
    if(vote==1) return dp[n][m]=count(n-1,m,vote+1,p*((double)n/(n+m)));
    dp[n][m]=count(n-1,m,vote+1,p*((double)n/(n+m))) + count(n,m-1,vote-1,p*((double)m/(n+m)));
    return dp[n][m];
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;
    for(int tt=1;tt<=test;tt++){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<2000;i++) for(int j=0;j<2000;j++) dp[i][j]=-1;
        cout<<"Case #"<<tt<<": ";
        double p=((double)n)/(n+m);
        dp[n][m]=p;
        double val=count(n-1,m,1,p);
        cout<<fixed<<setprecision(10)<<val<<endl;
    }
    return 0;
}

