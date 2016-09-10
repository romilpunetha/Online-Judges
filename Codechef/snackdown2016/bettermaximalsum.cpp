#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;cin>>test;
    while(test--)
    {
        ll n,sum=0,res=0;cin>>n;
        vector<ll>arr(n),pre(n,0),suf(n,0);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            res=max(res,sum);
            pre[i]=sum;
            if(sum<0)sum=0;
        }
        sum=0;
        for(int i=n-1;i>=0;i--)
        {
            sum+=arr[i];
            res=max(res,sum);
            suf[i]=sum;
            if(sum<0)sum=0;
        }
        //for(auto it:pre)cout<<it<<" ";cout<<endl;
        //for(auto it:suf)cout<<it<<" ";cout<<endl;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0)
            {
                res=max(res,(i-1>=0?pre[i-1]:0) + (i+1<n?suf[i+1]:0));
            }
        }
        if(res==0){res=LLONG_MIN;for(auto it:arr)res=max(res,it);}
        cout<<res<<endl;
    }
    return 0;
}

