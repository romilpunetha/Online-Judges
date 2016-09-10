#include<iostream>
#include<vector>
#include<list>
#define mp make_pair
using namespace std;

typedef vector<list<pair<int,int> > > graph;

int max_cost=0;
int max(int a,int b)
{
    return a>b?a:b;
}

int find_total_cost(graph &g,vector<int>&visited,vector<int>&relevant,int parent)
{
    if(visited[parent] || !relevant[parent])
    {
        return 0;
    }
    visited[parent]=1;
    int cost=0;
    list<pair<int,int> >::iterator it;
    for(it=g[parent].begin();it!=g[parent].end();it++)
    {
        if(!visited[it->first] && relevant[it->first])
        {
            cost+=(it->second)+find_total_cost(g,visited,relevant,it->first);
        }
    }
    return cost;
}

int find_max_cost_path(graph &g,vector<int>&visited,vector<int>&relevant,int parent)
{
    if(visited[parent] || !relevant[parent])
        return 0;
    visited[parent]=1;
    int max1=0,max2=0,cost=0;
    list<pair<int,int> >::iterator it;
    for(it=g[parent].begin();it!=g[parent].end();it++)
    {
        if(!visited[it->first] && relevant[it->first])
        {
            cost=(it->second)+find_max_cost_path(g,visited,relevant,it->first);
            if(cost>max1)
            {
                max2=max1;
                max1=cost;
            }
            else if(cost>max2)
            {
                max2=cost;
            }
        }
    }
    max_cost=max(max_cost,max1+max2);
    return max1;
}

void find_relevant(graph &g,vector<int>&relevant,vector<int>&visited,int parent)
{
    if(visited[parent])
        return;
    visited[parent]=1;
    list<pair<int,int> >::iterator it;
    for(it=g[parent].begin();it!=g[parent].end();it++)
    {
        if(!visited[it->first])
        {
            find_relevant(g,relevant,visited,it->first);
            if(relevant[it->first])
            {
                relevant[parent]=1;
            }
        }
    }
}

int main()
{
    int N,K;
    cin>>N>>K;
    graph g(N+1);
    vector<int> relevant(N+1,0);
    vector<int> visited(N+1,0);
    vector<int>dest(N+1,0);
    int start;
    for(int i=0;i<K;i++)
    {
        int t;
        cin>>t;
        dest[t]=1;
        relevant[t]=1;
        start=t;
    }
    for(int i=0;i<N-1;i++)
    {
        int p,q,r;
        cin>>p>>q>>r;
        g[p].push_back(mp(q,r));
        g[q].push_back(mp(p,r));
    }
    find_relevant(g,relevant,visited,start);
    vector<int>(N+1,0).swap(visited);
    int cost=find_max_cost_path(g,visited,relevant,start);
    cost=max(max_cost,cost);
    vector<int>(N+1,0).swap(visited);
    int total_cost=find_total_cost(g,visited,relevant,start);
    total_cost= (total_cost-cost)*2 + cost;
    cout<<total_cost<<endl;
    return 0;
}
