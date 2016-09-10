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
typedef vector<list<pair<int,int> > > graph;
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
const ll inf = LLONG_MAX;
// }}}
// {{{ display vectors
    template<class T>
void display(vector<vector<T> >& arr)
{
    typename vector<vector<T> >::iterator ii;
    typename vector<T>::iterator ij;
    cout<<"Vector contains:"<<endl;
    for(ii=arr.begin();ii!=arr.end();ii++)
    {
        for(ij=(*ii).begin();ij!=(*ii).end();ij++)
        {
            cout<<*ij<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
    template<class T>
void display(vector<T>& arr)
{
    typename vector<T>::iterator it;
    cout<<"Vector contains:"<<endl;
    for(it=arr.begin();it!=arr.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
// }}}
//  {{{ swaps, gcd, modinv, power, bigmod,tostr

    template<typename T>
string tostr(T x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}

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
    if(a==0)
        return 1;
    ll res=1;
    while(a)
    {
        if(a&1)
        {
            res=(res*num)%mod;
        }
        num=(num*num)%mod;
        a>>=1;
    }
    if(res<0)
        return res+mod;
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

struct comp
{
    bool operator()(const pll &a,const pll &b)
    {
        return a.ss>b.ss;
    }
};

void dijkstra(graph &g,int source,vl &distance)
{
    priority_queue<pll,vector<pll>,comp> Q;
    Q.push(make_pair(source,0));
    while(!Q.empty())
    {
        int u=Q.top().first;
        Q.pop();
        foreach(it,g[u])
        {
            int v= (*it).ff;
            int w = (*it).ss;
            if(distance[v] > distance[u]+w)
            {
                distance[v] = distance[u]+w;
                Q.push(make_pair(v,distance[v]));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    si(N);
    si(M);
    si(S);
    graph g(N+1);
    vl population(N+1,0);
    FOR(i,0,N-1)
    {
        scanf("%lld",&population[i+1]);
    }
    FOR(i,0,M-1)
    {
        si(u);
        si(v);
        si(w);
        g[u].pb(mp(v,w));
        g[v].pb(mp(u,w));
    }
    vl distance(N+1,inf);
    distance[S]=0;
    dijkstra(g,S,distance);
    ll prefix1=0,prefix2=0;
    FOR(i,1,N)
    {
        if(distance[i]!=inf)
        {
            prefix1+=distance[i]*population[i];
            prefix2+=population[i];
        }
    }
    //display(distance);
    FOR(i,1,N)
    {
        ll ans=0;
        if(distance[i]!=inf)
        {
            ans = ((prefix2-population[i])*distance[i])+(prefix1-population[i]*distance[i]);
        }
        //cout<<ans<<" ";
    }
    cout<<endl;
    return 0;
}

