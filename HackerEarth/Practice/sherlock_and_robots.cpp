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

typedef struct BIT {
    V<ll> bit;
    BIT() {
        bit = V<ll>(1e6 + 10, 0);
    }
    void update(ll i, ll val) {
        while (i <= 1e6) {
            bit[i] += val;
            i += i & -i;
        }
    }

    ll query(ll i) {
        ll sum = 0;
        while (i) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }
} BIT;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    V<ll> H(n), I(n), P(n, 0);
    BIT count, val;
    for (int i = 0; i < n; i++) cin >> H[i] >> I[i];
    for (int i = n - 1; i >= 0; i--) {
        count.update(H[i], 1), val.update(H[i], I[i]);
        ll low = count.query(H[i] - 1), hi = n - i - low;
        ll p = val.query(H[i] - 1), q = val.query(1e6) - p;
        P[i] = hi * I[i] - q + p - low * I[i];
    }
    for (auto &it : P) cout << it << endl;
    return 0;
}
