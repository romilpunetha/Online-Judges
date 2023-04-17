// {{{ #includes
#include <limits.h>
#include <string.h>

#include <algorithm>
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
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// }}}
// {{{ #define
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define um unordered_map
#define clear(x) memset((x), 0, sizeof((x)))
#define fill(x, y) memset((x), y, sizeof((x)))
#define si(x) \
    int x;    \
    scanf("%d", &(x));
#define sl(x) \
    ll x;     \
    scanf("%lld", &(x));
#define FOR(i, x, y) for (ll i = (x); i <= (y); ++i)
#define ROF(i, x, y) for (ll i = (y); i >= (x); --i)
#define sz(a) int((a).size())
#define len(a) int((a).length())
#define foreach(i, c) for (auto i = (c).begin(); i != (c).end(); i++)
#define all(x) (x).begin(), (x).end()
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define lcm(x, y) (((x) / gcd((x), (y))) * (y))
#define abs(x) ((x) < 0 ? -(x) : (x))
#define sq(x) ((x) * (x))
using namespace std;
// }}}
// {{{ typedefs
typedef vector<list<int> > graph;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef list<int> li;
typedef vector<li> vli;
const ll inf = INT_MAX;
// }}}
// {{{ display vectors
template <class T>
void display(vector<vector<T> >& arr) {
    typename vector<vector<T> >::iterator ii;
    typename vector<T>::iterator ij;
    cout << "Vector contains:" << endl;
    for (ii = arr.begin(); ii != arr.end(); ii++) {
        for (ij = (*ii).begin(); ij != (*ii).end(); ij++) {
            cout << *ij << " ";
        }
        cout << endl;
    }
    cout << endl;
}
template <class T>
void display(vector<T>& arr) {
    typename vector<T>::iterator it;
    cout << "Vector contains:" << endl;
    for (it = arr.begin(); it != arr.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
// }}}
//  {{{ swaps, gcd, modinv, power, bigmod,tostr

template <typename T>
string tostr(T x) {
    stringstream ss;
    ss << x;
    return ss.str();
}

template <typename T>
void swaps(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
template <typename T1, typename T2>
T1 power(T1 num, T2 a) {
    if (a == 0) {
        return 1;
    }
    double res = 0;
    while (a) {
        if (a & 1) {
            res = res * num;
        }
        num = num * num;
        a >>= 1;
    }
    return (T1)res;
}
template <typename T1, typename T2, typename T3>
T3 bigmod(T1 num, T2 a, T3& mod) {
    if (mod == 1) {
        return 0;
    }
    if (a == 0)
        return 1;
    ll res = 1;
    while (a) {
        if (a & 1) {
            res = (res * num) % mod;
        }
        num = (num * num) % mod;
        a >>= 1;
    }
    if (res < 0)
        return res + mod;
    return res;
}
template <typename T1, typename T2, typename T3, typename T4>
T2 inverse(T1 a, T2 b, T3& X, T4& Y) {
    T3 x = 1;
    T4 y = 0;
    X = 0;
    Y = 1;
    ll q, r, m, n;
    while (a != 0) {
        q = b / a;
        r = b % a;
        m = X - q * x;
        n = Y - q * y;
        X = x;
        Y = y;
        x = m;
        y = n;
        b = a;
        a = r;
    }
    return b;
}
template <typename T1, typename T2>
T1 modinv(T1 a, T2 b) {
    ll x = 0, y = 0;
    inverse(a, b, x, y);
    x = x < 0 ? x + b : x;
    return (T1)x;
}
template <typename T>
T gcd(T a, T b) {
    if (b == 0) {
        return a;
    }
    T x = 0, y = 0;
    T res = inverse(a, b, x, y);
    return res;
}
// }}}

int max_global = 0;

int dfs(graph& g, vi& colour, vi& visited, int parent) {
    if (visited[parent] || colour[parent] == 0)
        return 0;
    visited[parent] = 1;
    int ans = 0, max1 = 0, max2 = 0;
    foreach (it, g[parent]) {
        if (!visited[*it]) {
            // cout<<"parent = "<<parent<<" and child = "<<*it<<endl;
            ans = dfs(g, colour, visited, *it);
            // cout<<"ans in dfs for "<<parent<<" is "<<ans<<endl;
        }
        if (ans >= max1) {
            max2 = max1;
            max1 = ans;
        } else if (ans > max2) {
            max2 = ans;
        }
    }
    ans++;
    max_global = max(max_global, max1 + max2 + 1);
    // cout<<"ans for "<<parent<<" is "<<ans<<endl;
    return max1 + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    si(N);
    graph g(N + 1);
    vi colour(N + 1);
    FOR(i, 1, N) {
        scanf("%d", &colour[i]);
    }
    FOR(i, 1, N - 1) {
        si(u);
        g[u].pb(i + 1);
        g[i + 1].pb(u);
    }
    vi visited(N + 1, 0);
    int max_val = 0;
    FOR(i, 1, N) {
        if (colour[i] == 1 && !visited[i]) {
            int ans = dfs(g, colour, visited, i);
            // cout<<"ans = "<<ans<<" for dfs at = "<<i<<endl;
            // cout<<"global = "<<max_global<<endl;
            max_val = max(max_val, ans);
        }
    }
    printf("%d\n", max(max_val, max_global));
    return 0;
}
