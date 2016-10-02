#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
ll arr[1010][1010][2],c[1010][1010],d[1010][1010];
int test,n,m;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>test;
    while(test--){
        cin>>n>>m;
        memset(arr,0,sizeof(arr));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(!i || !j)c[i][j]=INT_MAX;
                else cin>>c[i][j];
                arr[i][j][0]=arr[i][j][1]=INT_MAX;
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(!i || !j)d[i][j]=INT_MAX;
                else cin>>d[i][j];
            }
        }
        arr[1][1][0]=arr[1][1][1]=c[1][1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1 && j==1 )continue;
                arr[i][j][0]=min(arr[i][j][0],arr[i-1][j][0]+d[i-1][j]+d[i][j]);
                arr[i][j][0]=min(arr[i][j][0],arr[i-1][j][1]+d[i][j]);
                arr[i][j][0]=min(arr[i][j][0],arr[i][j-1][0]);
                arr[i][j][0]=min(arr[i][j][0],arr[i][j-1][1]+d[i][j-1]);
                arr[i][j][1]=min(arr[i][j][1],arr[i-1][j][0]+d[i-1][j]);
                arr[i][j][1]=min(arr[i][j][1],arr[i-1][j][1]);
                arr[i][j][1]=min(arr[i][j][1],arr[i][j-1][0]+d[i][j]);
                arr[i][j][1]=min(arr[i][j][1],arr[i][j-1][1]+d[i][j-1]+d[i][j]);
                arr[i][j][0]+=c[i][j];
                arr[i][j][1]+=c[i][j];
            }
        }
        cout<<min(arr[n][m][0],arr[n][m][1])<<endl;
    }
    return 0;
}

