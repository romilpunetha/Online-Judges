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
#define init(x, y) memset((x),y,sizeof((x))
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    vi sieve(1000010, 1);
    sieve[0] = 0;
    sieve[1] = 0;
    vi dp(1000010, 0);
    FOR(i, 2, 1000000) {
        if (sieve[i] == 1) {
            dp[i] = dp[i - 1] + 1;
            int j = i;
            while (i * j <= 1000000) {
                sieve[i * j] = 0;
                j++;
            }
        } else {
            dp[i] = dp[i - 1];
        }
    }
    FOR(i, 1, 100) {
        if (sieve[i] == 1)
            cout << i << endl;
    }
    while (test--) {
        int li, ri;
        cin >> li;
        cin >> ri;
        double prob = 0.0;
        prob = (1.0 * (dp[ri] - dp[li - 1])) / (ri - li + 1);
        if (ri < li)
            prob = 0;
        cout << fixed << setprecision(6) << prob << "\n";
        // printf("%6f\n",prob);
    }
    return 0;
}
