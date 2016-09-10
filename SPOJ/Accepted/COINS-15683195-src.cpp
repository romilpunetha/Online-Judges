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
#define mp(x,y) make_pair(x,y)
using namespace std;

unsigned long long int max(unsigned long long int a,unsigned long long int b)
{
    return (a>b?a:b);
}

unsigned long long int max_value(unsigned long long int input,map<unsigned long long int,unsigned long long int> &mymap)
{
    if(mymap.find(input)!=mymap.end())
    {
        return mymap[input];
    }
    else
    {
        mymap.insert(mp(input,max(input,max_value(input/2,mymap)+max_value(input/3,mymap)+max_value(input/4,mymap))));
        return mymap[input];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int test=10;
    map<unsigned long long int,unsigned long long int> mymap;
    mymap.insert(mp(0,0));
    mymap.insert(mp(1,1));
    mymap.insert(mp(2,2));
    mymap.insert(mp(3,3));
    mymap.insert(mp(4,4));
    while(test--)
    {
        unsigned long long int input;
        cin>>input;
        cout<<max_value(input,mymap)<<endl;
    }
    return 0;
}
