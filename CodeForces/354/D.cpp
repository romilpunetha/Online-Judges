#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a,b,c,d;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

typedef struct node
{
    int x,y,f,dist;
    node(int x,int y,int f,int dist)
    {
        this->x=x;
        this->y=y;
        this->f=f;
        this->dist=dist;
    }
    friend bool operator<(const node &a,const node &b){return a.dist>b.dist;}
}node;

bool isvalid(int x,int y)
{
    return (x>=0 && y>=0 && x<n && y<n);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    vector<string>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>a>>b>>c>>d;a--,b--,c--,d--;


    return 0;
}

