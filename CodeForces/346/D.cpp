#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isdanger(int d1,int d2)
{
    return (d2-d1==1 || d2-d1==-3);
}

int getdir(int x1,int y1,int x2,int y2)
{
    if(x1==x2) return y2>y1?1:3;
    if(y1==y2) return x2>x1?2:4;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<pair<int,int> >arr(n+1);
    for(int i=0;i<=n;i++){int a,b;cin>>a>>b;arr[i]=make_pair(a,b);}
    int curr_dir,prev_dir=1,cnt=0;
    for(int i=2;i<=n;i++)
    {
        curr_dir=getdir(arr[i-1].first,arr[i-1].second,arr[i].first,arr[i].second);
        cnt+=isdanger(curr_dir,prev_dir)?1:0;
        prev_dir=curr_dir;
    }
    cout<<cnt<<endl;
    return 0;
}

