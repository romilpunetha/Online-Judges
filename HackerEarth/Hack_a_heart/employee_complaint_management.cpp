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

ll maxn = 1e5;
int ln = 20, n;
typedef struct node {
    list<node *> child;
    ll id, val, level, mxid;
    node(int x, int y) {
        id = mxid = x, val = y;
    }
} node;

vector<vector<int> > pa(ln, vector<int>(maxn, -1));
vector<node *> tree;
vector<int> parent;

void dfs(node *root, int parent, int depth, ll val, int mxid) {
    root->level = depth;
    if (root->val < val) {
        root->val = val;
        root->mxid = mxid;
    }
    pa[0][root->id] = parent;
    for (auto &it : root->child) {
        dfs(it, root->id, depth + 1, root->val, root->mxid);
    }
}

ll lca(ll u, ll v) {
    if (tree[u]->level < tree[v]->level) swap(u, v);
    for (int i = ln - 1; i >= 0; i--) {
        if (tree[u]->level - (1 << i) >= tree[v]->level) {
            u = pa[i][u];
        }
    }
    for (int i = ln - 1; i >= 0; i--) {
        if (pa[i][u] != -1 && pa[i][u] != pa[i][v]) {
            u = pa[i][u];
            v = pa[i][v];
        }
    }
    return pa[0][u];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    tree.resize(n);
    parent.resize(n - 1);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        tree[i] = new node(i, t);
    }
    for (auto &it : parent) {
        cin >> it;
        it--;
    }
    for (int i = 0; i < n - 1; i++) {
        (tree[parent[i]]->child).pb(tree[i + 1]);
    }
    dfs(tree[0], -1, 0, 0, -1);
    for (int i = 1; i < ln; i++) {
        for (int j = 0; j < n; j++) {
            if (pa[i - 1][j] != -1) {
                pa[i][j] = pa[i - 1][pa[i - 1][j]];
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << tree[lca(u, v)]->mxid + 1 << endl;
    }
    return 0;
}
