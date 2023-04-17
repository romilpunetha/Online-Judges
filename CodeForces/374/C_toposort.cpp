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
int inf = 1e9 + 7;
int n, m, t;
vector<vector<int> > dp(5002, vector<int>(5002, inf)), parent(5002, vector<int>(5002, inf));
queue<int> order, temp;
vector<int> indeg(5002, 0);
list<pair<int, int> > *g;

void topo() {
    for (int i = 1; i <= n; i++)
        if (!indeg[i]) temp.push(i);
    while (!temp.empty()) {
        order.push(temp.front());
        for (auto &it : g[temp.front()]) {
            indeg[it.ff]--;
            if (!indeg[it.ff]) temp.push(it.ff);
        }
        temp.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> t;
    g = new list<pair<int, int> >[n + 1];
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
        indeg[v]++;
    }
    dp[1][1] = 0;
    topo();
    while (!order.empty()) {
        int u = order.front();
        order.pop();
        for (auto &it : g[u]) {
            int v = it.ff, w = it.ss;
            for (int i = 1; i <= n; i++) {
                if (dp[u][i - 1] + w < dp[v][i]) {
                    dp[v][i] = dp[u][i - 1] + w;
                    parent[v][i] = u;
                }
            }
        }
    }
    int i = n + 1, curr = n;
    while (dp[n][i] > t) i--;
    cout << i << endl;
    stack<int> ans;
    ans.push(curr);
    while (curr != 1) {
        curr = parent[curr][i--];
        ans.push(curr);
    }
    while (!ans.empty()) cout << ans.top() << " ", ans.pop();
    return 0;
}
