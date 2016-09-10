#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll n,m,xm,pr=1,ans=0,ht;
vector<ll>h(1e6+10,0);

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>h[i];
    cin>>m;
    vector<int>mm(m);
    for(int i=0;i<m;i++)cin>>mm[i];
    sort(mm.begin(),mm.end());
    for(int i=0;i<m;i++){
        xm=mm[i];
        ht=1;
        for(int j=xm-1;j>=pr;j--){
            h[j]=h[j]<ht?h[j]:ht;
            ht++;
        }
        pr=xm;
    }
    for(int i=1;i<=n;i++)ans+=h[i];
    cout<<ans<<endl;
    return 0;
}

