#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,cnt=0;cin>>a>>b;
    while(a && b && !(a==1 && b==1))
    {
        if(a>b) swap(a,b);
        a++,b-=2;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}

