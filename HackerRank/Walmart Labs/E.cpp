#include <bits/stdc++.h>
#define tr1(x) cerr << #x << ":\t" << x << endl
#define tr2(x, y) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int n, m, q, food, person;
list<int> *g;
unordered_set<int> path;

ll lca(int a, int b, int p = 0) {
    ll dist = 0;
    if (p) path.insert(a), path.insert(b);
    while (a != b) {
        if (a > b)
            a >>= 1;
        else
            b >>= 1;
        if (p) path.insert(a), path.insert(b);
        dist++;
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    g = new list<int>[m + 1];
    for (int i = 1; i <= m; i++) {
        int t;
        cin >> t;
        while (t--) {
            int p;
            cin >> p;
            g[i].push_back(p);
        }
    }
    ll ans = 0, start = 1;
    while (q--) {
        cin >> food >> person;
        ans += lca(start, person, 1);
        ll diff = LLONG_MAX;
        for (auto &it : g[food]) {
            for (auto &jt : path) {
                diff = min(diff, lca(it, jt));
            }
        }
        path.clear();
        ans += diff * 2;
        start = person;
    }
    cout << ans << endl;
    return 0;
}
