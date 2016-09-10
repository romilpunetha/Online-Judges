#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;
    for(int t=1;t<=test;t++){
        cout<<"Case #"<<t<<": ";
        ll l,r;cin>>l>>r;
        if(r<l)swap(r,l);
        cout<<((l*(l+1))/2)<<endl;
    }
    return 0;
}

