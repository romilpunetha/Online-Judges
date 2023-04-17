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
    V<int> arr;
    UM<int, UM<int, int> > mp;
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
        int s = 0;
        int n;
        cin >> n;
        arr.resize(n);
        for (auto &it : arr) cin >> it, s += it;
        for (int i = 0; i < n; i++) {
            auto it = find_if(all(mp[s - arr[i]]), [&j](const UM<int, int>::value_type &a) { return a.ff != j; });
            if (it != mp[s - arr[i]].end()) {
                cout << "YES" << endl;
                cout << j + 1 << " " << i + 1 << endl;
                cout << it->ff + 1 << " " << it->ss + 1 << endl;
                return 0;
            }
            mp[s - arr[i]][j] = i;
        }
    }
    cout << "NO" << endl;
    return 0;
}
