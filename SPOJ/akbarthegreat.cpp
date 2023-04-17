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
    scan(x);
#define sl(x) \
    ll x;     \
    scan(x);
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
#define gc getchar_unlocked
#define pc putchar_unlocked
using namespace std;
// }}}
// {{{ typedefs
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
const ll inf = 2147383647;
// }}}
// {{{ fast I/O
template <typename T>
inline void scan(T& x) {
    bool neg = false;
    x = 0;
    int c = gc();
    for (; (c < 48 || c > 57) && c != '-'; c = gc())
        ;
    if (c == '-') {
        neg = true;
        c = gc();
    }
    for (; c > 47 && c < 58; c = gc()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
    x = neg == true ? -x : x;
}
template <typename T>
inline void write(T x) {
    bool neg = false;
    char buffer[200];
    int i = 0;
    if (x < 0) {
        x = -x;
        neg = true;
    }
    do {
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while (x);
    i--;
    if (neg == true) {
        i++;
        buffer[i] = '-';
    }
    while (i >= 0) pc(buffer[i--]);
    pc('\n');
}
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
int stop = 0;
vi covered;
void visit(vector<list<int> >& g, vi& visited, int parent, int city, int strength, int level) {
    // cout<<"city : "<<city<<" strength : "<<strength<<" level : "<<level<<endl;
    if (covered[city] != 0 && covered[city] != parent) {
        stop = 1;
        return;
    }
    visited[city] = level;
    covered[city] = parent;
    if (strength == level)
        return;
    list<int>::iterator it;
    foreach (it, g[city]) {
        // cout<<"city = "<<city<<" it = "<<*it<<" level = "<<level<<endl;
        if (visited[*it] == -1 || visited[*it] > level) {
            visit(g, visited, parent, *it, strength, level + 1);
            if (stop == 1) {
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    si(test);
    while (test--) {
        stop = 0;
        si(n);
        si(r);
        si(m);
        vector<list<int> > graph(n + 1);
        FOR(i, 1, r) {
            si(u);
            si(v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        list<pii> l;
        FOR(i, 0, m - 1) {
            si(u);
            si(s);
            l.pb(mp(u, s));
        }
        list<int>::iterator it;
        vi(n + 1, 0).swap(covered);
        vi visited(n + 1, -1);
        foreach (it, l) {
            visit(graph, visited, it->ff, it->ff, it->ss, 0);
            // display(visited);
            if (stop == 1) {
                break;
            }
        }
        int flag = 0;
        FOR(i, 1, n) {
            if (covered[i] == 0 || stop == 1) {
                flag = 1;
                break;
            }
        }
        // display(covered);
        if (flag == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
