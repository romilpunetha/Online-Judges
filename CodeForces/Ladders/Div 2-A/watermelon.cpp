#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w;
    cin>>w;
    int flag=0;
    for(int i=1;i<=w;i++)
    {
        if(i%2==0 && w-i>0 && (w-i)%2==0)
        {
            flag=1;
            break;
        }
    }
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

