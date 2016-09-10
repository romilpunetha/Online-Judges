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

int totient(int num)
{
    int result=num;
    // cout<<num<<" = ";
    for(int i=2;i*i<=num;i++)
    {
        if(num%i==0)
        {
            while(num%i==0)
            {
                num=num/i;
            }
            result=result- result/i;
        }
    }
    if(num>1)
    {
        result=result-result/num;
    }
    return (int)(result);

}


int main()
{
    //vector<int>sieve(1000001,1);
    //sieve[0]=0;
    //sieve[1]=0;
    //for(int i=2;i<1000001;i++)
    //{
    //if(sieve[i]==1)
    //{
    //long long int j=i;
    //while(i*j<=1000000)
    //{
    //sieve[i*j]=0;
    //j++;
    //}
    //}
    //}
    int test;
    cin>>test;
    while(test--)
    {
        int num;
        cin>>num;
        if(num==1)
        {
            cout<<"1"<<endl;
        }
        else
        {
            cout<<totient(num)<<endl;
        }

    }
    return 0;
}
