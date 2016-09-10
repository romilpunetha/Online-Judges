#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    map<int,int>mp;
    for(int i=0;i<n;i++) {
        int temp;cin>>temp;mp[temp]++;
    }
    ll diff=mp.rbegin()->first-mp.begin()->first;
    ll combi=(ll)mp.rbegin()->second * (ll)mp.begin()->second;
    if(mp.size()==1) combi=((ll)mp.rbegin()->second * ((ll)mp.begin()->second -1))/2;
    cout<<diff<<" "<<combi<<endl;
    return 0;
}

