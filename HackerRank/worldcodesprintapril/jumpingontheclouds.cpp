
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr(n);
    int count=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i!=n-1;i++)
    {
        //cout<<i<<" ";
        if(i+2<n && !arr[i+2])
        {
            i++;
        }
        count++;
    }
    cout<<count<<endl;
    return 0;
}

