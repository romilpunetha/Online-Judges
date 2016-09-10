#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b,ans;cin>>n>>a>>b;
    ans=(((a+b)%n)==0?n:(a+b)%n);
    cout<<(ans<0?n+ans:ans)<<endl;
    return 0;
}

