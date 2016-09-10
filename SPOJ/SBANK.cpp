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

struct bank
{
    int a;
    long long int b;
    int c;
    int d;
    int e;
    int f;
    string input;
};

bool myfun(struct bank a,struct bank b)
{
    if(a.input.compare(b.input)<0)
    {
        return true;
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
    //cout<<test<<endl;
    while(test--)
    {
        int size;
        cin>>size;
        cin.ignore(INT_MAX, '\n');
        //cin.clear();
        //fflush(stdin);
        vector<struct bank>arr(size);
        for(int i=0;i<size;i++)
        {
            getline(cin,arr[i].input);
            // cout<<arr[i].input<<endl;
        }
        sort(arr.begin(),arr.end(),myfun);
        int count=1;
        for(int i=0;i<size-1;i++)
        {
            if(arr[i].input==arr[i+1].input)
            {
                count++;
            }
            else
            {
                cout<<arr[i].input<<" "<<count<<endl;
                count=1;
            }
        }
        cout<<arr[size-1].input<<" "<<count<<endl;
        cout<<"\n";
    }
    return 0;
}
