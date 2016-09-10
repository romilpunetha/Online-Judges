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
// }}}
// {{{ #define
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define um unordered_map
#define clear(x) memset ((x),0,sizeof((x)))
#define init(x,y) memset((x),y,sizeof((x))
#define si(x) int x; scan(x);
#define sl(x) ll x; scan(x);
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
#define gc getchar_unlocked
#define pc putchar_unlocked
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
const ll inf = 2147383647;
// }}}
// {{{ fast I/O
    template<typename T>
inline void scan(T &x)
{
    bool neg=false;
    x=0;
    int c=gc();
    for(;(c<48 || c>57) && c!='-';c=gc());
    if(c=='-')
    {
        neg=true;
        c=gc();
    }
    for(;c>47 && c<58;c=gc())
    {
        x=(x<<1)+(x<<3)+c-48;
    }
    x=neg==true?-x:x;
}
    template<typename T>
inline void write(T x)
{
    bool neg=false;
    char buffer[200];
    int i=0;
    if(x<0)
    {
        x=-x;
        neg=true;
    }
    do
    {
        buffer[i++]=(x%10)+'0';
        x/=10;
    } while(x);
    i--;
    if(neg==true)
    {
        i++;
        buffer[i]='-';
    }
    while(i>=0) pc(buffer[i--]);
    pc('\n');
}
// }}}
//  {{{ swaps, gcd, modinv, power, bigmod
    template<typename T>
void swaps(T& a,T& b)
{
    T temp=a;
    a=b;
    b=temp;
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sl(n);
    sl(k);
    while(n!=-1 && k!=-1)
    {
        if(k<=2)
        {
            write(0);
        }
        else
        {
            k--;
            ll p=0;
            if(k%2==0)
            {
                k=k/2;
                p=k + (k*(k-1));
            }
            else
            {
                k=k/2;
                p=k*(k+1);
            }
            ll q;
            if(n&1)
            {
                q= ((n-1)/2)*n;
            }
            else
            {
                q=(n/2)* (n-1);
            }
            ll g=gcd(p,q);
            p/=g;
            q/=g;
            printf("%lld/%lld\n",p,q);
        }
        scan(n);
        scan(k);
    }
    return 0;
}

