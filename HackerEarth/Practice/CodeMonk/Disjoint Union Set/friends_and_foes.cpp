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
int n, m, k;

ll parent[1000010], size[1000100], valid[1000010];

int get(int x) {
    while (x != parent[x]) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void join(int u, int v) {
    int p = get(u), q = get(v);
    if (p != q) {
        parent[p] = q;
        size[q] += size[p];
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < 1e6 + 10; i++) {
        parent[i] = i;
        size[i] = 1;
        valid[i] = 1;
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        join(u, v);
    }
    cin >> k;
    ll ans = 0;
    while (k--) {
        int u, v, p, q;
        cin >> u >> v;
        p = get(u), q = get(v);
        if (p == q) valid[p] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int p = get(i);
        if (valid[p]) ans = max(ans, size[p]), valid[p] = 0;
    }
    cout << ans << endl;
    return 0;
}
