
// {{{22222
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
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define FOR(i, x, y) for (long long int i = (x); i <= (y); ++i)
#define ROF(i, x, y) for (long long int i = (y); i >= (x); --i)
#define all(x) (x).begin(), (x).end()
#define lcm(x, y) (((x) / gcd((x), (y))) * (y))
#define abs(x) ((x) < 0 ? -(x) : (x))
#define sq(x) ((x) * (x))
using namespace std;
//  }}}
// {{{
/*************************************************************************************************/
/*************************************************************************************************/
/****************************************TEMPLATE STARTS HERE*************************************/
/*************************************************************************************************/
/*************************************************************************************************/
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef vector<pii> vii;
typedef vector<int> vi;
const ll inf = 2147383647;
// }}}
ull max(ull a, ull b) {
    return a > b ? a : b;
}
ull min(ull a, ull b) {
    return a < b ? a : b;
}

int main() {
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--) {
        ll n;
        cin >> n;
        vector<ull> A(n), B(n);
        FOR(i, 0, n - 1) {
            cin >> A[i];
        }
        FOR(i, 0, n - 1) {
            cin >> B[i];
        }
        ull m = min(A[0], B[0]);
        int flag = 0;
        FOR(i, 1, n - 1) {
            if (max(A[i], B[i]) < m) {
                flag = 1;
                break;
            } else if (min(A[i], B[i]) >= m) {
                m = min(A[i], B[i]);
            } else {
                m = max(A[i], B[i]);
            }
        }
        if (flag == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
