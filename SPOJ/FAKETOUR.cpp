#include <algorithm>
#include <limits.h>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <string.h>
#include <string>
#include <unordered_map>
#define pp pair<int,int>
#define pb(x) push_back(x)
using namespace std;
typedef vector<list<int> > graph;
typedef list<int>::iterator ite;

graph transpose(graph &g)
{
    ite it;
    int size=g.size();
    graph grev(size);
    for(int i=1;i<size;i++)
    {
        for(it=g[i].begin();it!=g[i].end();it++)
        {
            grev[*it].pb(i);
        }
    }
    return grev;
}
void dfs(graph &g,int source,vector<bool>&visited,int *count)
{
    //cout<<"source = "<<source<<endl;
    (*count)++;
    visited[source]=true;
    ite i;
    for(i=g[source].begin();i!=g[source].end();i++)
    {
        if(!visited[*i])
        {
            dfs(g,*i,visited,count);
        }
    }
}

void dfs(graph &g,int source,vector<bool>&visited,stack<int>&s)
{
    visited[source]=true;
    ite i;
    for(i=g[source].begin();i!=g[source].end();i++)
    {
        if(!visited[*i])
        {
            dfs(g,*i,visited,s);
        }
    }
    s.push(source);
}

stack<int> strongly_connected_component(graph &g)
{
    stack<int> s;
    int size=g.size();
    vector<bool> visited(size,false);
    for(int i=1;i<size;i++)
    {
        if(!visited[i])
        {
            dfs(g,i,visited,s);
        }
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin>>test;
    while(test--)
    {
        int size;
        cin>>size;
        vector<bool> visited(size+1,false);
        vector<bool> visited1(size+1,false);
        graph g(size+1);
        for(int i=1;i<=size;i++)
        {
            int temp;
            cin>>temp;
            for(int j=0;j<temp;j++)
            {
                int k=0;
                cin>>k;
                g[k].pb(i);
            }
        }
        graph grev=transpose(g);
        stack<int> s=strongly_connected_component(g);
        int count=0;
        dfs(g,s.top(),visited,&count);
        //cout<<"st top = "<<s.top()<<endl;
        //cout<<"count = "<<count<<endl;
        if(count==size)
        {
            count=0;
            dfs(grev,s.top(),visited1,&count);
            cout<<count<<endl;
        }
        else
        {
            cout<<"0"<<endl;
        }
    }
    return 0;
}
