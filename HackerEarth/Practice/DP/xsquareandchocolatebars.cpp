#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int n,len;
string bar;
vector<int>dp;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    while(n--){
        dp.clear();
        dp.resize(1e6,0);
        cin>>bar;
        len=bar.length();
        for(int i=len-3;i>=0;i--){
            int a=0;
            for(int j=i;j<i+3;j++)a+=bar[j]=='S';
            if(a!=0 && a!=3)dp[i]=1+dp[i+3];
        }
        for(int i=0;i<len;i++)dp[0]=max(dp[0],dp[i]);
        cout<<len-dp[0]*3<<endl;
    }
    return 0;
}

