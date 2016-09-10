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
#define fill(x,y) memset((x),y,sizeof((x)))
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

int xco[]={0,-1,1,0};
int yco[]={-1,0,0,1};
int glob=0;
bool isvalid(int p,int q,int r,int c)
{
    if(p<0 || p==r || q<0 || q ==c)
    {
        return false;
    }
    return true;
}

int dfs(vector<string>&laby,vvi &visited,int x,int y,int r,int c)
{
    int res=0,max1=0,max2=0;
    visited[x][y]=1;
    FOR(i,0,3)
    {
        int a=x+xco[i];
        int b=y+yco[i];
        if(isvalid(a,b,r,c) && !visited[a][b] && laby[a][b]=='.')
        {
            int temp=1+dfs(laby,visited,a,b,r,c);
            if(temp>max1)
            {
                max2=max1;
                max1=temp;
            }
            else if(temp>max2)
            {
                max2=temp;
            }
        }
    }
    res+=max1;
    glob=max(max1+max2,glob);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    while(test--)
    {
        glob=0;
        int r,c;
        cin>>c;
        cin>>r;
        vector<string> laby(r);
        list<pii>l;
        list<pii>::iterator it;
        FOR(i,0,r-1)
        {
            cin>>laby[i];
            FOR(j,0,c-1)
            {
                if(laby[i][j]=='.')
                {
                    l.pb(mp(i,j));
                }
            }
        }
        vvi visited(r,vi(c,0));
        int res=0;
        foreach(it,l)
        {
            if(!visited[it->ff][it->ss])
            {
                res=(dfs(laby,visited,it->ff,it->ss,r,c));
                res=max(res,glob);
            }
        }
        cout<<"Maximum rope length is "<<res<<"."<<endl;
    }
    return 0;
}

