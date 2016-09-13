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
    if(cnt<=2)return start;
    else return -1;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    if(n==1)return cout<<-1,0;
    else if(n==2){
        cout<<2<<end;
        int s,t;cin>>s>>t;
        cout<<s-(t-s)<<" "<<t+(t-s);
        return 0;
    }
    arr.resize(n);
    for(auto &it:arr)cin>>it;
    sort(arr.begin(),arr.end());
    int val=util();

    return 0;
}

