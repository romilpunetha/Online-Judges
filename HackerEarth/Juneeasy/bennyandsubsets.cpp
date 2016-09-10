#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> gauss(vector<vector<int> >&arr,int n){
    vector<int>x(n,0);
    for(int i=0;i<n;i++){
        if(!arr[i][i]){
            for(int j=i+1;j<n;j++){
                if(!arr[j][i]){
                    for(int k=0;k<n;k++){
                        swap(arr[i][k],arr[j][k]);
                    }
                    swap(x[i],x[j]);
                    break;
                }
            }
        }
        for(int j=0;j<n;j++){
            if(j!=i){
                if(arr[i][j]){
                    int m=0;
                    for(m=i;m<n;m++){
                        arr[j][m]^=arr[i][m];
                    }
                    x[j]^=x[i];
                }
            }
        }
    }
    for(auto it:x) cout<<it<<" ";cout<<endl;
    return x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;cin>>n>>x;
    int mod=10000007;
    vector<vector<int> >arr(20,vector<int>(n+1,0));
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        for(int j=19;j>=0;j--){
            arr[j][i]=temp&1;temp>>=1;
        }
    }
    for(int j=19;j>=0;j--){ arr[j][n]=x&1;x>>=1; }
    vector<int> ans=gauss(arr,n);
    return 0;
}

