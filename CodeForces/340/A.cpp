#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    int ans=n/5 + (n%5!=0);
    cout<<ans<<endl;
    return 0;
}

