#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a,int b)
{
    if(a<b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    while(b)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size,cnt=0;cin>>size;
    vector<int>arr(size);
    vector<int>ans;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
        if(i)
        {
            ans.push_back(arr[i-1]);
            if(gcd(arr[i],arr[i-1])!=1)
            {
                cnt++;
                ans.push_back(1);
            }
        }
    }
    ans.push_back(arr[size-1]);
    cout<<cnt<<endl;
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

