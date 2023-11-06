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
#define VVi V<V<int>>
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
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define stoi stoll
#define si(x) int(x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using dbl = double;
using ldbl = long double;

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

template <typename T, typename U>
T ceil(T x, U y) {
    return (x > 0 ? (x + y - 1) / y : x / y);
}
template <typename T, typename U>
T floor(T x, U y) {
    return (x > 0 ? x / y : (x - y + 1) / y);
}
template <typename T, typename U>
pair<T, T> divmod(T x, U y) {
    T q = floor(x, y);
    return { q, x - q * y };
}

template <typename T, typename U>
T SUM(const vector<U> &A) {
    T sum = 0;
    for (auto &&a : A) sum += a;
    return sum;
}

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
void tr() { cerr << endl; }
template <typename H, typename... T>
inline void tr(H head, T... tail) {
    cerr << head << ' ';
    tr(tail...);
    cerr << endl;
}

const int limit = 1e5 + 10;
Vll arr(limit), brr(limit), ans, incoming;
V<bool> visited;

Graph g;
int n;

void dfs(int u, Vi &crr) {
    if (visited[u]) return;
    visited[u] = true;
    crr.pb(u);
    for (auto &it : g[u])
        if (!visited[it]) dfs(it, crr);
}

void util(int i) {
    Vi crr;
    dfs(i, crr);
    ll res = 1;
    for (auto &it : crr) res += 2 * brr[it];
    ll mx = 0, k = -1;
    for (int i = 0; i < si(crr); i++) {
        ll t = res - brr[crr[i]];
        if (mx < t) {
            mx = t;
            k = i;
        }
    }

    for (int i = 0; i < si(crr); i++) {
        ++k;
        k = k % si(crr);
        ans.pb(crr[k]);
    }
}

void solve() {
    cin >> n;

    ans.clear();
    incoming.clear();
    incoming.resize(n + 1, 0);
    visited.clear();
    visited.resize(n + 1, 0);
    g.clear();
    g.resize(n + 1);

    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) cin >> brr[i];

    for (int i = 1; i <= n; i++) {
        incoming[arr[i]]++;
        g[i].pb(arr[i]);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!incoming[i]) q.push(i);

    while (!q.empty()) {
        int t = q.front();
        visited[t] = true;
        q.pop();
        ans.pb(t);
        incoming[arr[t]]--;
        if (!incoming[arr[t]]) q.push(arr[t]);
    }

    for (int i = 1; i <= n; i++)
        if (!visited[i]) util(i);
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