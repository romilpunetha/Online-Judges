#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,p,total=1;cin>>n>>p;
    double probability=0.0;
    vector<pair<int,int> >arr(n);
    for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second,total*=arr[i].second-arr[i].first+1;
    for(int i=0;i<n;i++)
    {
        int j=(i+1)%n;
        double ai=arr[i].second/p - (arr[i].first-1)/p;
        double aj=arr[j].second/p - (arr[j].first-1)/p;
        probability+=1- ((arr[i].second - arr[i].first +1.0 -ai)/(arr[i].second - arr[i].first +1.0))*((arr[j].second - arr[j].first +1.0 -aj)/(arr[j].second - arr[j].first +1.0));
    }
    cout<<fixed<<setprecision(10)<<(probability*2000)<<endl;
    return 0;
}

