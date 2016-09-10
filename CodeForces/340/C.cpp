#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll> >d;
ll n,xa,ya,xb,yb;
ll distance(ll x1,ll y1,ll x2,ll y2)
{
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>xa>>ya>>xb>>yb;
    d.resize(n);
    for(int i=0;i<n;i++)
    {
        ll p,q;
        cin>>p>>q;
        d[i].first=distance(xa,ya,p,q);
        d[i].second=distance(xb,yb,p,q);
    }
    sort(d.begin(),d.end());
    d.push_back({LLONG_MAX,0});
    for(int i=n-1;i>=0;i--) d[i].second=max(d[i].second,d[i+1].second);
    ll res=min(d[n-1].first,d[0].second);
    for(int i=0;i<n;i++)
    {
        res=min(res,d[i].first+d[i+1].second);
    }
    cout<<res<<endl;
    return 0;
}

