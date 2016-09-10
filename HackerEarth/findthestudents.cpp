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

int main()
{
    ios_base::sync_with_stdio(false);
    int size;
    cin>>size;
    vector<int>arr(size,0);
    int min=INT_MAX;
    int count=0;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    while(1)
    {
        count=0;int flag=1;
        for(int i=0;i<size;i++)
        {
            if(arr[i]!=0)
            {
                arr[i]-=min;
                count++;
                flag=0;
            }
        }
        min=INT_MAX;
        for(int i=0;i<size;i++)
        {
            if(arr[i]!=0 && arr[i]<min)
            {
                min=arr[i];
            }
        }
        if(flag==1)
        {
            break;
        }
        cout<<count<<endl;
    }
    return 0;
}
