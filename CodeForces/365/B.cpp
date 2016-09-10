#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll n,k,p1=0,p2=0,tmp=0;
vector<ll>arr;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    arr.resize(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];p1+=(arr[i]*arr[(i-1+n)%n]);
        p2+=arr[i];
    }
    p1+=(arr[n-1]*arr[0]);
    unordered_set<int>st;
    for(int i=0;i<k;i++){
        int t;cin>>t;t--;
        p1+=(arr[t]*(p2-arr[t]-tmp));
        whats(p1);
        tmp+=arr[t];
        if(st.find((t+1)%n)==st.end()) p1-=(arr[t]*arr[(t+1)%n]);
        if(st.find((t-1+n)%n)==st.end()) p1-=(arr[t]*arr[(t-1+n)%n]);
        st.insert(t);
    }
    cout<<p1<<endl;
    return 0;
}

