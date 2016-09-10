#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll minval=n/m;
    ll maxval=n-m+1;
    minval=((n%m)*(minval*(minval+1))/2) +  (m-(n%m))*(minval*(minval-1))/2;
    maxval=(maxval*(maxval-1))/2;
    cout<<minval<<" "<<maxval<<endl;
    return 0;
}

