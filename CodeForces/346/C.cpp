#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,cost;cin>>n>>cost;
    unordered_set<int>s;
    for(int i=0;i<n;i++){int temp;cin>>temp;s.insert(temp);}
    int curr=0,cnt=0,i=1;
    vector<int>ans;
    while(curr<=cost)
    {
        if(s.find(i)==s.end()){ans.push_back(i);cnt++;curr+=i;}
        i++;
    }
    int len=ans.size()-1;
    cout<<cnt-1<<endl;
    for(int i=0;i<len;i++) cout<<ans[i]<<" ";
    return 0;
}

