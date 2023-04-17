
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
#define MP map
#define ST set
#define UM unordered_map
#define MM multimap
#define UMM unordered_multimap
#define MST multiset
#define UST unordered_set
#define UMS unordered_multiset
#define PQ priority_queue
#define Graph V<L<int> >
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

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    V<P<ll, ll> > arr(n);
    MST<ll> coins;
    UM<ll, ll> posi, res;
    for (auto &it : arr) cin >> it.ff;
    for (auto &it : arr) cin >> it.ss, coins.insert(it.ss);
    for (int i = 0; i < n; i++) posi[arr[i].ff] = i;
    sort(all(arr));
    reverse(all(arr));
    for (auto &it : arr) {
        ll ans = it.ss;
        coins.erase(coins.find(it.ss));
        int j = k;
        for (auto jt = coins.rbegin(); j && jt != coins.rend(); j--, jt++) ans += *jt;
        res[it.ff] = ans;
    }
    V<ll> result(n);
    for (auto &it : posi) result[posi[it.ff]] = res[it.ff];
    for (auto &it : result) cout << it << " ";
    return 0;
}
