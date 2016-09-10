#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<char,int>mp;
map<int,int>mp2;
map<pair<int,int>,int>dp;
int util(int k,auto start,auto end)
{
    if(end->first-start->first<=k) return 0;
    if((mp2.upper_bound(start->first))->first==end->first) return 999999;
    if(dp.find({start->first,end->first})!=dp.end()) return dp[{start->first,end->first}];
    int res1=start->second + util(k,++start,end);
    int res2=end->second + util(k,--start,++end);
    end--;
    return dp[{start->first,end->first}]=min(res1,res2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;cin>>test;
    while(test--)
    {
        mp.clear();
        mp2.clear();
        dp.clear();
        string s;cin>>s;
        int k;cin>>k;
        int len=s.length();
        for(int i=0;i<len;i++){mp[s[i]]++;}
        for(auto &it:mp) mp2[it.second]++;
        auto start=mp2.begin();auto end=mp2.rbegin();
        int cnt=0;
        cnt=util(k,start,end);
        cout<<cnt<<endl;
    }
    return 0;
}

