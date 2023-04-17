#include <bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define present(c, x) ((c).find(x) != (c).end())
#define mod 1000000007
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

ll n, m, k, mx = 0, ans = 0;

typedef struct Dsu {
    vector<ll> sizes, parent, gov, visited;
    Dsu(int n) {
        parent.resize(n + 1);
        sizes.resize(n + 1, 1);
        gov.resize(n + 1, 0);
        visited.resize(n + 1, 0);
    }

    int find(int x) {
        while (x != parent[x]) x = parent[x];
        return x;
    }

    void merge(int x, int y) {
        int p = find(x);
        int q = find(y);
        if (p != q) {
            parent[p] = q;
            sizes[q] += sizes[p];
        }
    }

} Dsu;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    Dsu d(n);
    for (int i = 1; i <= n; i++) d.parent[i] = i;
    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
        d.gov[t] = 1;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        d.merge(u, v);
    }
    for (int i = 0; i <= n; i++)
        if (d.gov[i]) d.gov[d.find(i)] = 1;
    for (int i = 1; i <= n; i++) {
        int t = d.find(i);
        if (d.gov[t] && !d.visited[t]) {
            mx = max(mx, d.sizes[t]);
            ans += (d.sizes[t] * (d.sizes[t] - 1) / 2);
            d.visited[t] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        int t = d.find(i);
        if (!d.gov[t]) {
            ans += mx;
            mx++;
        }
    }
    ans -= m;
    cout << ans << endl;
    return 0;
}
