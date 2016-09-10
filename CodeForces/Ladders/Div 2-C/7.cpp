#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int> >arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;cin>>n>>m;
    n=m=min(n,m);
    int i=n,j=0;
    while(i>=0 && j<=m) arr.push_back({i--,j++});
    cout<<n+1<<endl;
    for(auto &&it:arr) cout<<it.first<<" "<<it.second<<endl;
    return 0;
}

