#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double n,sum=0.0;cin>>n;
    for(int i=0;i<n;i++){ double t;cin>>t; sum+= t/100.0;}
    cout<<fixed<<setprecision(15)<<(sum/n)*100<<endl;
    return 0;
}

