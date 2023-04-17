#include <bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define der(c, x) ((c).find(x) != (c).end())
#define base 999983
#define baseinv 943912055
#define mod 1000000007
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

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, sum = 0, even = 1, odd = 0;
    cin >> n;
    V<ll> left(n + 2, 0), right, arr;
    right = arr = left;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
        if (sum & 1)
            left[i] = odd++;
        else
            left[i] = even++;
    }
    even = 1, odd = 0, sum = 0;
    for (int i = n; i >= 1; i--) {
        sum += arr[i];
        if (sum & 1)
            right[i] = odd++;
        else
            right[i] = even++;
    }
    for (int i = n; i > 0; i--) right[i] += right[i + 1];
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += left[i] * right[i + 1];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
