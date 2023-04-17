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
#define MS multiset
#define US unordered_set
#define UMS unordered_multiset
#define PQ priority_queue
#define Graph list<int> *
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

ll maxn = 1e5, ln = 20;
vector<vector<int> > pa(ln, vector<int>(maxn, -1));

typedef struct node {
    vector<node *> child;
    int level;
    int id;
    node() {}
    node(int x) {
        int id = x;
    }
};

void dfs(node *root, int parent, int depth) {
    root->level = depth;
    pa[0][root->id] = parent;
    for (auto &it : root->child) {
        dfs(it, root->id, depth + 1);
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
    for (int i = 1; i < ln; i++) {
        for (int j = 0; j < n; j++) {
            if (pa[i - 1][j] != -1) {
                pa[i][j] = pa[i - 1][pa[i - 1][j]];
            }
        }
    }

    return 0;
}
