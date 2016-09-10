#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll r,p,g,b,ans=0,k;cin>>r>>p>>g>>b;
    ll net=g-b;
    if(p<=net)
    {
        ans=r/p;
        r=r%p;
    }
    if(r>=g)
    {
        k=((r-g)/net)+1;
        ans+=k;
        r=r-k*net;
    }
    ans+=r/p;
    cout<<ans<<endl;
    return 0;
}

