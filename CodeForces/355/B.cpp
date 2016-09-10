#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k,h,x,sec=0,rem=0;cin>>n>>h>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x+rem>h) sec++,rem=0;
        x+=rem;
        sec+=x/k;
        rem=x%k;
    }
    if(rem) sec++;
    cout<<sec<<endl;
    return 0;
}

