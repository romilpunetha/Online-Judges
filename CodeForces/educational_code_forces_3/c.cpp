#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    vector<int>arr(n);
    ll sum=0,ans=0;
    for(auto &it:arr)cin>>it,sum+=it;
    sort(arr.begin(),arr.end());
    int t2=sum%n,t1=n-t2;
    int a=ceil((double)sum*1.0/n);
    int b=floor((double)1.0*sum/n);
    for(int i=0;i<t1;i++)ans+=abs(arr[i]-b);
    for(int i=t1;i<n;i++)ans+=abs(arr[i]-a);
    cout<<ans/2<<endl;
    return 0;
}

