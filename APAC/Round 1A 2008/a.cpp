#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int test=1;test<=t;test++){
        cout<<"Case #"<<test<<": ";
        int n;cin>>n;
        vector<ll>a(n),b(n);
        for(auto &it:a)cin>>it;
        for(auto &it:b)cin>>it;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=a[n-i-1]*b[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}

