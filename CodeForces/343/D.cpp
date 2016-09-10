#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int len;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>len;
    long double pi=3.14159265359;
    map<ll,ll>mp;
    mp[0]=0;
    for(int i=0;i<len;i++)
    {
        ll r,h;cin>>r>>h;ll vol= r*r*h;
        auto it=mp.lower_bound(vol);
        it--;
        mp[vol]=max(mp[vol],it->second + vol);
        it=mp.upper_bound(vol);
        while(it!=mp.end() && mp[vol]>it->second) it=mp.erase(it);
    }
    cout<<setprecision(18)<<pi*(mp.rbegin()->second)<<endl;
    return 0;
}

