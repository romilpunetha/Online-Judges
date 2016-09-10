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
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define FOR(i,x,y) for(long long int i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(long long int i = (y) ; i >= (x) ; --i)
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define ALL(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define ABS(x) ((x)<0?-(x):(x))

using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef pair<string,int> psi;
typedef pair<int,string> pis;
typedef vector<pii> vii;
typedef vector<int> vi;

const ll inf = 2147383647;

long long int power(long long int num,long long int a)
{
    long long int res=0;
    while(a)
    {
        if(a&1)
        {
            res=res*num;
        }
        num=num*num;
        a>>=1;
    }
    return res;
}

long long int bigmod(long long int num,long long int a,long long int mod)
{
    long long int res=0;
    while(a)
    {
        if(a&1)
        {
            res=(res*num)%mod;
        }
        num=(num*num)%mod;
        a>>=1;
    }
    return res;
}


long long int gcd(long long int a,long long int b,long long int &X,long long int &Y)
{
    long long int x=1,y=0;
    X=0;Y=1;
    long long int q,r,m,n;
    while(a!=0)
    {
        q=b/a;
        r=b%a;
        m=X-q*x;
        n=Y-q*y;
        X=x;
        Y=y;
        x=m;
        y=n;
        b=a;
        a=r;
    }
    return b;
}

long long int modinv(long long int a,long long int b)
{
    long long int x=0,y=0;
    gcd(a,b,x,y);
    x=x<0?x+b:x;
    return x;
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll size,k;
    priority_queue<pii>q;
    cin>>size>>k;
    vi arr(size);
    FOR(i,0,size-1)
    {
        cin>>arr[i];
        q.push(mp(arr[i],i));
    }
    FOR(i,0,k-1)
    {
        pii num=q.top();
        q.pop();
        ll temp=arr[i];
        arr[i]=arr[num.ss];
        arr[num.ss]=temp;
    }
    FOR(i,0,size-1)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
