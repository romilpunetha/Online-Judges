#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int t,k,n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int>arr(n);
        for(auto &it:arr)cin>>it;
        sort(arr.begin(),arr.end());
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int temp=k-1,p=i-1,q=i+1,cost=0;
            while(temp){
                if(p>=0 && q<n){
                    if((arr[i]-arr[p])*3 <=(arr[q]-arr[i])*5) cost+=(arr[i]-arr[p])*3,p--;
                    else cost+=(arr[q]-arr[i])*5,q++;
                }
                else if(p<0)cost+=(arr[q]-arr[i])*5,q++;
                else cost+=(arr[i]-arr[p])*3,p--;
                temp--;
            }
            //whats(cost);
            ans=min(ans,cost);
        }
        cout<<ans<<endl;
    }
    return 0;
}

