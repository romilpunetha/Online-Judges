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
    vector<int> sieve(100000,1);
    sieve[0]=0;
    sieve[1]=0;
    sieve[2]=1;
    for(int i=2;i<100000;i++)
    {
        if(sieve[i]==1)
        {
            long long int j=i;
            while(i*j<100000)
            {
                sieve[i*j]=0;
                j++;
            }
        }
    }
    vector<int>sieve2;

    while(test--)
    {
        long long int m,n;
        cin>>m>>n;
        vector<int>(n-m+1,1).swap(sieve2);
        //int *sieve2=new int[n-m+1];
        for(long long int i=0;i*i<=n;i++)
        {
            if(sieve[i]==1)
            {
                long long int j=m/i;
                if(j*i<m)
                {
                    j++;
                }
                while(i*j<=n)
                {
                    sieve2[(j*i)-m]=0;
                    j++;
                }
            }
        }
        long long int t=m;
        while(m<=n && m<100000)
        {
            if(sieve[m]==1)
            {
                cout<<m<<endl;
            }
            m++;
        }
        while(m<=n)
        {
            if(sieve2[m-t]==1)
            {
                cout<<m<<endl;
            }
            m++;
        }
        cout<<endl;

    }
    return 0;
}
