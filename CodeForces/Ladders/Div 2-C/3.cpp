#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    if(n>m+1 || n<(m-1)/2)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(n>=m)
    {
        while(m)
        {
            cout<<"01",m--,n--;
        }
        while(n)
        {
            cout<<0,n--;
        }
        cout<<endl;
    }
    else
    {
        while(m-n>1 && n)
        {
            cout<<"110",m-=2,n--;
        }
        while(n)
        {
            cout<<"10",m--,n--;
        }
        while(m)
        {
            cout<<"1",m--;
        }
        cout<<endl;
    }
    return 0;
}

