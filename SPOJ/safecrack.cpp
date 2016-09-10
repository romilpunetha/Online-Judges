// {{{ #includes
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
#include <unordered_set>
// }}}
// {{{ #define
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define um unordered_map
#define clear(x) memset ((x),0,sizeof((x)))
#define fill(x,y) memset((x),y,sizeof((x)))
#define si(x) int x; scanf("%d",&(x));
#define sl(x) ll x; scanf("%lld",&(x));
#define FOR(i,x,y) for(ll i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(ll i = (y) ; i >= (x) ; --i)
#define sz(a) int((a).size())
#define len(a) int ((a).length())
#define foreach(i,c) for(auto i = (c).begin(); i != (c).end(); i++)
#define all(x) (x).begin(),(x).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define lcm(x,y) (((x)/gcd((x),(y)))*(y))
#define abs(x) ((x)<0?-(x):(x))
#define sq(x) ((x)*(x))
using namespace std;
// }}}
// {{{ typedefs
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;
typedef pair<string,int> psi;
typedef pair<int,string> pis;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef list<int> li;
typedef vector<li> vli;
const ll inf = INT_MAX;
// }}}
//  {{{ swaps, gcd, modinv, power, bigmod,tostr

    template<typename T>
string tostr(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

    template<typename T1, typename T2>
T1 power(T1 num,T2 a)
{
    if(a==0)
    {
        return 1;
    }
    double res=0;
    while(a)
    {
        if(a&1)
        {
            res=res*num;
        }
        num=num*num;
        a>>=1;
    }
    return (T1)res;
}
    template<typename T1,typename T2,typename T3>
T3 bigmod(T1 num,T2 a,T3& mod)
{
    if(mod==1)
    {
        return 0;
    }
    ll res=0;
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
    template<typename T1,typename T2,typename T3,typename T4>
T2 inverse(T1 a,T2 b,T3 &X,T4 &Y)
{
    T3 x=1;T4 y=0;
    X=0;Y=1;
    ll q,r,m,n;
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
    template<typename T1,typename T2>
T1 modinv(T1 a,T2 b)
{
    ll x=0,y=0;
    inverse(a,b,x,y);
    x=x<0?x+b:x;
    return (T1)x;
}
    template<typename T>
T gcd(T a,T b)
{
    if(b==0)
    {
        return a;
    }
    T x=0,y=0;
    T res=inverse(a,b,x,y);
    return res;
}
// }}}

int xco[]={0,1,0,-1};
int yco[]={-1,0,1,0};
int mod=1000000007;
ll pad1[4][3]={{1,1,1},{1,1,1},{1,1,1},{1,0,0}};
ll pad2[4][3];
bool isvalid(int x,int y)
{
    if(x<0 || x==3 || y<0 || y==3)
        return false;
    return true;
}
int p=2;


int compute()
{
    FOR(i,0,2)
    {
        FOR(j,0,2)
        {
            FOR(k,0,3)
            {
                int a=i+xco[k];
                int b=j+yco[k];
                if(isvalid(a,b))
                {
                    pad2[i][j]=((pad2[i][j]%mod)+pad1[a][b]%mod);
                }
            }
        }
    }
    pad2[2][0]+=pad1[3][0];
    pad2[3][0]=pad1[2][0];
    ll res=0;
    FOR(i,0,2)
    {
        FOR(j,0,2)
        {
            res=((res%mod)+(pad2[i][j]%mod))%mod;
        }
    }
    res+=pad2[3][0]%mod;
    FOR(i,0,2)
    {
        FOR(j,0,2)
        {
            pad1[i][j]=pad2[i][j]%mod;
            pad2[i][j]=0;
        }
    }
    pad1[3][0]=pad2[3][0]%mod;
    pad2[3][0]=0;
    pad2[3][1]=0;
    pad2[3][2]=0;
    return res;
}
void fills(ll arr[],int n)
{
    FOR(i,p,n)
    {
        arr[i]=compute()%mod;
        //coUT<<"I : "<<I<<" ARR[I] : "<<ARR[I]<<endl;
    }
    p=n+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    si(test);
    ll arr[100010];
    clear(arr);
    arr[1]=10;
    clear(pad2);
    while(test--)
    {
        si(n);
        if(n<p)
        {
            arr[n]%=mod;
            printf("%lld\n",arr[n]);
        }
        else
        {
            fills(arr,n);
            printf("%lld\n",arr[n]);
        }
    }
    return 0;
}

