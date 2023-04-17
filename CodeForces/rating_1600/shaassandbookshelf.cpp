#include <bits/stdc++.h>
#define endl '\n'
#define inf 1e5
#define pb push_back
#define der(c, x) ((c).find(x) != (c).end())
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define V vector
#define L list
#define P pair
#define MP map
#define ST set
#define UM unordered_map
#define MM multimap
#define UMM unordered_multimap
#define MST multiset
#define UST unordered_set
#define UMS unordered_multiset
#define PQ priority_queue
#define Graph list<int> *
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

V<ll> ans(110, inf);
int n;

void dp(V<P<int, int>> &a, int t, int w, int i) {
    tr3(i, t, w);
    if (i >= n)
        return;
    if (w <= t)
        ans[i] = ans[i] <= t ? ans[i] : t;
    dp(a, t + a[i].ff, w, i + 1);
    dp(a, t, w + a[i].ss, i + 1);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    ans[0] = 0;
    V<P<int, int>> a(n);
    for (auto &it : a) cin >> it.ff >> it.ss;
    dp(a, 0, 0, 0);
    for (auto &it : ans) cout << it << " ";
    cout << ans[n] << endl;
    return 0;
}
