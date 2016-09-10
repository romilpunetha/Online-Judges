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
#define init(x,y) memset((x),(y),sizeof((x)))
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
int counts=0;
int len;

int lcs(string &abr,vector<string> &arr)
{
    int l2=abr.length();
    int l1=arr.size();
    int dp[l1+1][l2+1];
    clear(dp);
    dp[0][0]=1;
    int dp2[160][160];
    FOR(i,1,l1)
    {
        FOR(j,1,l2)
        {
            int mx=min(l2-(j-1),(int)arr[i-1].length());
            int p=arr[i-1].length();
            FOR(k,0,mx)
            {
                dp2[0][k]=0;
            }
            FOR(k,0,p)
            {
                dp2[k][0]=1;
            }
            FOR(k,0,p)
            {
                FOR(l,0,mx)
                {
                    dp2[k+1][l+1]=dp2[k][l+1];
                    if(arr[i-1][k]==abr[j+l-1])
                    {
                        dp2[k+1][l+1]+=dp2[k][l];
                    }
                }
            }
            FOR(k,1,mx)
            {
                dp[i][j-1+k]+=dp[i-1][j-1]*dp2[p][k];
            }
        }
    }
    return dp[l1][l2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin>>num;
    cin.ignore(INT_MAX,'\n');
    while(num)
    {
        string s;
        map<string,int>m;
        FOR(i,0,num-1)
        {
            getline(cin,s);
            m[s]=1;
        }
        getline(cin,s);
        while(s.compare("LAST CASE")!=0)
        {
            vector<string> arr;
            s=s+' ';
            string words;
            int i=0;
            int l=s.length();
            string abr;
            while(s[i]!=' ')
            {
                abr+=s[i];
                i++;
            }
            len=i;
            i++;
            while(i<l)
            {
                if(s[i]==' ')
                {
                    if(m.find(words)==m.end())
                    {
                        arr.pb(words);
                    }
                    words="";
                }
                else
                {
                    words=words+s[i];
                }
                i++;
            }
            cout<<abr;
            FOR(k,0,len-1)
            {
                abr[k]=tolower(abr[k]);
            }
            int res = lcs(abr,arr);
            if(res==0)
            {
                cout<<" is not a valid abbreviation\n";
            }
            else
            {
                cout<<" can be formed in "<<res<<" ways\n";
            }
            getline(cin,s);
        }
        cin>>num;
        cin.ignore(INT_MAX,'\n');
    }
    return 0;
}

