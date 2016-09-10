#include<iostream>
#include<vector>
#include<list>
using namespace std;

int total=0;
int dfs(vector<vector<int> >v,int root,vector<int> visited)
{
    int m,m1=-1,m2=-1;
    visited[root]=1;
    for(int i=0;i<v[root].size();i++)
    {
        if(visited[v[root][i]]!=1){
            m = dfs(v,v[root][i],visited);
            if(m>=m1)
            {
                m2= m1;
                m1 = m;
            }
            else if(m>m2)
                m2=m;
        }
    }
    total = max(total , m1+m2+2);
    return (m1 + 1);
}
int main()
{
    int result=0;
    int n=0;
    cin>>n;
    if(n==0)
    {
        cout<<"0"<<endl;
    }
    else
    {
        vector<vector<int> > adjacency(n+5);
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            if(u>n || v>n)
            {
                result=-1;
            }
            else
            {
                adjacency[u-1].push_back(v-1);
                adjacency[v-1].push_back(u-1);
            }
        }
        if(result==-1)
        {
            cout<<"0"<<endl;
        }
        else
        {
            vector<int> visited(n,-1);
            //        visited[0]=1;
            result= dfs(adjacency,n-1,visited);
            result--;
            if(result<total)
            {
                result=total;
            }
            cout<<result<<endl;
        }
    }
    return 0;
}
