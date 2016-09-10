#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;
    for(int t=1;t<=test;t++){
        int flip=0,ans=0;
        ll n,num=2;cin>>n;
        while((num<<1) <= n)num<<=1;
        while(n>1){
            if(n>=num)n=num-(n-num),flip^=1;
            num>>=1;
        }
        ans=flip?1:0;
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
    return 0;
}

