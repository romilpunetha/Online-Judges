#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=1000000007;
vector<vector<ll> >FG(4,vector<ll>(1,0));
unordered_map<ll, pair<ll,ll> > intermediate;
vector<vector<ll> > mul(vector<vector<ll> >&a,vector<vector<ll> >&b,int ilim,int jlim,int klim)
{
    vector<vector<ll> >res(ilim,vector<ll>(jlim,0));
    for(int i=0;i<ilim;i++)
    {
        for(int j=0;j<jlim;j++)
        {
            for(int k=0;k<klim;k++)
            {
                res[i][j]= ((res[i][j])+ (a[i][k] * b[k][j]))%mod;
            }
        }
    }
    return res;
}

vector<vector<ll> > fastexp(vector<vector<ll> >arr,int q)
{
    vector<vector<ll> >res(4,vector<ll>(4,0));
    if(q==0)
        return res;
    for(int i=0;i<4;i++)
    {
        res[i][i]=1;
    }
    while(q)
    {
        if(q&1)
        {
            res=mul(res,arr,4,4,4);
        }
        arr=mul(arr,arr,4,4,4);
        q>>=1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> f(2),g(2);
    f[0]=1;
    f[1]=1;
    g[0]=0;
    g[1]=1;
    int Q;
    cin>>Q;
    FG[0][0]=1;
    FG[1][0]=1;
    FG[2][0]=0;
    FG[3][0]=1;
    vector<vector<ll> >arr(4,vector<ll>(4,0));
    arr[0][0]=1;
    arr[0][1]=1;
    arr[0][2]=2;
    arr[1][0]=1;
    arr[2][3]=1;
    arr[3][0]=1;
    arr[3][3]=1;
    while(Q--)
    {
        int n;
        char a;
        cin>>n>>a;
        n=n%mod;
        if(n==0)
        {
            if(a=='f')
                cout<<f[0]<<endl;
            else
                cout<<g[0]<<endl;
        }
        else if(n==1)
        {
            if(a=='f')
                cout<<f[1]<<endl;
            else
                cout<<g[1]<<endl;
        }
        else
        {
            if(intermediate.find(n-1)!=intermediate.end())
            {
                if(a=='f')
                    cout<<intermediate[n-1].first<<endl;
                else
                    cout<<intermediate[n-1].second<<endl;
                continue;
            }
            vector<vector<ll> >arrnew=fastexp(arr,n-1);
            vector<vector<ll> >result=mul(arrnew,FG,4,1,4);
            switch(a)
            {
                case 'f': cout<<result[0][0]%mod<<endl;
                          break;
                case 'g': cout<<result[3][0]%mod<<endl;
                          break;
            }
            intermediate[n-1].first=result[0][0];
            intermediate[n-1].second=result[3][0];
        }
    }
    return 0;
}

