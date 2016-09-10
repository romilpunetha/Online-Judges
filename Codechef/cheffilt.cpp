// {{{
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <string>
#include <unordered_map>
#define pb push_back
#define ff first
#define gc getchar_unlocked
#define ss second
#define mp make_pair
#define FOR(i,x,y) for(int i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(int i = (y) ; i >= (x) ; --i)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define all(x) (x).begin(),(x).end()
#define lcm(x,y) (((x)/gcd((x),(y)))*(y))
#define abs(x) ((x)<0?-(x):(x))
#define sq(x) ((x)*(x))
// }}}
// {{{
/*************************************************************************************************/
/*************************************************************************************************/
/****************************************TEMPLATE STARTS HERE*************************************/
/*************************************************************************************************/
/*************************************************************************************************/
using namespace std;
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

inline void scanint(int &x)
{
    int c=gc();
    for(;c<48 || c>57;c=gc());
    x=0;
    for(;c>47 && c<58;c=gc())
    {
        x=(x<<1)+(x<<3)+c-48;
    }
}

inline void scanpm(char *i)
{
    int p=0;
    char temp=getchar_unlocked();
    while(temp!='+' && temp!='-')
        temp=getchar_unlocked();
    while(temp=='+' || temp=='-')
    {
        i[p]=temp;
        p++;
        temp=getchar_unlocked();

    }
    i[p]='\0';

}
inline void scanstr(char *i)
{
    int p=0;
    char temp=getchar_unlocked();
    while(temp<'a'||temp>'z')
        temp=getchar_unlocked();
    while(temp>='a'&&temp<='z')
    {
        i[p]=temp;
        p++;
        temp=getchar_unlocked();
    }
    i[p]='\0';
}


int main()
{
    int test;
    scanint(test);
    ull mod=1000000007;
    while(test--)
    {
        unordered_map<int,ull>m,m2;
        unordered_map<int,ull>::iterator it,it2;
        int pic=0,filt=1023;
        char c[11];
        scanstr(c);
        FOR(i,0,9)
        {
            c[i]=='w'?pic=(pic<<1):pic=((pic<<1)|1);
        }
        int n;
        scanint(n);
        int req=pic^filt;
        int temp=0;
        FOR(i,0,n-1)
        {
            temp=0;
            char cp[11];
            scanpm(cp);
            FOR(j,0,9)
            {
                cp[j]=='+'?temp=((temp<<1)|1):temp<<=1;
            }
            for(it=m.begin();it!=m.end();it++)
            {
                int k=temp^it->first;
                m2[k]+=it->second;
                if(m2[k]>=mod)
                {
                    m2[k]=m2[temp^it->first]%mod;
                }
            }
            m2[temp]++;
            m=m2;
        }
        if(req==0)
        {
            m[req]++;
        }
        printf("%lld\n",m[req]%mod);
    }
    return 0;
}

