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

using namespace std;
vector<int>color;
int red=0,black=0;
void reduce_degree(map<int,int>&m,vector<list<int> >&g,vector<int>&visited,int key)
{
    visited[key]=1;
    map<int,int>::iterator it2;
    list<int>::iterator it;
    //cout<<"source vertex = "<<key<<endl;
    for(it=g[key].begin();it!=g[key].end();it++)
    {
        if(visited[*it]!=1)
        {
            g[*it].remove(key);
            m[*it]--;
            if(m[*it]==0)
            {
                visited[*it]=1;
                it2=m.find(*it);
                m.erase(it2);
                if(color[*it]==1)
                {
                    red--;
                }
                else
                {
                    black--;
                }
            }
            //cout<<"reduced key "<<*it<<" to value "<<m[*it]<<endl;
        }
    }
}

void colour_graph(vector<list<int> >&g,vector<int>&color)
{
    queue<int>q;
    q.push(1);
    color[1]=1;
    list<int>::iterator it;
    while(!q.empty())
    {
        int source=q.front();
        //cout<<"source = "<<source<<endl;
        q.pop();
        for(it=g[source].begin();it!=g[source].end();it++)
        {
            //cout<<"Adjacent node = "<<*it<<" and its color = "<<color[*it]<<endl;
            if(color[*it]==0)
            {
                if(color[source]==1)
                {
                    color[*it]=2;
                }
                else
                {
                    color[*it]=1;
                }
                q.push(*it);
            }
        }
    }
}

struct greatest
{
    bool operator()(pair<int,int>a,pair<int,int>b)
    {
        if(a.second<b.second)
        {
            return true;
        }
        else if(a.second>b.second)
        {
            return false;
        }
        else if(a.second==b.second && color[a.first]==color[b.first])
        {
            return true;
        }
        else if(a.second==b.second && color[a.first]!=color[b.first])
        {
            if(color[a.first]==1 && red>black)
            {
                return true;
            }
            else if(color[a.first]==2 && black>red)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};


int main()
{
    int cover=0;
    ios_base::sync_with_stdio(false);
    int nodes;
    cin>>nodes;
    vector<int >degree(nodes+1,0);
    vector<int >visited(nodes+1,0);
    vector<list<int> >graph(nodes+1);
    map<int,int> m;
    for(int i=1;i<=nodes-1;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    vector<int>(nodes+1,0).swap(color);
    red=0;
    black=0;
    colour_graph(graph,color);
    for(int i=1;i<=nodes;i++)
    {
        if(color[i]==1)
        {
            red++;
        }
        else
        {
            black++;
        }
    }
    //cout<<"total red = "<<red<<" and total black = "<<black<<endl;
    //cout<<"flag 1"<<endl;
    for(int i=1;i<=nodes;i++)
    {
        m.insert(make_pair(i,degree[i]));
        //cout<<"i = "<<i<<" with degree = "<<degree[i]<<endl;
    }
    //cout<<"flag 2"<<endl;
    while(!m.empty())
    {
        //cout<<" red = "<<red<<" and black = "<<black<<endl;
        //cout<<"key = "<<(m.begin())->first<<" with value = "<<(m.begin())->second<<endl;
        //int dummy;
        //cin>>dummy;
        map<int,int>::iterator it;
        it=max_element(m.begin(),m.end(),greatest());
        if((*it).second==0)
        {
            break;
        }
        cover++;
        int lkey=(*it).first;
        m.erase(lkey);
        if(color[lkey]==1)
        {
            red--;
        }
        else
        {
            black--;
        }
        reduce_degree(m,graph,visited,lkey);
    }
    cout<<cover<<endl;
    return 0;
}
