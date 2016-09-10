#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,ans=0;cin>>n;
    map<int,int>mp;
    for(int i=0;i<n;i++){int a,b;cin>>a>>b;ans+=mp[a-b]++ + mp[a+b+(2*n)]++;}
    cout<<ans<<endl;
    return 0;
}

