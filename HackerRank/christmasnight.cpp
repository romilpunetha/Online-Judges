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
inline void scan(T &x) {
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

int parent(int p, vi &arr) {
    while (p != arr[p]) {
        p = arr[arr[p]];
    }
    return p;
}

void unionfrnd(int p, int q, vi &arr, vi &size) {
    int x = parent(p, arr);
    int y = parent(q, arr);
    if (size[x] > size[y]) {
        arr[y] = x;
        size[x] = size[x] + size[y];
    } else {
        arr[x] = y;
        size[y] += size[x];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    si(test);
    while (test--) {
        si(n);
        si(m);
        vi arr(n + 1);
        vi size(n + 1, 1);
        FOR(i, 0, n) {
            arr[i] = i;
        }
        FOR(i, 1, m) {
            si(p);
            si(q);
            if (parent(p, arr) != parent(q, arr)) {
                unionfrnd(p, q, arr, size);
            }
        }
        vi money(n + 1, 0);
        FOR(i, 1, n) {
            scan(money[i]);
        }
        vi res(n + 1, 0);
        FOR(i, 1, n) {
            res[parent(i, arr)] += money[i];
        }
        int maxs = 0;
        FOR(i, 1, n) {
            maxs = max(maxs, res[i]);
        }
        write(maxs);
    }
    return 0;
}
