#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n;
vector<ll>arr;

int util(){
    int cnt=0,start=0;
    for(int i=1;i<n-1;i++){
        if(arr[i+1]-arr[i]!=arr[i]-arr[i-1])cnt++,start=i;
    }
    if(cnt<=1)return start;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    arr.resize(n);
    for(auto &it:arr)cin>>it;
    sort(arr.begin(),arr.end());
    int val=util();
    return 0;
}

