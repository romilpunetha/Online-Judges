#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int start=0,i=0,mn=INT_MAX,p=0,sum=0;
    while(i<n){
        while(i<n && i-start<k) sum+=arr[i++];
        mn=min(mn,sum);
        p=mn==sum?start:p;
        sum-=arr[start++];
    }
    cout<<p+1<<endl;
    return 0;
}

