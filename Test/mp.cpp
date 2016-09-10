#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,int>mp;
    mp[0]=0;
    mp[4]=10;
    auto it=mp.upper_bound(4);
    //it--;
    cout<<it->first<<" "<<it->second<<endl;
    cout<<(it==mp.end()?"YES":"NO")<<endl;
    return 0;
}

