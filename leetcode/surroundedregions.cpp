#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int x[4]={0,-1,0,1};
int y[4]={-1,0,1,0};
int m=0,n=0;
vector< vector<int> >visited;

bool isValid(int i,int j){
    return (i>=0 && i<m && j>=0 && j<n);
}
void update(vector< vector<char> >&a,int i,int j){
    queue<pair<int,int> >qu;
    qu.push({i,j});
    a[i][j]='X';
    while(!qu.empty()){
        i=qu.front().ff;
        j=qu.front().ss;
        qu.pop();
        for(int k=0;k<4;k++){
            int p=i+x[k];
            int q=j+y[k];
            if(isValid(p,q) && a[p][q]=='O'){
                qu.push({p,q});
                a[p][q]='X';
            }
        }
    }
}

bool bfs(vector< vector<char> >&a,int i,int j){
    int flag=isValid(i,j);
    queue<pair<int,int> >qu;
    qu.push({i,j});
    visited[i][j]=1;
    while(!qu.empty()){
        i=qu.front().ff;
        j=qu.front().ss;
        qu.pop();
        for(int k=0;k<4;k++){
            int p=i+x[k];
            int q=j+y[k];
            flag=flag & isValid(p,q);
            if(isValid(p,q) && !visited[p][q] && a[p][q]=='O'){
                visited[p][q]=1;
                qu.push({p,q});
            }
        }
    }
    return flag;
}

void solve(vector<vector<char> > &a) {
    if(!m)return ;
    visited.resize(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && a[i][j]=='O'){
                if(bfs(a,i,j)) update(a,i,j);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s;cin>>s;
    int i=0,j=0,k=0;
    vector<vector<char> >arr(2000,vector<char>(2000));
    while(s[k]){
        if(s[k]!=',' && s[k]!='O' && s[k]!='X'){k++;continue;}
        if(s[k]==','){i++,j=0,k++;continue;}
        arr[i][j++]=s[k++];
        n=max(n,j);
    }
    m=i+1;
    solve(arr);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

