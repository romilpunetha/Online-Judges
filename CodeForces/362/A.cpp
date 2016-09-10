#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,s,x;cin>>t>>s>>x;
    if(x<t){cout<<"NO"<<endl;return 0;}
    if(x==t){cout<<"YES"<<endl;return 0;}
    if(s==0){
        if(x==t || x==t+1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return 0;
    }
    int p= (x-t)/s;
    if(p && (x== t+s*p || x==t+1+s*p))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

