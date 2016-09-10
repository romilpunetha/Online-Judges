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

unsigned long long int gcd(unsigned long long int b,unsigned long long int a)
{
    if(b==0)
    {
        return a;
    }
    return gcd(a%b,b);
}


unsigned long long int pollard_rho(unsigned long long int num)
{
    if(num%2==0)
    {
        return 2;
    }
    long long int x=rand()%num;
    if(x==0)
    {
        x++;
    }
    long long int y=x;
    long long int c=rand()%num;
    //cout<<"c = "<<c<<endl;
    if(c==0)
    {
        c++;
    }
    long long int g=1;
    while(g==1)
    {
        x=((x*x)%num + c*c)%num;
        y=((y*y)%num +c*c)%num;
        y=((y*y)%num +c*c)%num;
        g=gcd(abs(x-y),num);
    }
    return g;
}

int main()
{
    ios_base::sync_with_stdio(false);
    unsigned long long int num;
    cin>>num;
    while(num!=0)
    {
        unsigned long long int n=num;
        unsigned long long int result=0;
        while(result!=n && n!=1)
        {
            result=pollard_rho(n);
            cout<<result<<" "<<n<<endl;
            int count=0;
            while(n%result==0)
            {
                n=n/result;
                count++;
            }
            cout<<result<<"^"<<count<<" ";
        }
        cout<<endl;
        cin>>num;
    }
    return 0;
}
