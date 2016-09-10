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

unsigned long long int modular_pow(unsigned long long int base,unsigned long long int power,unsigned long long int mod)
{
    if(mod==1)
    {
        return 0;
    }
    unsigned res=1;
    base=base%mod;
    while(power>0)
    {
        if(power%2==1)
        {
            res=(res*base)%mod;
        }
        power>>=1;
        base=(base*base)%mod;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    unsigned long long int n;
    cin>>n;
    unsigned long long int p;
    cin>>p;
    cout<<modular_pow(2,n-1,p)<<endl;
    return 0;
}
