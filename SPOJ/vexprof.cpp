#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;cin>>test;
    while(test--){
        map<int,int>mp;
        int n,k;cin>>n>>k;
        for(int i=0;i<n;i++){
            int temp;cin>>temp;
            mp[temp]++;
        }
        int temp=0,prev=0,cnt=0,time=0;
        for(auto &it:mp){
            if(cnt<k){
                cnt+=it.second;
                time+=((it.first-prev)*temp);
                prev=it.first;
                temp+=it.second;
            }
            else temp=cnt=it.second,prev=it.first;
        }
        cout<<time<<endl;
    }
    return 0;
}

