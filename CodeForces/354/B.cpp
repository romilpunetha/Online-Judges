#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,sec,res=0;cin>>n>>sec;
    vector<vector<double> >arr(n+1,vector<double>(n+1,0.0));
    arr[0][0]=sec;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(arr[i][j]>=1)
            {
                arr[i+1][j]+= (arr[i][j]-1.0)/2;
                arr[i+1][j+1]+= (arr[i][j]-1.0)/2;
                res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}

