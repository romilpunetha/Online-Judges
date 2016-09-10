#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i;cin>>n;
    vector<int>arr(n);
    for(i=0;i<n;i++)cin>>arr[i];
    for(i=n-2;i>=0 && arr[i]<arr[i+1];i--);
    cout<<i+1<<endl;
    return 0;
}

