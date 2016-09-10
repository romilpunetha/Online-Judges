#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    vector<vector<int> >arr(n,vector<int>(n,0));
    int r=n/2,c=0;
    for(int i=1;i<=n*n;i++){
        int a=(r-1+n)%n;
        int b=(c+1)%n;
        if(arr[a][b]==0)arr[a][b]=i,r=a,c=b;
        else arr[(r+1)%n][c]=i,r=(r+1)%n;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

