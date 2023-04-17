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
#define all(a) (a).begin(), (a).end()
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
using namespace std;
template <typename A, typename B>
inline ostream& operator<<(ostream& os, const pair<A, B>& v) { return os << v.first << ' ' << v.second; }
template <typename A>
inline ostream& operator<<(ostream& os, const vector<A>& v) {
    auto it = v.begin();
    os << *it;
    for (++it; it != v.end(); os << ' ' << *it++)
        ;
    return os;
}
void tr() { cout << endl; }
template <typename H, typename... T>
inline void tr(H head, T... tail) {
    cerr << head << ' ';
    tr(tail...);
}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

int n, k;
V<int> arr(1e5 + 10);
MP<int, ST<int> > mp;

bool check(int i) {
    if (i >= n || mp[arr[i]].empty()) return false;
    mp[arr[i]].erase(mp[arr[i]].begin());
    if (der(mp, arr[i] - 1) && !mp[arr[i] - 1].empty()) {
        int j = *(mp[arr[i] - 1].begin());
        check(j);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        cin >> n >> k;
        mp.clear();
        for (int i = 0; i < n; i++) cin >> arr[i], mp[arr[i]].insert(i);
        for (int i = 0; i < n; i++) {
            ans += check(i);
        }
        if (ans > k)
            cout << "-1" << endl;
        else
            cout << k - ans << endl;
    }
    return 0;
}
