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

long long int combination(int num)
{
    long long int res=((num*(num-1))/2)%1000000007;
    return res;
}


void color(vector<list<int> >&g,int source,int &odd,int &even,int size)
{
    vector<int> visited(size+1,0);
    visited[source]=1;
    queue<int>q;
    int toggle=1;
    list<int>::iterator it;
    q.push(-1);
    q.push(source);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(u==-1)
        {
            if(q.front()==-1)
            {
                break;
            }
            q.push(-1);
            toggle=(toggle+1)%2;
        }
        else
        {
            if(toggle==0)
            {
                odd++;
            }
            else
            {
                even++;
            }
            for(it=g[u].begin();it!=g[u].end();it++)
            {
                if(!visited[*it])
                {
                    visited[*it]=1;
                    q.push(*it);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        vector<list<int> >g(n+1);
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int odd=0,even=0;
        color(g,1,odd,even,n);
        long long int res=(combination(odd)+combination(even))%1000000007;
        cout<<res<<endl;
    }
    return 0;
}
