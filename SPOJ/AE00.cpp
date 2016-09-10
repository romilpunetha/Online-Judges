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

long long int no_of_divisors(int num)
{
    if(num==1 || num==2 || num==3)
    {
        return 1;
    }
    long long int count=0;
    for(int i=1;i<=sqrt(num);i++)
    {
        if(num%i==0)
        {
            count+=1;
        }
    }
    //cout<<"count for "<<num<<" is "<<count<<endl;
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int num;
    cin>>num;
    long long int count=0;
    for(int i=1;i<=num;i++)
    {
        count+=no_of_divisors(i);
    }
    cout<<count<<endl;
    return 0;
}
