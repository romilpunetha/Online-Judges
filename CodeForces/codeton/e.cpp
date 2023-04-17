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
#define all(a) (a).begin(), (a).end()
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

Vi parent;
Vi sz;

int find(int x) {
    if (x == parent[x]) return x;
    return find(parent[x] = parent[parent[x]]);
}

void join(int x, int y) {
    int parent_x = find(x);
    int parent_y = find(y);
    if (parent_x == parent_y) return;
    if (parent_x > parent_y) swap(parent_x, parent_y);
    parent[parent_y] = parent_x;
    sz[parent_x] += sz[parent_y];
}

bool solve() {
    int n, m;
    cin >> n >> m;
    parent.clear();
    sz.clear();
    parent.resize(n, 0);
    sz.resize(n, 1);

    for (int i = 0; i < n; i++) parent[i] = i;

    Graph g(n);
    Vi arr(n);
    PQ<V<int>, V<V<int>>, greater<V<int>>> q;
    V<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (!arr[i]) q.push({ 0, i, i });
    }

    for (int i = 0; i < m; i++) {
        int p, q;
        cin >> p >> q;
        p--, q--;
        g[p].pb(q);
        g[q].pb(p);
    }

    while (!q.empty()) {
        V<int> t = q.top();

        q.pop();
        int power = t[0];
        int index = t[1];
        int from = t[2];

        if (sz[find(from)] < power) return false;
        join(from, index);

        if (visited[index]) continue;
        visited[index] = true;

        for (auto &it : g[index]) q.push({ arr[it], it, index });
    }

    bool ans = false;

    for (int i = 0; i < n; i++) {
        ans |= (sz[find(i)] == n);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
