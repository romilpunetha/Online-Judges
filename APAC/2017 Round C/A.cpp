#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int R,C,Rs,Cs,S;
double P,Q;
int x[]={0,1,0,-1};
int y[]={1,0,-1,0};

vector<vector<char> >grid(30,vector<char>(30,'.'));
vector<vector<int> >visited(30,vector<int>(30,0));

bool valid(int r,int c){
    return (r>=0 && r<R && c>=0 && c<C);
}

double dfs(int a,int b,int s){
    if(!s) return 0;
    visited[a][b]++;
    double ans=grid[a][b]=='A'?pow(1-P,visited[a][b]-1)*P:pow(1-Q,visited[a][b]-1)*Q;
    double score=0.0;
    for(int i=0;i<4;i++){
        int p=a+x[i];
        int q=b+y[i];
        if(valid(p,q)){
            score=max(score,dfs(p,q,s-1));
        }
    }
    visited[a][b]--;
    return ans+score;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;
    for(int tst=1;tst<=test;tst++){
        cin>>R>>C>>Rs>>Cs>>S>>P>>Q;
        for(int i=0;i<R;i++) for(int j=0;j<C;j++)cin>>grid[i][j],visited[i][j]=0;
        double ans=0.0;
        for(int i=0;i<4;i++){
            int p=Rs+x[i];
            int q=Cs+y[i];
            if(valid(p,q)){
                ans=max(ans,dfs(p,q,S));
            }
        }
        cout<<fixed<<setprecision(10)<<"Case #"<<tst<<": "<<ans<<endl;
    }
    return 0;
}

