#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;while(test--){
        int ans=0,n,m,c;cin>>n>>m>>c;
        int lim=sqrt(c);
        for(int i=1;i<=lim;i++){
            if(c%i==0 && i <= n && c/i <= m)ans++;
            if(c%i==0 && c/i<=n && i<=m && i!=c/i)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

