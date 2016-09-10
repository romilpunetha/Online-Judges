#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ispossible(int n,int sum)
{
    return (sum>=0 && sum<=(9*n));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,sum;
    cin>>n>>sum;
    int sum1=sum;
    if(!ispossible(n,sum) || (sum==0 && n>1))
    {
        cout<<-1<<" "<<-1<<endl;
        return 0;
    }
    string mn="";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<10;j++)
        {
            if((i>0 || j>0 || (n==1 && j==0)) && ispossible(n-i-1,sum-j))
            {
                mn=mn+(char)('0'+j);
                sum-=j;
                break;
            }
        }
    }
    cout<<mn<<" ";
    string mx="";
    for(int i=0;i<n;i++)
    {
        for(int j=9;j>=0;j--)
        {
            if(ispossible(n-i-1,sum1-j))
            {
                mx=mx+(char)('0'+j);
                sum1-=j;
                break;
            }
        }
    }
    cout<<mx<<endl;
    return 0;
}

