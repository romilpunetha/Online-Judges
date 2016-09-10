#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,ans=0,cnt=0;cin>>n;
    map<ll,ll>x,y;
    map<pair<ll,ll> ,ll>xy;
    set<pair<ll,ll> >st;
    for(int i=0;i<n;i++)
    {
        ll a,b;cin>>a>>b;x[a]++,y[b]++;
        st.insert(make_pair(a,b));
        xy[make_pair(a,b)]++;
    }
    for(auto it:xy) cnt+=(it.second * (it.second-1))/2;
    for(auto it:x) ans+=(it.second * (it.second-1))/2;
    for(auto it:y) ans+=(it.second * (it.second-1))/2;
    cout<<ans-cnt<<endl;
    return 0;
}

