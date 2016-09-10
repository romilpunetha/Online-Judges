#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;cin>>s>>t;
    auto start=s.find(t);
    int ans=0;
    while( (start=s.find(t,start))!=string::npos ) ans++,start+=t.length();
    cout<<ans<<endl;
    return 0;
}

