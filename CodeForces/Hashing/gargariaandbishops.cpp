#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,p=1,q=1,r=1,s=2;
ll mx1=0,mx2=0;
ll arr[2010][2010];
unordered_map<ll,ll>mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int t;cin>>t;
            arr[i][j]=t;
            mp[i+j+5000]+=t;
            mp[i-j]+=t;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i+j)%2==0){
                if(mx1<mp[i+j+5000]+mp[i-j]-arr[i][j]){
                    mx1=mp[i+j+5000]+mp[i-j]-arr[i][j];
                    p=i+1;q=j+1;
                }
            }
            else{
                if(mx2<mp[i+j+5000]+mp[i-j]-arr[i][j]){
                    mx2=mp[i+j+5000]+mp[i-j]-arr[i][j];
                    r=i+1;s=j+1;
                }
            }
        }
    }
    cout<<mx1+mx2<<endl<<p<<" "<<q<<" "<<r<<" "<<s<<" "<<endl;
    return 0;
}

