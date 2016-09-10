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
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define all(x) (x).begin(),(x).end()
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
        typedef pair < int, int > pii;
        typedef pair < ll, ll > pll;
        typedef pair<string,int> psi;
typedef pair<int,string> pis;
typedef vector<pii> vii;
typedef vector<int> vi;
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
    char buffor[35];
    int i=0;
    if(x<0)
    {
        x=-x;
        i=1;
        buffor[0]='-';
    }
    do
    {
        buffor[i++]=(x%10)+'0';
        x/=10;
    } while(x);
    i--;
    while(i>=0) pc(buffor[i--]);
    pc('\n');
}
// }}}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sl(n);
    sl(k);
    ll count=0;
    while(n--)
    {
        sl(a);
        if(a%k==0)
            count++;
    }
    write(count);
    return 0;
}

