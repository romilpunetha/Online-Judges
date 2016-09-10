#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

vector<bool>arr(1e6,0);
vector<int>index(1e6,0);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,c=0,cnt=0,ans=0;cin>>n>>q;
    vector<int>hash[n+1];
    for(int i=0;i<q;i++){
        int type,t;cin>>type>>t;
        if(type==1){
            arr[c]=1;
            hash[t].push_back(c++);
            ans++;
        }
        else if(type==2){
            for(int j=index[t];j<(int)hash[t].size();j++,index[t]++){
                ans-=arr[hash[t][j]];
                arr[hash[t][j]]=0;
            }
        }
        else{
            for(;cnt<t;cnt++){
                ans-=arr[cnt];
                arr[cnt]=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

