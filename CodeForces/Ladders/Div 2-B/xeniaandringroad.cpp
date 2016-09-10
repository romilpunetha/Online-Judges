#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll houses,len;
    cin>>houses>>len;
    ll temp=0,curr=0;
    ll t=0;
    for(ll i=0;i<len;i++)
    {
        cin>>temp;
        temp--;
        if(i==0)
        {
            curr=temp;
            t=temp;
            continue;
        }
        if(temp>=curr)
        {
            t+=temp-curr;
        }
        else
        {
            t+=houses-(curr-temp);
        }
        curr=temp;
    }
    cout<<t<<endl;
    return 0;
}

