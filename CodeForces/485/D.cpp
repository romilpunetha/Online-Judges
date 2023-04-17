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
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    V<L<int>> g(n);
    int arr[n][k];
    memset(arr, 0, sizeof(arr));
    queue<int> goods[k];
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        t--;
        arr[i][t] = 1;
        goods[t].push(i);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v), g[v].pb(u);
    }
    for (int i = 0; i < k; i++) {
        while (!goods[i].empty()) {
            int u = goods[i].front();
            goods[i].pop();
            for (auto &v : g[u]) {
                if (!arr[v][i]) arr[v][i] = arr[u][i] + 1, goods[i].push(v);
            }
        }
    }
    for (auto &it : arr) sort(it, it + k);
    V<int> ans(n, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < s; j++)
            ans[i] += arr[i][j];
    for (auto &it : ans) cout << it - s << " ";
    return 0;
}
