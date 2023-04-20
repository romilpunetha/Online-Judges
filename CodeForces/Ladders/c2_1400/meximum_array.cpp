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
#define Vi V<int>
#define Vll V<ll>
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
#define Pii P<int, int>
#define Pll P<long long, long long>
#define Graph V<L<int>>
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define sz size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
using namespace std;
template <typename A, typename B>
inline ostream &operator<<(ostream &os, const pair<A, B> &v) { return os << v.first << ' ' << v.second; }
template <typename A>
inline ostream &operator<<(ostream &os, const vector<A> &v) {
    auto it = v.begin();
    os << *it;
    for (++it; it != v.end();
         os << ' ' << *it++)
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

int getMex(int i, int mx, UST<int> &st) {
    for (; i <= mx; i++) {
        if (!der(st, i)) return i;
    }
    return mx + 1;
}

void util(int start, Vi &arr, Vi &ans, Vi &mex) {
    if (start >= arr.sz) return;
    int mx = mex[start], k = 0;
    UST<int> st;
    for (; start < arr.sz; start++) {
        st.insert(arr[start]);
        int t = getMex(k, mx, st);
        if (t == mx) break;
        k = t;
    }
    bool flag = 0;
    for (int i = 0; i <= mx; i++) {
        if (!der(st, i)) {
            ans.pb(i);
            flag = 1;
            break;
        }
    }
    if (!flag) ans.pb(mx + 1);
    util(start + 1, arr, ans, mex);
}

Vi createMex(Vi &arr) {
    Vi mex(arr.sz);
    int mx = arr[arr.sz - 1], k = 0;
    UST<int> st;
    for (int i = arr.sz - 1; i >= 0; i--) {
        mx = max(mx, arr[i]);
        st.insert(arr[i]);
        mex[i] = getMex(k, mx, st);
        k = mex[i];
    }
    return mex;
}

void solve() {
    int n;
    cin >> n;
    Vi arr(n), mex, ans;
    for (auto &it : arr) cin >> it;
    mex = createMex(arr);
    util(0, arr, ans, mex);
    cout << ans.sz << endl;
    for (auto &it : ans) cout << it << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}