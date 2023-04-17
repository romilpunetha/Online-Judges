#include <bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define der(c, x) ((c).find(x) != (c).end())
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define V vector
#define L list
#define P pair
#define M map
#define S set
#define UM unordered_map
#define MM multimap
#define UMM unordered_multimap
#define MS multiset
#define US unordered_set
#define UMS unordered_multiset
#define PQ priority_queue
#define Graph list<int>*
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

int x[] = { -2, -2, 1, -1 };
int y[] = { 1, -1, -2, -2 };

V<V<int> > dp(20, V<int>(20, -1));

int solve(int i, int j) {
    if (i <= 0 || i > 15 || j <= 0 || j > 15) return 0;
    if (dp[i][j] != -1) return dp[i][j] ^ 1;
    int a = 0;
    for (int k = 0; k < 4; k++) {
        a |= solve(i + x[k], j + y[k]);
    }
    dp[i][j] = a;
    return dp[i][j] ^ 1;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            solve(i, j);
        }
    }
    int test;
    cin >> test;
    while (test--) {
        int p, q;
        cin >> p >> q;
        cout << (dp[p][q] == 1 ? "First" : "Second") << endl;
    }
    return 0;
}
