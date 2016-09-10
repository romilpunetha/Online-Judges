#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pair<ll,ll>a,b,c;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
    unordered_multimap<ll,pair<ll,ll> >mx,my;
    mx.insert({a.x,a});
    mx.insert({b.x,b});
    mx.insert({c.x,c});
    my.insert({a.y,a});
    my.insert({b.y,b});
    my.insert({c.y,c});
    if(mx.count(a.x)==3 || my.count(a.y)==3){cout<<1<<endl;return 0;}
    if(mx.count(a.x)==2 || mx.count(b.x)==2 || my.count(a.y)==2 || my.count(b.y)==2)
    {
        if(mx.count(a.x)==2)
        {
            auto it=mx.find(a.x);
            pair<ll,ll>p=it++->second,q=it->second;
            if(p.y>q.y) swap(p,q);
            if(q==b || p==b)
            {
                cout<<((c.y>p.y && c.y<q.y)?"3":"2")<<endl;
            }
            else
            {
                cout<<((b.y>p.y && b.y<q.y)?"3":"2")<<endl;
            }
            return 0;
        }
        else if(mx.count(b.x)==2)
        {
            auto it=mx.find(b.x);
            pair<ll,ll>p=it++->second,q=it->second;
            if(p.y>q.y) swap(p,q);
            cout<<((a.y>p.y && a.y<q.y)?"3":"2")<<endl;
            return 0;
        }
        if(my.count(a.y)==2)
        {
            auto it=my.find(a.y);
            pair<ll,ll>p=it++->second,q=it->second;
            if(p.x>q.x) swap(p,q);
            if(q==b || p==b)
            {
                cout<<((c.x>p.x && c.x<q.x)?"3":"2")<<endl;
            }
            else
            {
                cout<<((b.x>p.x && b.x<q.x)?"3":"2")<<endl;
            }
            return 0;
        }
        else
        {
            auto it=my.find(b.y);
            pair<ll,ll>p=it++->second,q=it->second;
            if(p.x>q.x) swap(p,q);
            cout<<((a.x>p.x && a.x<q.x)?"3":"2")<<endl;
            return 0;
        }
    }
    cout<<3<<endl;
    return 0;
}
