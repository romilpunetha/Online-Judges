#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size;
    cin>>size;
    vector<int>arr(size);
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    unordered_map<int,int>m1,m2;
    m1.reserve(1000100);
    m2.reserve(1000100);
    for(auto i:arr)
    {
        for(auto j:arr)
        {
            for(auto k:arr)
            {
                m1[i*j+k]++;
                if(i)
                    m2[i*(j+k)]++;
            }
        }
    }
    int ans=0;
    for(auto it:m1)
    {
        auto jt=m2.find(it.first);
        if(jt!=m2.end())
        {
            ans=ans+(it.second)*(jt->second);
        }
    }
    cout<<ans<<endl;
    return 0;
}

