#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,p;cin>>t;p=t;
    ll num=3,base=1,cnt=0;
    while(p>0) cnt++,p-=num,num<<=1;
    num=3;
    while(cnt>1) cnt--,base+=num,num<<=1;
    cout<<(num-t+base)<<endl;
    return 0;
}

