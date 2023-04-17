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

int mod = 1000000007;

ll count(int num, vi &sieve) {
    ll res = 1;
    int p = 0;
    while (1) {
        int count = 0;
        int prime = sieve[p];
        if (prime > num || prime == 0) {
            break;
        }
        while (num / prime) {
            count += (num / prime);
            prime = prime * sieve[p];
        }
        p++;
        res = ((res % mod) * (count + 1)) % mod;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vi sieve(10000, 0);
    int arr[60000];
    FOR(i, 0, 60000 - 1) {
        arr[i] = 1;
    }
    int p = 0;
    arr[0] = 0;
    arr[1] = 0;
    FOR(i, 2, 60000) {
        if (arr[i] == 1) {
            sieve[p] = i;
            p++;
            int j = i;
            while (i * j <= 60000) {
                arr[i * j] = 0;
                j++;
            }
        }
    }
    si(test);
    while (test--) {
        ll res = 0;
        si(num);
        if (num != 0)
            res = count(num, sieve);
        if (num == 0) {
            res = 1;
        }
        write(res);
    }
    return 0;
}
