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

unsigned long long int fact(int a,vector<unsigned long long int>&fac)
{
    if(a==1)
    {
        return 1;
    }
    if(fac[a]!=0)
    {
        return fac[a];
    }
    else
    {
        fac[a]=(a * (fact(a-1,fac)%1000000007))%1000000007;
        return fac[a];
    }
    //unsigned long long int res=1;
    //for(int i=1;i<=a;i++)
    //{
    //res=(res*i)%1000000007;
    //}
    //return res;
}


unsigned long long int powe(unsigned long long int num,unsigned long long int a)
{
    if(a==0)
    {
        return 1;
    }
    if(a==1)
    {
        return num%1000000007;
    }
    if(a%2==0)
    {
        return (powe((num*num)%1000000007,a/2))%1000000007;
    }
    else
    {
        return ((num%1000000007)*(powe((num*num)%1000000007,a/2)%1000000007))%1000000007;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin>>test;
    vector<unsigned long long int>fac(1000010,0);
    fac[1]=1;
    while(test--)
    {
        int k,n;
        cin>>n>>k;
        unsigned long long int res=1;
        if(n==1)
        {
            res=powe(24,k);
        }
        else
        {
            res=powe(8,k);
        }
        res=res*fact(k,fac);
        res=res%1000000007;
        cout<<res<<endl;
    }
    return 0;
}
