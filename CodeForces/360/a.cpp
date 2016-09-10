#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n,d;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>d;
    vector<int>arr(d,0);
    for(int i=0;i<d;i++){
        string t;cin>>t;
        int flag=0;
        for(int j=0;j<n;j++){
            if(t[j]=='0') flag=1;
        }
        arr[i]=flag;
    }
    int res=0;
    for(int i=0;i<d;i++){
        if(i && arr[i]) arr[i]+=arr[i-1];
        res=max(res,arr[i]);
    }
    cout<<res<<endl;
    return 0;
}

