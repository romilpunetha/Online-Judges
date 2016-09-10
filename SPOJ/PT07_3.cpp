#include<iostream>
#include<vector>
#include<list>
using namespace std;

int global_max=0;

int dfs(vector<list<int> > adjacency,int source,vector<int> visited)
{
    int dist=0,max1=0,max2=0,max3=0;
    list<int>::iterator it;
    visited[source]=1;
    if(adjacency[source].empty())
    {
        return 1;
    }
    for(it=adjacency[source].begin();it!=adjacency[source].end();it++)
    {
        if(visited[(*it)]!=1)
        {
            dist=dijkstra(adjacency,(*it),visited,l);
            // visited[(*it)]=0;
            if(dist>=max1)
            {
                max2=max1;
                max1=dist;
            }
            else if(dist>max2)
            {
                max2=dist;
            }
            if(global_max<max1+max2)
            {
                global_max=max1+max2;
            }
            if(max3<dist)
            {
                max3=dist;
            }
        }
    }
    return max3+1;
}
int main()
{
    int n,a,b;
    cin>>n;
    vector<int> v[n+9];
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        v[a].push_back(b-1);
        v[b].push_back(a-1);
    }
    dfs(v,0);
    cout<<global_max<<endl;
}
