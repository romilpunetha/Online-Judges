// Finding the vertex cover for a n-way tree.
// The approach is greedy.
// We choose the vertex with degree 1. Then focus on its neighbour.
// because to accommodate this vertex, its neighbour must be in the vertex cover.
// We delete this node as well as the neighbour from the map, reduce the degrees of all the nodes connected to the neighbour by 1 and include the neighbour in the vertex covering.
// repeat till no more vertices in the map.
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
void reduce_degree(unordered_map<int,int>& m,vector<list<int> >& g,vector<int>& visited,int key)
{
    visited[key]=1;//marking neighbour of the node as visited
    unordered_map<int,int>::iterator it2;
    list<int>::iterator it;
    //cout<<"source vertex = "<<key<<endl;
    for(it=g[key].begin();it!=g[key].end();it++)
    {
        g[*it].remove(key);//removing the node from the adjacency list of its neighbours,ie, when i delete the node 'key' from the graph, no node should have this 'key' node in its adjacency list. so im traversing the adjacency list of the 'key' node and deleting the key node from the list of its neighbours.
        if(visited[*it]==0)
        {
            m[*it]--;//reducing the degree of the neighbours by 1
            if(m[*it]==0)//if the degree becomes 0, that means the node im deleting ,ie, key node, will account for the edge of this node to be deleted. Hence i dont need this node with degree 0 in my map as my map must contain nodes with degree>=1 at all times.
            {
                visited[*it]=1;
                m.erase(*it);//deleting the node with degree 0 from the map
            }
            //cout<<"reduced key "<<*it<<" to value "<<m[*it]<<endl;
        }
    }
}


struct least
{
    bool operator()(pair<int,int>a,pair<int,int>b)
    {
        return a.second<b.second;
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
    unordered_map<int,int> m;
    //Creating the graph
    for(int i=1;i<=nodes-1;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    //Inserting all edges of the graph into the map. map key=vertex name. value= degree of the vertex.
    for(int i=1;i<=nodes;i++)
    {
        m.insert(make_pair(i,degree[i]));
    }
    //while there is a node in the map
    while(!m.empty())
    {
        unordered_map<int,int>::iterator it;
        it=min_element(m.begin(),m.end(),least());//fetch the element with degree 1 from the map
        //cout<<"node = "<<(*it).first<<" and visited = "<<visited[(*it).first]<<endl;
        if(visited[(*it).first]==0)
        {
            visited[(*it).first]=1;
            int lkey=*(graph[(*it).first].begin());//since it is of degree 1, it'll have only 1 neighbour, found at the beginning of the adjacency list.
            m.erase(it);//delete the node
            m.erase(lkey);//delete its neighbour
            reduce_degree(m,graph,visited,lkey);//reduce the degree of the adjacent nodes of the neighbour by 1.
            //cout<<"visited of source = "<<visited[lkey]<<endl;
            cover++;//can use an array here to keep track of the nodes included in the vertex cover. I'm only keeping track of the count.
        }
        else
        {
            m.erase(it);//deleting the node incase its already been visited
        }
    }
    cout<<cover<<endl;
    return 0;
}

