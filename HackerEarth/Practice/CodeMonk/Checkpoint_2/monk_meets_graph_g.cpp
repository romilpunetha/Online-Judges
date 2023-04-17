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
inline ostream &operator<<(ostream &os, const pair<A, B> &v) { return os << v.first << ' ' << v.second; }
template <typename A>
inline ostream &operator<<(ostream &os, const vector<A> &v) {
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

int n, m, A, B, mod = 1e9 + 7;

void getShortestPath(Graph &g, int S, V<ll> &visited, V<ll> &cnt, V<ll> &val) {
    queue<int> q;
    cnt[S] = visited[S] = 1;
    val[S] = 0;
    q.push(S);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v : g[u]) {
            if (!visited[v]) {
                val[v] = val[u] + 1;
                cnt[v] = cnt[u];
                visited[v] = 1;
                q.push(v);
            } else if (val[v] == val[u] + 1) {
                cnt[v] += cnt[u];
            }
            cnt[v] %= mod;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    V<ll> visitedA(n + 1, 0), cntA(n + 1, 0), valA(n + 1, 0);
    V<ll> visitedB(n + 1, 0), cntB(n + 1, 0), valB(n + 1, 0);
    Graph g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> A >> B;
    getShortestPath(g, A, visitedA, cntA, valA);
    getShortestPath(g, B, visitedB, cntB, valB);
    ST<int> st;
    for (int i = 1; i <= n; i++) {
        if (i != A && i != B && cntA[B] != 0 && (cntA[i] * cntB[i]) % mod == cntA[B] && valA[i] + valB[i] == valA[B]) {
            st.insert(i);
        }
    }
    if (!st.size())
        cout << "-1" << endl;
    else
        cout << *st.begin() << endl;
    return 0;
}
