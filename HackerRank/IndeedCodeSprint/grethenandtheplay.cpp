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
    int c=gc();
    for(;c<48 || c>57;c=gc());
    x=0;
    for(;c>47 && c<58;c=gc())
    {
        x=(x<<1)+(x<<3)+c-48;
    }
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

void update(vector<int>&BIT,int s,int max,int v)
{
    s++;
    while(s<=max)
    {
        BIT[s]+=v;
        s+=(s&-s);
    }
}

int query(vector<int>&BIT,int p)
{
    int sum=0;
    while(p)
    {
        sum+=BIT[p];
        p-=p&-p;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    si(M);
    si(N);
    si(Q);
    vi spos(N,0);
    vi scount(M,0);
    vi BIT(N+1,0);
    FOR(i,0,N-1)
    {
        scan(spos[i]);
        scount[spos[i]]++;
    }
    FOR(i,0,M-1)
    {
        update(BIT,scount[i],N,1);
    }
    while(Q--)
    {
        si(q);
        if(q==1)
        {
            si(actor);
            si(scene);
            update(BIT,scount[spos[actor]],N,-1);
            scount[spos[actor]]--;
            update(BIT,scount[spos[actor]],N,1);
            update(BIT,scount[scene],N,-1);
            scount[scene]++;
            update(BIT,scount[scene],N,1);
            spos[actor]=scene;
        }
        else
        {
            si(p);
            int ans=query(BIT,p);
            write(ans);
        }
    }

    return 0;
}

