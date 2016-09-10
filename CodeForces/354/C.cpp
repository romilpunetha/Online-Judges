#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,cnt=0,mx=0;cin>>n>>k;
    string s;cin>>s;
    vector<int>arr(n,0);
    int start=0,end=-1;
    while(start<n)
    {
        while(cnt<=k && end<n) cnt+=s[++end]=='b';
        mx=max(mx,end-start);
        cnt-=s[start++]=='b';
    }
    start=0,end=-1,cnt=0;
    while(start<n)
    {
        while(cnt<=k && end<n) cnt+=s[++end]=='a';
        mx=max(mx,end-start);
        cnt-=s[start++]=='a';
    }
    cout<<mx<<endl;
    return 0;
}

