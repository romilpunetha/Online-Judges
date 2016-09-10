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

bool myfun(pair<pair<int,double>,int>a ,pair<pair<int,double>,int>b)
{
    if(a.first.second<b.first.second)
    {
        return true;
    }
    else if(a.first.second==b.first.second)
    {
        if(a.first.first>b.first.first)
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

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin>>test;
    for(int t=1;t<=test;t++)
    {
        int size;
        cin>>size;
        vector<pair<pair<int,double>,int> > result;
        vector<int> sec(size,0);
        vector<double> prob(size,0);
        for(int i=0;i<size;i++)
        {
            cin>>sec[i];
        }
        for(int i=0;i<size;i++)
        {
            cin>>prob[i];
            prob[i]=1-((prob[i]*1.0)/100);
        }
        for(int i=0;i<size;i++)
        {
            result.push_back(make_pair(make_pair(sec[i],prob[i]),i));
        }
        sort(result.begin(),result.end(),myfun);
        cout<<"Case #"<<t<<": ";
        for(int i=0;i<size;i++)
        {
            cout<<result[i].second<<" ";
        }
        cout<<endl;
    }
    return 0;
}
