#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll test,n,ki;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>test;
    for(int i=1;i<=test;i++){
        cin>>n>>ki;
        vector<ll>arr[4];
        for(int j=0;j<4;j++){
            arr[j].resize(n);
            for(int k=0;k<n;k++){
                cin>>arr[j][k];
            }
        }
        ll res=0;
        for(auto p:arr[0]){
            for(auto q:arr[1]){
                for(auto r:arr[2]){
                    for(auto s:arr[3]){
                        if((p^q^r^s)==ki) res++;
                    }
                }
            }
        }
        cout<<"Case #"<<i<<": "<<res<<endl;
    }
    return 0;
}

