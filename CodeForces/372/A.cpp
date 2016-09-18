#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,c,prev,t,cnt=1;cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>t;
        if(i && t-prev<=c)cnt++;
        else cnt=1;
        prev=t;
    }
    cout<<cnt<<endl;
    return 0;
}

