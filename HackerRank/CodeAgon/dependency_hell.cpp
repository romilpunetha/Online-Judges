#include <bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define pf pop_front
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

list<int> *g, *topo;
vector<int> visited, indegree;
set<int> st;

void dfs(int root) {
    if (visited[root]) return;
    visited[root] = 1;
    int flag = 0;
    for (auto &it : g[root]) {
        topo[it].pb(root);
        indegree[root]++;
        dfs(it);
        flag = 1;
    }
    if (!flag) st.insert(root);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    while (test--) {
        int n, k;
        cin >> n >> k;
        st.clear();
        g = new list<int>[n + 1];
        topo = new list<int>[n + 1];
        indegree.clear();
        visited.clear();
        indegree.resize(n + 1, 0);
        visited.resize(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int p;
            cin >> p;
            while (p--) {
                int u;
                cin >> u;
                g[i].pb(u);
            }
        }
        while (k--) {
            int p;
            cin >> p;
            dfs(p);
        }
        list<int> res;
        while (!st.empty()) {
            int u = *st.begin();
            st.erase(st.begin());
            res.pb(u);
            for (auto &it : topo[u]) {
                indegree[it]--;
                if (!indegree[it]) st.insert(it);
            }
        }
        cout << res.size() << endl;
        for (auto &it : res) cout << it << " ";
        cout << endl;
    }
    return 0;
}
