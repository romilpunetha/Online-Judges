#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int len,ans=0;cin>>len;
    vector<int>M(366,0),F(366,0);
    for(int i=0;i<len;i++)
    {
        char c;cin>>c;int s,e;cin>>s>>e;
        M[s-1]+=c=='M'?1:0;
        if(e!=366) M[e]+=c=='M'?-1:0;
        F[s-1]+=c=='F'?1:0;
        if(e!=366) F[e]+=c=='F'?-1:0;
    }
    for(int i=0;i<366;i++) if(i) M[i]+=M[i-1],F[i]+=F[i-1];
    for(int i=0;i<366;i++){ans=max(ans,min(F[i],M[i]));}
    cout<<ans*2<<endl;
    return 0;
}

