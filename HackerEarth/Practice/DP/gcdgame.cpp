#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int dp[1010][1010];

void generate(){
    for(int i=1;i<1010;i++){
        for(int j=i;j<1010;j++){
            if(i==1)dp[i][j]=1;
            else if(j==1)dp[i][j]=0;
            else{
                dp[i][j]=(dp[j-1][i] | (__gcd(i,j)>1?dp[j/__gcd(i,j)][i]:0))^1;
                dp[j][i]=(dp[i-1][j] | (__gcd(i,j)>1?dp[i/__gcd(i,j)][j]:0))^1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    generate();
    int test;cin>>test;while(test--){
        int a,b;cin>>a>>b;
        if(a==1 && b==1){cout<<"Draw\n";continue;}
        cout<<(dp[a][b]?"Chandu Don\n":"Arjit\n");
    }
    return 0;
}

