#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size;cin>>size;
    vector<ll>arr(size);
    for(int i=0;i<size;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    ll a=0,b=0,c=0,p=0;
    for(int i=0;i<size;i++)
    {
        int k=i+2;
        for(int j=i+1;j<size;j++)
        {
            if(j==k)k++;
            if(k==size)break;
            if(arr[i]+arr[j]>arr[k] && arr[i]+arr[k]>arr[j] && arr[j]+arr[k]>arr[i])
            {
                if(p<=arr[i]+arr[j]+arr[k])
                {
                    p=arr[i]+arr[j]+arr[k];
                    a=i;
                    b=j;
                    c=k;
                }
                k++;
            }
            else continue;
        }
    }
    if(p==0){cout<<-1<<endl;return 0;}
    cout<<arr[a]<<" "<<arr[b]<<" "<<arr[c]<<endl;
    return 0;
}

