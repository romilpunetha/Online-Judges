#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    ll k=1;
    for(int i=0;i<n;i++){
        arr[i]=(arr[i]>=k?k++:arr[i]);
    }
    cout<<k<<endl;
    return 0;
}
