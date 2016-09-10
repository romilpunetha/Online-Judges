#include <algorithm>
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

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int size;
        cin>>size;
        vector<int>arr;
        vector<int>(size,0).swap(arr);
        long long int sum=0;
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
        int max=arr[size-1];
        for(int i=size-1;i>=0;i--)
        {
            if(arr[i]<=max)
            {
                 sum+=max-arr[i];
            }
            else
            {
                max=arr[i];
            }
        }
        cout<<sum<<endl;
        sum=0;
    }
    return 0;
}
