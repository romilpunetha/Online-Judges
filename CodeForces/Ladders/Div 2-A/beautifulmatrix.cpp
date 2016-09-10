#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p=0,q=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            int temp;
            cin>>temp;
            if(temp)
            {
                p=i;
                q=j;
                break;
            }
        }
    }
    cout<<abs(2-p)+abs(2-q)<<endl;
    return 0;
}

