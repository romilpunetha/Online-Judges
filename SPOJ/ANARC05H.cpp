#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int> >dp;

int util(int pos,int psum,int len,string &s)
{
    if(pos==len)return 1;
    if(dp[pos][psum]!=-1) return dp[pos][psum];

    int sum=0,cnt=0;
    for(int i=pos;i<len;i++)
    {
        sum+=s[i]-'0';
        if(sum>=psum)
            cnt+=util(i+1,sum,len,s);
    }
    return dp[pos][psum]=cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int i=1;
    cin>>s;
    while(s!="bye")
    {
        int len=s.length();
        dp.clear();
        dp=vector<vector<int> >(len,vector<int>(500,-1));
        int res=util(0,0,len,s);
        cout<<i++<<". "<<res<<endl;
        cin>>s;
    }
    return 0;
}

