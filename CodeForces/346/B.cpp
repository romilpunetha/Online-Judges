#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;cin>>n>>m;
    vector<multimap<int,string, greater<int> > >arr(n);
    while(n--)
    {
        string s;int r,score;cin>>s>>r>>score;
        arr[r-1].insert(make_pair(score,s));
    }
    for(int i=0;i<m;i++)
    {
        multimap<int,string>::iterator it=arr[i].begin();
        int s1,s2;string n1,n2;
        s1=it->first,n1=(it++)->second,s2=it->first,n2=(it++)->second;
        if(it==arr[i].end() || (it->first!=s1 && it->first!=s2))
            cout<<n1<<" "<<n2<<endl;
        else
            cout<<'?'<<endl;
    }
    return 0;
}

